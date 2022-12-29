from cs50 import get_float

# ask for change until we get a poaitive number
while True:
    change_owed = get_float("Change owed: ")
    
    if change_owed >= 0:
        break
    else:
        continue
    
# round floating point value to an int    
change = round(change_owed * 100)
num_coins = 0

# give largest coin value possible 
while change >= 25:
    num_coins += 1
    change -= 25
    
while change >= 10:
    num_coins += 1
    change -= 10
    
while change >= 5:
    num_coins += 1
    change -= 5
    
while change >= 1:
    num_coins += 1
    change -= 1
    
# print total number of coins given as change    
print("", num_coins)
    