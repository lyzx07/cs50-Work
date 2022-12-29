import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # get users current cash balance and stocks held by user
    cb = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])[0]["cash"]
    stocks = db.execute(
        "SELECT stock_symbol, share_price , SUM(share_amount) AS shares FROM transactions WHERE id=? GROUP BY stock_symbol", session["user_id"])
    grand_total = float(cb)

    # loop through stocks table and add total share price to grand total
    for i in stocks:
        i['name'] = lookup(i['stock_symbol'])['name']
        i['share_total'] = lookup(i['stock_symbol'])['price']
        i['price'] = lookup(i['stock_symbol'])['price'] * i['shares']
        total = i['price']
        grand_total += total

    return render_template("index.html", cash=usd(cb), stocks=stocks, grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # check if POST was used
    if request.method == "POST":

        # get users current cash balance and look up stock submitted
        current_balance = db.execute('SELECT cash FROM users WHERE id=:id', id=session["user_id"])[0]["cash"]
        cb = float(current_balance)
        stock = lookup(request.form.get("symbol"))

        # check for errors
        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("Must Provide Stock Symbol and/or Amount of Shares", 400)
        elif stock == None:
            return apology("Invalid: Symbol Not Found", 400)

        if request.form.get("shares").isdigit():
            shares = int(float(request.form.get("shares")))
        else:
            return apology("positive integers only", 400)

        # get total price from stock price times shares selected
        price = stock["price"]
        cost = float(price) * shares
        if cost > cb:
            return apology("Not enough funds")

        # insert into transactions table and update users table
        db.execute("INSERT INTO transactions (id, stock_symbol, share_price, share_amount, date_time) VALUES (?, ?, ?, ?, DATETIME('now'))",
                   session["user_id"], stock["symbol"], price, shares)
        db.execute("UPDATE users SET cash=cash-:cost WHERE id=:id", cost=cost, id=session["user_id"])
        return redirect(url_for("index"))
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # show complete history of all purchases and sales in table
    stocks = db.execute(
        "SELECT stock_symbol, share_amount, share_price, date_time FROM transactions WHERE id=? ORDER BY date_time", session["user_id"])

    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # check if method is POST
    if request.method == "POST":

        # error handling
        if request.form.get("symbol") == "":
            return apology("Invalid: Blank", 400)

        # look up submitted stock symbol for quote price
        quote = lookup(request.form.get("symbol"))
        if quote == None:
            return apology("Symbol not found", 400)
        else:
            return render_template("quoted.html", quote=quote)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # get all form information submitted
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username was submitted and that it doesnt already exsist
        if username == "" or len(db.execute('SELECT username FROM users WHERE username = ?', username)) > 0:
            return apology("Invalid Username: Blank or Already Exists", 400)
        elif password == "" or password != confirmation:
            return apology("Invalid Password: Blank or Does Not Match", 400)

        # insert information to the users table
        db.execute('INSERT INTO users (username, hash) VALUES(?, ?)', username, generate_password_hash(password))

        newUser = db.execute("SELECT * FROM users WHERE username = ?", username)

        session["user_id"] = newUser[0]["id"]

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # check to see if method was POST
    if request.method == "POST":

        # get information submitted and select stocks owned by user
        shares = int(request.form.get("shares"))
        symbol = request.form.get("symbol")
        stocks = db.execute(
            "SELECT stock_symbol, SUM(share_amount) AS total_shares FROM transactions WHERE id=? AND stock_symbol=? GROUP BY stock_symbol", session["user_id"], symbol)

        # error handling
        if shares == "" or symbol == "":
            return apology("Invalid: blank shares and/or symbol", 403)
        elif stocks[0]["total_shares"] < shares:
            return apology("do not own enough shares")

        # get users current casg balance and lookup stock submitted and calculate total cost
        current_balance = db.execute('SELECT cash FROM users WHERE id=:id', id=session["user_id"])[0]["cash"]
        cb = float(current_balance)
        stock = lookup(request.form.get("symbol"))
        price = stock["price"]
        cost = float(price) * shares

        # insert into transactions table and update users table
        db.execute("INSERT INTO transactions (id, stock_symbol, share_price, share_amount, date_time) VALUES (?, ?, ?, ?, DATETIME('now'))",
                   session["user_id"], stock["symbol"], price, -shares)
        db.execute("UPDATE users SET cash=cash+:cost WHERE id=:id", cost=cost, id=session["user_id"])

        return redirect(url_for("index"))
    else:
        symbols = db.execute("SELECT stock_symbol FROM transactions WHERE id=? GROUP BY stock_symbol", session["user_id"])

        return render_template("sell.html", symbols=symbols)
