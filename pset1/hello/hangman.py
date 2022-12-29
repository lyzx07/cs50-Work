

word = ['h', 'e', 'l', 'l', 'o']
guess_word = ['', '', '', '', '']

while True:
    letter = input("enter a letter: ")
    if len(letter) > 1:
        continue
    elif (letter >= 'a' and letter <= 'z') or (letter >= 'A' and letter <= 'Z'):
        break
    else:
        continue

if letter in word:
    
    