# starter.py — Grade Tracker
# Project 2 | Easy | 25–30 minutes
#
# Run from this folder:
#   python starter.py

import csv

# ── Step 1: Set up storage variables ─────────────────────────────────────────
scores = []          # we'll collect all scores here for the average
grade_counts = {"A": 0, "B": 0, "C": 0, "D": 0, "F": 0}

# We track highest and lowest as dicts so we can store the name too
highest = {"name": "", "score": -1}
lowest  = {"name": "", "score": 101}   # Why 101? Discuss with your pair.

# ── Step 2: Read the CSV ──────────────────────────────────────────────────────
with open("grades.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name  = row["name"]
        score = int(row["score"])   # IMPORTANT: CSV values are strings — must convert

        # TODO: Append score to the scores list

        # TODO: Update highest if this score is greater than highest["score"]

        # TODO: Update lowest if this score is less than lowest["score"]

        # TODO: Determine the letter grade using if/elif/else
        #   A = 90-100, B = 80-89, C = 70-79, D = 60-69, F = 0-59
        # TODO: Increment grade_counts[letter] by 1

# ── Step 3: Calculate the average ────────────────────────────────────────────
# TODO: average = sum(scores) / len(scores)  — round to 1 decimal place
average = ???

# ── Step 4: Print the report ──────────────────────────────────────────────────
print("=== Quiz Grade Summary ===")
# TODO: Print all summary lines matching the expected output format
# Hint: use f-strings. For alignment, try f"{label:<20} {value}"
