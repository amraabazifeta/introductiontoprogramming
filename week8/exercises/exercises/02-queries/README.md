# Exercise 02 — Querying Data

> **Database:** `school.db` and `library.db`
> **Estimated Time:** 25–35 minutes

---

## Background

Beyond basic filtering, SQL offers powerful tools for searching patterns, sorting, and deduplication.

### LIKE — Pattern Matching

```sql
-- Names starting with 'A'
SELECT name FROM students WHERE name LIKE 'A%';

-- Names containing 'son'
SELECT name FROM students WHERE name LIKE '%son%';

-- Names with exactly 4 characters
SELECT name FROM students WHERE name LIKE '____';
```

`%` matches any sequence of characters. `_` matches exactly one character.

### ORDER BY — Sorting

```sql
SELECT name, gpa FROM students ORDER BY gpa DESC;  -- highest first
SELECT name, gpa FROM students ORDER BY gpa ASC;   -- lowest first (default)
SELECT * FROM students ORDER BY last_name, first_name;  -- multi-column sort
```

### DISTINCT — Remove Duplicates

```sql
SELECT DISTINCT enrollment_year FROM students;
```

### IN — Match a List

```sql
SELECT * FROM students WHERE enrollment_year IN (2019, 2021);
```

---

## Setup

```bash
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql
```

---

## Exercises

### 2.1 — Search by Name (school.db)
Find all students whose **last name** contains the letter "s" (case-insensitive).

> 💡 SQLite's `LIKE` is case-insensitive for ASCII characters by default.

---

### 2.2 — Email Domain Search (school.db)
Find all teachers whose email ends in `@cs50.harvard.edu`.

---

### 2.3 — Top 5 GPAs (school.db)
List the top 5 students by GPA (highest first). Show their full name and GPA.

---

### 2.4 — Distinct Enrollment Years (school.db)
List all unique enrollment years in the students table (no duplicates).

---

### 2.5 — Multiple Departments (school.db)
Find all courses that belong to department `1` OR department `2`. Use the `IN` keyword.

---

### 2.6 — Students NOT from 2018 (school.db)
Find all students who did **not** enroll in 2018. Use `NOT IN`.

---

### 2.7 — Sort Courses by Credits then Title (school.db)
List all courses sorted by number of credits (descending), then alphabetically by title within the same credit count.

---

### 2.8 — Find Books by Title Pattern (library.db)
Find all books whose title starts with "The".

---

### 2.9 — Non-Returned Loans (library.db)
Find all loans where the `return_date` is `NULL` (books not yet returned). Show the loan id, member_id, and due_date.

---

### 2.10 — British Authors (library.db)
Find all authors who are British. Sort by last name.

---

### 2.11 — Premium and Student Members (library.db)
Find all library members with membership type `premium` or `student`. Use `IN`.

---

### 2.12 — Challenge: 4-Letter First Names (school.db)
Find all students whose first name is exactly 4 characters long. Use the `_` wildcard.

---

## Tips

- `LIKE` patterns: `%` = any characters, `_` = exactly one character
- `IS NULL` and `IS NOT NULL` for NULL checks (not `= NULL`)
- You can `ORDER BY` a column you didn't `SELECT`
