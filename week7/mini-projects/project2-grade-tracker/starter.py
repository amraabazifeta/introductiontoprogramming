# starter.py — Grade Tracker
# Project 2 | Easy | 25–30 minutes
#
# Run from this folder: 
#   python starter.py

import csv

# — Step 1: Set up storage variables __________________________
# store scores and grade counts
scores = []              # we'll collect all scores here for the average
grade_counts = {"A": 0, "B": 0, "C": 0, "D": 0, "F": 0}

# We track highest and lowest as dicts so we can store the name too
# track highest and lowest scores
highest = {"name": "", "score": -1}
lowest = {"name": "", "score": 101}    # We started with 101 because the maximum grade is 100. 
# This way, any grade from the list will be lower than 101, helping us find the minimum correctly.

# — Step 2: Read the CSV _____________________________________
# read CSV file
with open("grades.csv", "r") as file:
    reader = csv.DictReader(file)
     # loop through each student
    for row in reader:
        name = row["name"]
        score = int(row["score"])   # Since CSV data is read as strings, we need to convert the score to an integer 
# to perform mathematical comparisons and calculations.

        # TODO: Append score to the scores list
         # collect scores
        scores.append(score)

        # TODO: Update highest if this score is greater than highest["score"]
        # check highest score
        if score > highest["score"]:
            highest["name"] = name
            highest["score"] = score

        # TODO: Update lowest if this score is less than lowest["score"]
         # check lowest score
        if score < lowest["score"]:
            lowest["name"] = name
            lowest["score"] = score

        # TODO: Determine the letter grade using if/elif/else
        #   A = 90–100, B = 80–89, C = 70–79, D = 60–69, F = 0–59
        # assign letter grade
        if score >= 90:
            letter = "A"
        elif score >= 80:
            letter = "B"
        elif score >= 70:
            letter = "C"
        elif score >= 60:
            letter = "D"
        else:
            letter = "F"

        # TODO: Increment grade_counts[letter] by 1
        # count grades
        grade_counts[letter] += 1

# — Step 3: Calculate the average _____________________________
# TODO: average = sum(scores) / len(scores) — round to 1 decimal place
# calculate average
average = round(sum(scores) / len(scores), 1)

# — Step 4: Print the report __________________________________
print("=== Quiz Grade Summary ===")
# TODO: Print all summary lines matching the expected output format
# Hint: use f-strings. For alignment, try f"{label:<20} {value}"
# print summary
print(f"{'Total Students:':<20} {len(scores)}")
print(f"{'Average Score:':<20} {average}")
print(f"{'Highest Score:':<20} {highest['name']} ({highest['score']})")
print(f"{'Lowest Score:':<20} {lowest['name']} ({lowest['score']})")

print("\n--- Grade Distribution ---")
# print grade distribution
for grade in ["A", "B", "C", "D", "F"]:
    print(f"{grade}: {grade_counts[grade]}")

print("\n" + "-" * 30)
