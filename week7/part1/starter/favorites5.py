# favorites5.py
# Task: Count languages using a single dictionary instead of separate variables.
#
# Why is this better than favorites4?
#   - Works for any number of languages — no hard-coding
#   - Adding a new language to the CSV requires zero code changes
#
# Expected output (order may vary):
#   Python: 196
#   C: 40
#   Scratch: 28

import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {}  # language -> count

    for row in reader:
        favorite = row["language"]
        # TODO: If favorite is already in counts, increment counts[favorite] by 1
        # TODO: Otherwise, set counts[favorite] = 1

    # TODO: Print each key-value pair in counts
    #       Format: "Python: 196"
