# Project 3 — Grade Calculator
# Author: Arda Ok

scores = []

# TODO: use a for loop to collect 5 scores and append each to the list
for i in range(5):
    score = float(input(f"Enter score {i + 1}: "))
    scores.append(score)

# TODO: calculate the average using sum() and len()
average = sum(scores) / len(scores)

# TODO: determine the grade with if/elif/else (A/B/C/D/F)
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

# TODO: print the average (1 decimal place) and the grade
#   Hint: f"{average:.1f}" formats to 1 decimal place
print(f"Average: {average:.1f}")
print(f"Grade: {grade}")