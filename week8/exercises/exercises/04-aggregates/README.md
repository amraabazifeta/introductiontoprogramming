# Exercise 04 — Aggregates

> **Database:** `school.db` and `library.db`
> **Estimated Time:** 30–45 minutes

---

## Background

Aggregate functions collapse multiple rows into a single value. They're used with `GROUP BY` to produce summaries.

### Aggregate Functions

| Function | Description |
|----------|-------------|
| `COUNT(*)` | Count all rows |
| `COUNT(column)` | Count non-NULL values |
| `SUM(column)` | Sum of values |
| `AVG(column)` | Average of values |
| `MIN(column)` | Smallest value |
| `MAX(column)` | Largest value |

### GROUP BY

```sql
-- How many students enrolled each year?
SELECT enrollment_year, COUNT(*) AS count
FROM students
GROUP BY enrollment_year;
```

### HAVING — Filter on Aggregates

`WHERE` filters rows **before** grouping. `HAVING` filters **after** grouping.

```sql
-- Only show years with MORE than 5 students
SELECT enrollment_year, COUNT(*) AS count
FROM students
GROUP BY enrollment_year
HAVING COUNT(*) > 5;
```

### Order of Clauses

```sql
SELECT ...
FROM ...
WHERE ...        -- filter rows first
GROUP BY ...     -- then group
HAVING ...       -- then filter groups
ORDER BY ...     -- then sort
LIMIT ...        -- then limit
```

---

## Setup

```bash
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql
```

---

## Exercises

### 4.1 — Total Students (school.db)
How many students are in the database?

---

### 4.2 — Students per Enrollment Year (school.db)
How many students enrolled in each year? Show the year and count, ordered by year.

---

### 4.3 — Average GPA (school.db)
What is the average GPA of all students? Round to 2 decimal places.

> 💡 Use `ROUND(AVG(gpa), 2)`

---

### 4.4 — Highest and Lowest GPA (school.db)
In a single query, find the highest GPA, lowest GPA, and average GPA.

---

### 4.5 — Courses per Department (school.db)
How many courses does each department offer? Show the department_id and count. Include departments with 0 courses.

---

### 4.6 — Students per Course (school.db)
How many students are enrolled in each course? Show the course_id and enrollment count. Sort by count descending.

---

### 4.7 — Popular Courses Only (school.db)
Which courses have **more than 3 students** enrolled? Show the course_id and enrollment count.

> 💡 Use `HAVING`

---

### 4.8 — Average Grade per Course (school.db)
Calculate the average `final` exam score per course (by course_id). Round to 1 decimal place.

**Tables:** `grades`, `enrollments`

---

### 4.9 — Department Salary Stats (school.db)
For each department, show:
- Department id
- Number of teachers
- Average salary (rounded to 0 decimal places)
- Highest salary

---

### 4.10 — Overdue Fines (library.db)
What is the total fine collected from all loans? What is the average fine per loan that has a fine > 0?

---

### 4.11 — Books per Genre (library.db)
How many books are in each genre? Show the genre_id and count. Sort by count descending.

---

### 4.12 — Challenge: Departments with High Avg Salary (school.db)
Find departments where the average teacher salary exceeds $75,000. Show department_id and the average salary.

---

## Tips

- `COUNT(*)` counts all rows including NULLs; `COUNT(column)` skips NULLs
- You can use aggregate functions in `ORDER BY` without repeating the expression
- Alias aggregates with `AS` to give them readable names
