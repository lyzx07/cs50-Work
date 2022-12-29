from sys import argv
from sys import exit
import csv


# define a function that takes a string and looks for the highest repeated substring od dna strs
def find_highest_str_count(str, dna_str):
    i = 0
    while str*(i + 1) in dna_str:
        i += 1
    return i


# make sure the right amount of arguments were provided at runtime
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# assign easier variable names
filename = argv[1]
seq_file = argv[2]

# read csv file into memory
with open(filename, "r") as datafile:
    reader = csv.reader(datafile, delimiter=',')
    people = []
    for row in reader:
        people.append(row)

# read dna sequence file into memory
with open(seq_file, "r") as sequence_file:
    sequence = sequence_file.read()

str_sequence = people[0]
strs = str_sequence[1:]

# use function to find highest strs and append to a list
highest = []
for key in strs:
    highest.append(find_highest_str_count(key, sequence))

people = people[1:]
# change highest to a list of strings for
highest = [str(i) for i in highest]

# change to strings for easier comparison
str_highest = ' '.join(highest)
str_people = [' '.join(x) for x in people]

# compare highest with csv file to find matching str counts
match = None
for i in range(len(str_people)):
    if str_highest in str_people[i]:
        match = people[i][0]
        print(match)
    else:
        continue

# if no matches were found print no match
if match == None:
    print("No match")