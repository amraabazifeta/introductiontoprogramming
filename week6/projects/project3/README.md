# 🟡 Project 3 — Grade Calculator

**Difficulty:** Medium | **Concepts:** for loop · Lists · Conditions · sum()

---

## 📋 Problem

Ask the user to enter **5 subject scores** (0–100). Calculate the average and print the letter grade.

| Average | Grade |
|---|---|
| >= 90 | A |
| >= 80 | B |
| >= 70 | C |
| >= 60 | D |
| < 60  | F |

---

## 📥 Expected Input / Output

```
Enter score 1: 85
Enter score 2: 92
Enter score 3: 78
Enter score 4: 90
Enter score 5: 88
Average: 86.6
Grade: B
```

---

## 💬 Group Discussion Questions

1. How do you collect 5 inputs without writing 5 separate lines? (Hint: loop + list)
2. What does `scores.append(score)` do?
3. What's the difference between `sum(scores) / len(scores)` and writing your own loop?
4. How do you chain multiple conditions using `elif`?

---

## 💻 Starter Code

```python
# Project 3 — Grade Calculator
# Author: your name here

scores = []

for i in range(5):
    score = float(input(f"Enter score {i + 1}: "))
    scores.append(score)

# TODO: calculate the average
# average = ...

# TODO: determine the grade using if/elif/else
# if average >= 90: ...

# TODO: print the result
```

---

## ⭐ Bonus Challenge

- Show the highest and lowest score.
- Allow any number of subjects (ask the user how many before the loop).
