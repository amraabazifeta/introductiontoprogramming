#arda_portakal_homework_AIE
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

print(f"Average: {average:.1f}")
print(f"Grade: {grade}")
