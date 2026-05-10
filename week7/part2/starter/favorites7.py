# favorites7.py
# Task: Print language counts sorted ALPHABETICALLY (A → Z)
#
# Hint: sorted(counts) returns the keys in alphabetical order.
#       The dictionary itself is NOT changed.

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

# TODO: Print counts sorted alphabetically by language name
# Expected output:
#   C: 40
#   Python: 196
#   Scratch: 28
