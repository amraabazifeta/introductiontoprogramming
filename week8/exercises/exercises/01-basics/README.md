# Exercise 01 — SQL Basics

> **Database:** `school.db`
> **Estimated Time:** 20–30 minutes

---

## Background

SQL (Structured Query Language) is how we talk to relational databases. The most fundamental operation is `SELECT` — retrieving data from a table.

```sql
SELECT column1, column2
FROM table_name
WHERE condition;
```

The `WHERE` clause filters which rows are returned. You can compare values using:
- `=` equal
- `<>` or `!=` not equal
- `<`, `>`, `<=`, `>=` comparisons
- `BETWEEN x AND y` within a range
- `AND`, `OR`, `NOT` to combine conditions

---

## Setup

```bash
sqlite3 data/school.db < data/school.sql
sqlite3 data/school.db
```

To see what tables are available:
```sql
.tables
.schema students
```

---

## Exercises

### 1.1 — Hello, Students!
Write a query to retrieve the `first_name` and `last_name` of every student in the database.

**Expected:** 20 rows

---

### 1.2 — Just the Emails
Write a query to get the `email` of every student, ordered alphabetically.

---

### 1.3 — High Achievers
Write a query to find all students with a `gpa` greater than `3.5`. Show their full name and GPA.

**Expected:** 9 rows (including NULL gpa students? Think carefully…)

---

### 1.4 — The Class of 2021
Write a query to find all students who enrolled in the year `2021`.

---

### 1.5 — Middle GPAs
Write a query to find students whose GPA is **between** 3.0 and 3.5 (inclusive).

---

### 1.6 — One Student Only
Write a query to find the student with the email `grace@school.edu`. Display all their information.

---

### 1.7 — Limit Yourself
Write a query to retrieve only the **first 5** students (by `id`).

---

### 1.8 — Who Has No GPA?
Write a query to find any student whose `gpa` is `NULL`.

> 💡 **Hint:** You can't use `= NULL`. What special SQL keyword handles NULL comparisons?

---

### 1.9 — High Salary Teachers
Write a query to find all teachers with a `salary` greater than `80000`. Show their full name and salary.

---

### 1.10 — Courses Worth 4 Credits
Write a query to find all courses worth `4` credits. Show the course `code` and `title`.

---

## Tips

- SQL keywords are conventionally written in UPPERCASE (`SELECT`, `FROM`, `WHERE`)
- Column names and table names are lowercase by convention
- Always end your SQL statements with a `;`
- Use `.mode column` and `.headers on` in SQLite for readable output

---

## Submit

Once complete, copy your queries into `exercise.sql` and run:

```bash
sqlite3 data/school.db < exercises/01-basics/exercise.sql
```
