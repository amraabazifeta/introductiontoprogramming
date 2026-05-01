# Project 3 — Grade Calculator
# Author: Esra Eylul Lofca

scores = []

# collect 5 scores
for i in range(5):
    score = float(input(f"Enter score {i + 1}: "))
    scores.append(score)

# calculate average
average = sum(scores) / len(scores)

# determine grade
if average >= 90:
    grade = "A"
elif average >= 80:
    grade = "B"
elif average >= 70:
    grade = "C"
elif average >= 60:
    grade = "D"
else:
    grade = "F"

# print result
print(f"Average: {average:.1f}")
print(f"Grade: {grade}")
