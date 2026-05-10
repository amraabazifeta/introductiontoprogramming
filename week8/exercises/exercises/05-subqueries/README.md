# Exercise 05 — Subqueries

> **Database:** `school.db` and `library.db`
> **Estimated Time:** 35–50 minutes

---

## Background

A **subquery** is a `SELECT` statement nested inside another query. They let you answer questions that require intermediate results.

### Scalar Subquery

Returns a single value, used in `WHERE`:

```sql
-- Find students with above-average GPA
SELECT first_name, gpa
FROM students
WHERE gpa > (SELECT AVG(gpa) FROM students);
```

### IN Subquery

Returns a list of values:

```sql
-- Find students enrolled in CS50 (course_id = 1)
SELECT first_name, last_name
FROM students
WHERE id IN (
    SELECT student_id
    FROM enrollments
    WHERE course_id = 1
);
```

### NOT IN Subquery

```sql
-- Students NOT enrolled in any Computer Science course
SELECT first_name, last_name
FROM students
WHERE id NOT IN (
    SELECT student_id FROM enrollments
    WHERE course_id IN (SELECT id FROM courses WHERE department_id = 1)
);
```

### EXISTS / NOT EXISTS

Returns true if the subquery returns any rows:

```sql
-- Students who have at least one enrollment
SELECT first_name FROM students s
WHERE EXISTS (
    SELECT 1 FROM enrollments WHERE student_id = s.id
);
```

### Subquery in FROM

Treat a subquery as a temporary table:

```sql
SELECT * FROM (
    SELECT student_id, COUNT(*) AS course_count
    FROM enrollments
    GROUP BY student_id
) AS enrollment_counts
WHERE course_count >= 3;
```

---

## Setup

```bash
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql
```

---

## Exercises

### 5.1 — Above Average GPA (school.db)
Find all students whose GPA is above the average GPA of all students.

---

### 5.2 — CS50 Students (school.db)
Find all students enrolled in the course with code `'CS50'`, using a subquery.

> 💡 First write the subquery to find CS50's course_id, then use it.

---

### 5.3 — Students NOT in CS50 (school.db)
Find all students who are **not** enrolled in `'CS50'`.

---

### 5.4 — Highest-Paid Teacher's Courses (school.db)
Find all courses taught by the highest-paid teacher.

> 💡 Use a subquery to find the teacher with `MAX(salary)`.

---

### 5.5 — Students With 3+ Courses (school.db)
Find all students who are enrolled in **3 or more** courses. Use a subquery in the `FROM` clause.

---

### 5.6 — Well-Read Members (library.db)
Find all members who have borrowed **more than 2 books**.

---

### 5.7 — Books Above Average Page Count (library.db)
Find all books with more pages than the average number of pages across all books.

---

### 5.8 — EXISTS: Students With Grades (school.db)
Use `EXISTS` to find all students who have at least one grade recorded.

---

### 5.9 — NOT EXISTS: Courses With No Grades (school.db)
Use `NOT EXISTS` to find courses that have no grades recorded yet.

---

### 5.10 — Challenge: Most Popular Course (school.db)
Using only subqueries (no `LIMIT`), find the course(s) with the **highest** number of enrollments.

> 💡 Hint: Use a subquery to find `MAX(enrollment count)`, then find courses matching that count.

---

## Tips

- Subqueries can be slow on large datasets — often JOINs are more efficient
- `IN (subquery)` can be rewritten as `INNER JOIN` for better performance
- `EXISTS` is often faster than `IN` when checking existence only
- Always test your subquery alone first before nesting it
