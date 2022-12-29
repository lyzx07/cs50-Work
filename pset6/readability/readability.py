from cs50 import get_string

text = get_string("Text: ")

# create counter variables for letters, words, and sentences
letter_count = 0
word_count = 0
sentence_count = 0

# iterate though text to count each letter
for i in text:
    if i.isalpha():
        letter_count += 1

# iterate through text to count words
for i in text:
    if i == " ":
        word_count += 1
word_count += 1

# iterate through text to count sentences
for i in text:
    if i == "." or i == "!" or i == "?":
        sentence_count += 1

# find letters per 100 words and sentences per 100 words
letters = (letter_count * 100) / word_count
sentences = (sentence_count * 100) / word_count

# use the Coleman-Liau formula to calculate grade of text given
score = 0.0588 * letters - 0.296 * sentences - 15.8

grade = round(score)

# print grade 16+ if score is 16 or over
if grade >= 16:
    print("Grade 16+")
# print before grade one if grade is less that 1
elif grade < 1:
    print("Before Grade 1")
# else print grade calculated
else:
    print("Grade: ", grade)
