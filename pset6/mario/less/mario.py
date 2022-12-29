from cs50 import get_int

# get pyramid height from user
while True:
    height = get_int("Height of pyramid? ")
    # keep asking until valid input is accepted
    if height >= 1 and height <= 8:
        break
    else:
        continue
    

for i in range(0, height):
    # print spaces for flipped pyramid
    for j in range(1, height - i):
        print(end=" ")
        
    # print hashes for each row
    for hashes in range(0, i + 1):
        print("#", end="")

    # print new line after pyramid is printed
    print("")

