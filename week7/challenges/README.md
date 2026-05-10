# Challenges

Optional extension problems for students who finish early or want extra practice.  
These are **not graded** — they are for curiosity and growth.

No starter files are provided. Work from scratch.

---

## Challenge 1 — Frequency Filter

**Difficulty:** 🟢 Easy  
**Time:** 15–20 minutes

Write a program `challenge1.py` that:
1. Reads `../week1/favorites.csv`
2. Asks the user: `Minimum votes to display: `
3. Prints only languages that received at least that many votes, sorted by count descending

**Sample run:**
```
Minimum votes to display: 30
Python: 196
C: 40
```

**Concepts:** DictReader, counting, filtering, user input

---

## Challenge 2 — Two-Column Report

**Difficulty:** 🟢 Easy  
**Time:** 20 minutes

Write `challenge2.py` that reads `../week1/favorites.csv` and prints a two-column table:
- Column 1: language
- Column 2: their most common favourite problem

**Sample output:**
```
Language   | Most Common Problem
-----------+--------------------
C          | Mario
Python     | Speller
Scratch    | Starting from Scratch
```

**Hint:** You need a nested dictionary: `{language: {problem: count}}`

---

## Challenge 3 — CSV Writer

**Difficulty:** 🟡 Intermediate  
**Time:** 25–30 minutes

Write `challenge3.py` that:
1. Reads `../week1/favorites.csv`
2. Counts votes per language
3. Writes the results to a NEW file `language_summary.csv` with columns: `language, votes, percentage`
4. Prints: `Saved to language_summary.csv`

Use `csv.writer` or `csv.DictWriter` — look up the docs.

**Sample output file:**
```
language,votes,percentage
Python,196,74.24
C,40,15.15
Scratch,28,10.61
```

---

## Challenge 4 — SQL Explorer

**Difficulty:** 🟡 Intermediate  
**Time:** 30–40 minutes

Set up a `favorites.db` (see week2 instructions).  
Write `challenge4.py` that presents a menu:

```
=== SQL Explorer ===
1. Count by language
2. Count by problem
3. Search by problem name
4. Top 5 problems overall
5. Quit
Choice: 
```

Each menu option runs a different SQL query. Option 3 uses a `?` parameterised query.

---

## Challenge 5 — Data Cleaner

**Difficulty:** 🔴 Hard  
**Time:** 45–60 minutes

Real data is messy. Write `challenge5.py` that:
1. Reads a CSV (you create `messy_data.csv` with intentional issues)
2. Detects and reports: blank rows, duplicate student IDs, out-of-range scores (not 1–5), unknown languages
3. Writes a cleaned version to `cleaned_data.csv`
4. Prints a cleaning report: how many rows were removed/fixed and why

This challenge requires careful thinking about edge cases. There is no single correct solution.
