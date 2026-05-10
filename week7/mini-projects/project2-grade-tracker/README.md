# Project 2 — Grade Tracker

🟢 **Easy** · 25–30 minutes · Pair work

---

## Problem Description

A lecturer has exported quiz results to a CSV file. Each row has a student name and their score (0–100).  
Write a program that reads the file and produces a grade summary:
- Total students assessed
- Average score (rounded to 1 decimal place)
- Highest score (with the student's name)
- Lowest score (with the student's name)
- Count of students in each letter grade band

---

## Input

`grades.csv` (already in this folder):
```
name,score
Alice,88
Bob,73
Carol,92
David,55
Emine,41
Fatih,67
Grace,91
Hassan,78
Irem,84
Jorge,60
```

---

## Expected Output

```
=== Quiz Grade Summary ===
Students assessed : 10
Average score     : 72.9
Highest score     : 92  (Carol)
Lowest score      : 41  (Emine)

Grade Distribution:
  A (90-100) : 2 students
  B (80-89)  : 2 students
  C (70-79)  : 2 students
  D (60-69)  : 2 students
  F ( 0-59)  : 2 students
```

---

## Concepts Practised

- Reading numeric data from CSV (`int()` conversion — CSV values are always strings)
- Tracking min and max values with variables
- Computing an average from a list
- `if/elif/else` for grade banding
- Counting with a dictionary
- Formatted output with aligned columns

---

## Starter Scaffold

See `starter.py` in this folder. Follow the TODO comments in order.

---

## Extension Ideas

1. Write the results to a new file `results.csv` with columns: `name, score, grade`
2. Draw a terminal histogram — one `#` per student in each grade band
3. Accept a pass threshold from the user: `Enter pass mark: 60` → show pass/fail count
4. Handle rows where the score cell is blank or contains non-numeric data

---

## Pair Discussion Questions

- Why do we initialise `lowest_score` to `101` instead of `0`?
- What would happen if the CSV had only one student?
- What would `sum(scores) / len(scores)` crash on if the file was empty?
