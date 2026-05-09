# Project 3 — Grade Calculator
# Author: Erinda

# Bonus: ask how many subjects
num = int(input("How many subjects? "))

scores = []
for i in range(1, num + 1):
    score = float(input(f"Enter score {i}: "))
    scores.append(score)

average = sum(scores) / len(scores)

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

print(f"Average: {average:.1f}")
print(f"Grade: {grade}")

# Bonus: highest and lowest
print(f"Highest score: {max(scores)}")
print(f"Lowest score: {min(scores)}")