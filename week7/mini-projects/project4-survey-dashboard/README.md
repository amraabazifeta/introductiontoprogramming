# Project 4 — Survey Dashboard

🔴 **Hard** · 60–90 minutes · Group of 4  
*(Best split across two sessions — see timing note below)*

---

## Problem Description

A university has collected satisfaction survey data from students across three faculties.  
The data is split across **three separate CSV files** (one per faculty).

Each file has the same columns:
`student_id, faculty, year, satisfaction, favourite_tool, comments`

Your program must:
1. Read and **merge all three CSV files** into a single SQLite database
2. Run SQL queries to generate a **five-section dashboard**
3. Offer an **interactive query** where the user filters by minimum satisfaction score

---

## Input Files

Three CSV files in this folder:
- `faculty_science.csv`
- `faculty_arts.csv`
- `faculty_business.csv`

Sample rows:
```
student_id,faculty,year,satisfaction,favourite_tool,comments
S001,Science,1,4,Python,Good course structure
S002,Science,2,5,Python,Loved the projects
S003,Science,1,3,R,More examples needed
A001,Arts,2,4,Excel,Clear explanations
B001,Business,3,5,Python,Best course I've taken
```

Satisfaction is rated **1–5** (1 = very dissatisfied, 5 = very satisfied).

---

## Expected Output

```
==============================
  UNIVERSITY SURVEY DASHBOARD
==============================

1. Total Responses by Faculty
   Science  : 15
   Arts     : 12
   Business : 13
   TOTAL    : 40

2. Average Satisfaction by Year of Study
   Year 1 : 3.8 / 5
   Year 2 : 4.1 / 5
   Year 3 : 4.4 / 5
   Year 4 : 4.7 / 5

3. Favourite Tool Popularity
   Python : 22 students
   Excel  :  9 students
   R      :  6 students
   SPSS   :  3 students

4. Faculty Comparison
   Faculty   | Avg Satisfaction | Most Popular Tool
   -----------------------------------------------
   Arts      | 4.2              | Excel
   Business  | 4.5              | Python
   Science   | 4.0              | Python

Enter minimum satisfaction score (1-5): 5
Students with satisfaction >= 5:
  S002 | Science  | Year 2 | Python
  B001 | Business | Year 3 | Python
  ...
```

---

## Concepts Practised

- Reading and merging multiple CSV files with a loop
- Creating an SQLite database table with `sqlite3`
- Inserting CSV rows into a database
- SQL: `COUNT(*)`, `AVG()`, `GROUP BY`, `ORDER BY`, `WHERE`
- Parameterised queries (`?`) — **mandatory for all user input**
- Formatted multi-section terminal output

---

## Starter Scaffold

See `starter.py` in this folder. Split the work as follows:

| Role | Section |
|------|---------|
| 🧑‍💻 Coder A | Step 1–2: CSV reading and database insertion |
| 🧑‍💻 Coder B | Step 3: Dashboard queries 1–3 |
| 🧑‍💻 Coder C | Step 3: Dashboard queries 4–5 (interactive) |
| 🏫 Mentor/Reviewer | Writes PR Teach-Back; tests all edge cases; checks all `?` placeholders |

---

## Session Timing

| Session | Work |
|---------|------|
| Session A (50 min) | Phases 1–3: database setup + queries 1–3 |
| Session B (40 min) | Queries 4–5 + Phase 4 PR and Teach-Back |

---

## Extension Ideas

1. Export each dashboard section to a separate CSV file
2. Add a `DELETE` query that removes all responses below satisfaction score 1 (data cleaning)
3. Find the student who left the most positive comment — add a "Comment of the Day" section
4. Use `argparse` to accept the database filename as a command-line argument
5. Rewrite the CSV-reading step using `pandas` — compare the line count

---

## Security Rule (Enforced at Code Review)

> **Every SQL query that uses user input MUST use `?` placeholders.**  
> Any PR using f-strings or string concatenation to build SQL will be **rejected** at review.

```python
# WRONG — never do this:
db.execute(f"SELECT * FROM responses WHERE satisfaction >= {score}")

# RIGHT — always do this:
db.execute("SELECT * FROM responses WHERE satisfaction >= ?", score)
```
