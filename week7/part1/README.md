# Week 1 — Reading CSV Files with Python

## Learning Objectives

By the end of this week you will be able to:
- Open and read a CSV file using `csv.reader` and `csv.DictReader`
- Explain the difference between accessing data by index vs. by column name
- Skip a header row correctly
- Count occurrences using a dictionary
- Write meaningful commit messages and a PR Teach-Back

---

## The Dataset

All exercises this week use `favorites.csv` — a real survey of student programming language preferences.

```
Timestamp,language,problem
10/20/2025 9:45:26,Python,Readability
10/20/2025 10:08:03,C,Mario
...
```

**Columns:**
- `Timestamp` — when the student submitted the survey
- `language` — their favourite programming language (Python, C, or Scratch)
- `problem` — their favourite CS50 problem

---

## Exercises (complete in order)

| File | Task | Key Concept |
|------|------|-------------|
| `starter/favorites0.py` | Print all languages using `csv.reader` | reader, index access, `next()` |
| `starter/favorites1.py` | Store the value in a named variable | code readability |
| `starter/favorites2.py` | Switch to `csv.DictReader` | named key access |
| `starter/favorites3.py` | Simplify DictReader usage | DictReader auto-skips header |
| `starter/favorites4.py` | Count languages using variables | conditionals, counters |
| `starter/favorites5.py` | Count using a dictionary | dynamic counting, `in` operator |

---

## How to Submit

1. Complete each file in `starter/`
2. Commit after each file: `feat(week1): complete favorites0 — csv.reader`
3. When all six files are done, push and open a PR: `yourname/week1` → `group/your-team`
4. Fill in the entire PR template including the Teach-Back section

---

## Common Mistakes This Week

- Forgetting `next(reader)` when using `csv.reader` — the header row becomes data row 1
- Using `row[1]` when `row["language"]` is clearer and safer
- Trying to call `next()` on a `DictReader` — it skips the header automatically
- Comparing `row["language"] == "python"` (lowercase) when the data stores `"Python"` (capitalised)

---

## Discussion Prompt

Open a GitHub Issue (label: `discuss`) and answer:  
*"When would you choose `csv.reader` over `csv.DictReader`? Give a real-world example of each."*
