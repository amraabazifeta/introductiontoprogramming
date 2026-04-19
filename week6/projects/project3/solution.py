scores = []

for i in range(5):
    score = float(input(f"Enter score {i + 1}: "))
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

highest = max(scores)
lowest = min(scores)

print(f"Average: {round(average, 2)}")
print(f"Grade: {grade}")
print(f"Highest score: {highest}")
print(f"Lowest score: {lowest}")
