# Week 2 — Sorting, SQL, and Real Queries

## Learning Objectives

By the end of this week you will be able to:
- Sort dictionary results alphabetically and by value
- Explain the difference between sorting by key and sorting by value
- Connect Python to an SQLite database using `cs50.SQL`
- Write SQL queries with `SELECT`, `COUNT`, `GROUP BY`, `ORDER BY`, and `WHERE`
- Use parameterised queries (`?`) to safely handle user input

---

## Exercises (complete in order)

| File | Task | Key Concept |
|------|------|-------------|
| `starter/favorites6.py` | Count using `try/except` instead of `if/else` | EAFP pattern |
| `starter/favorites7.py` | Sort results alphabetically | `sorted()` on dictionary keys |
| `starter/favorites8.py` | Sort results by popularity | `sorted()` with `key=counts.get` |
| `starter/favorites9.py` | Count using SQL `GROUP BY` | SQL aggregation |
| `starter/favorites10.py` | Interactive SQL query with user input | `WHERE`, parameterised query |

---

## Setting Up the Database (for favorites9 and favorites10)

You need to import the CSV into a SQLite database first.

```bash
# In your terminal, from the week2/ folder:
sqlite3 favorites.db
.mode csv
.import ../week1/favorites.csv favorites
.quit
```

Then run your Python files as normal.

---

## Key Concepts This Week

### sorted() with key=
```python
# Sort alphabetically (by key):
for lang in sorted(counts):
    print(lang)

# Sort by count, highest first (by value):
for lang in sorted(counts, key=counts.get, reverse=True):
    print(lang)
```

### SQL vs Python — Same Result, Different Approach
| Task | Python (dict) | SQL |
|------|--------------|-----|
| Count by group | `if k in d: d[k]+=1` | `COUNT(*) GROUP BY language` |
| Sort by count | `sorted(d, key=d.get, reverse=True)` | `ORDER BY n DESC` |
| Filter | `if counts[k] > 10` | `WHERE n > 10` |

---

## Common Mistakes This Week

- Calling `counts.get()` with parentheses in `key=counts.get` — the parentheses must be absent
- Forgetting `reverse=True` for descending sort
- Using string formatting (`f"...{user_input}..."`) to build SQL — always use `?` placeholders
- Not calling `conn.commit()` after INSERT/UPDATE operations

---

## Discussion Prompt

Open a GitHub Issue (label: `discuss`):  
*"What can SQL do in one line that would take 10+ lines in Python? Give a concrete example from this week."*
