# Project 1 — Language Poll Analyser

🟢 **Easy** · 20–25 minutes · Pair work

---

## Problem Description

You are given `favorites.csv` — a survey of student programming language preferences.  
Write a program that reads the file and produces a clean summary report showing:
- How many students chose each language
- Results sorted from most to least popular
- The total number of responses

---

## Input

`favorites.csv` (already in `week1/` — copy or reference it):
```
Timestamp,language,problem
10/20/2025 9:45:26,Python,Readability
10/20/2025 10:08:03,C,Mario
10/20/2025 11:20:23,Python,Filter
10/20/2025 13:37:06,Scratch,Starting from Scratch
...
```

---

## Expected Output

```
=== Language Popularity Report ===
1. Python  : 196 students
2. C       :  40 students
3. Scratch :  28 students

Total responses: 264
```

---

## Concepts Practised

- `csv.DictReader` to read rows as dictionaries
- Counting with a dictionary
- Sorting by value using `sorted()` with `key=counts.get`
- String formatting and alignment with f-strings
- `enumerate()` for rank numbers

---

## Starter Scaffold

See `starter.py` in this folder. Follow the TODO comments in order.

---

## Extension Ideas (for early finishers)

1. Add a percentage next to each count: `Python: 196  (74.2%)`
2. Draw a simple ASCII bar: `Python  ████████████ 196`  
   (Hint: `"█" * (count // 5)` scales the bar)
3. Accept the CSV filename as a command-line argument: `python solution.py favorites.csv`
4. Handle a missing file gracefully with a `try/except FileNotFoundError`
5. Make counting case-insensitive so `"python"` and `"Python"` are treated the same

---

## Common Mistake to Discuss

> The data stores `"Python"` with a capital P. What happens if a student typed `"python"` in the survey?  
> How would you fix your code to handle both? Discuss with your pair before coding the extension.
