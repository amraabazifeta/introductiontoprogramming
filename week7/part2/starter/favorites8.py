# favorites8.py
# Task: Print language counts sorted by POPULARITY (most popular first)
#
# Key idea: sorted() accepts a key= argument.
#   key=counts.get means: "for each key, use counts.get(key) as the sort value"
#   reverse=True means: highest count first
#
# Important: counts.get has NO parentheses — you are passing the method itself,
#            not calling it. sorted() will call it for you.

import csv

with open("../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# TODO: Print counts sorted by value (highest first)
# Expected output:
#   Python: 196
#   C: 40
#   Scratch: 28
