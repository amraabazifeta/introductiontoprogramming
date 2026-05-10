# starter.py — Grade Tracker

import csv

# Step 1: Set up storage variables
scores = []
grade_counts = {"A": 0, "B": 0, "C": 0, "D": 0, "F": 0}

highest = {"name": "", "score": -1}
lowest  = {"name": "", "score": 101}

# Step 2: Read the CSV
with open("grades.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name  = row["name"]
        score = int(row["score"])

        # Append score
        scores.append(score)

        # Update highest
        if score > highest["score"]:
            highest["name"] = name
            highest["score"] = score

        # Update lowest
        if score < lowest["score"]:
            lowest["name"] = name
            lowest["score"] = score

        # Determine letter grade
        if score >= 90:
            grade = "A"
        elif score >= 80:
            grade = "B"
        elif score >= 70:
            grade = "C"
        elif score >= 60:
            grade = "D"
        else:
            grade = "F"

        # Increment grade count
        grade_counts[grade] += 1

# Step 3: Calculate average
average = round(sum(scores) / len(scores), 1)

# Step 4: Print report
print("=== Quiz Grade Summary ===")

print(f"{'Average score:':<20} {average}")
print(f"{'Highest score:':<20} {highest['name']} ({highest['score']})")
print(f"{'Lowest score:':<20} {lowest['name']} ({lowest['score']})")

print("\nGrade distribution:")
for grade in ["A", "B", "C", "D", "F"]:
    print(f"{grade}: {grade_counts[grade]}")
