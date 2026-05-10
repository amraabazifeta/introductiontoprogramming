# Exercise 07 — Advanced SQL

> **Database:** `school.db` and `library.db`
> **Estimated Time:** 40–60 minutes

---

## Background

Now that you can query and design databases, it's time to learn professional techniques: speeding up queries with indexes, creating reusable views, and ensuring data integrity with transactions.

---

### CREATE INDEX — Speeding Up Queries

Without an index, SQLite scans every row to find matches (full table scan). Indexes create a sorted structure that makes lookups much faster.

```sql
-- Create an index on a column you frequently filter by
CREATE INDEX idx_students_gpa ON students(gpa);

-- Create a compound index for multi-column queries
CREATE INDEX idx_enrollments_student ON enrollments(student_id, course_id);

-- See the query plan (does it use an index?)
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE gpa > 3.5;
```

> ⚠️ Indexes speed up reads but slow down writes. Don't index every column!

---

### CREATE VIEW — Reusable Queries

A view is a saved query that behaves like a virtual table.

```sql
-- Create a view
CREATE VIEW high_gpa_students AS
SELECT first_name, last_name, gpa
FROM students
WHERE gpa > 3.5;

-- Use it like a table
SELECT * FROM high_gpa_students ORDER BY gpa DESC;

-- Drop it
DROP VIEW high_gpa_students;
```

---

### Transactions — All or Nothing

Transactions ensure multiple related operations either all succeed or all fail.

```sql
BEGIN TRANSACTION;

UPDATE books SET available_copies = available_copies - 1 WHERE id = 3;
INSERT INTO loans (member_id, book_id, loan_date, due_date)
VALUES (1, 3, '2024-04-01', '2024-04-15');

COMMIT;  -- save changes
-- or
ROLLBACK;  -- undo all changes since BEGIN
```

---

### INSERT, UPDATE, DELETE

```sql
-- Add a new row
INSERT INTO students (first_name, last_name, email, enrollment_year)
VALUES ('New', 'Student', 'new@school.edu', 2024);

-- Modify existing rows
UPDATE students SET gpa = 3.9 WHERE email = 'alice@school.edu';

-- Remove rows
DELETE FROM students WHERE enrollment_year < 2018;
```

---

## Exercises

### 7.1 — Create an Index (school.db)
Create an index on the `students` table for the `gpa` column. Then use `EXPLAIN QUERY PLAN` to verify it's being used in a query that filters by GPA.

---

### 7.2 — Create a View: Active Enrollments (school.db)
Create a view called `enrollment_details` that joins `enrollments`, `students`, `courses`, and `grades` to show:
- Student full name
- Course code and title
- Letter grade

Then query your view to find all 'A' grades.

---

### 7.3 — Create a View: Course Stats (school.db)
Create a view called `course_statistics` that shows, for each course:
- Course code and title
- Number of enrolled students
- Average final exam score

---

### 7.4 — Insert New Data (school.db)
Insert a new student into the `students` table:
- Name: Your choice
- Email: `newstudent@school.edu`
- Enrollment year: 2024
- GPA: NULL (they just started)

Then verify your insertion with a SELECT.

---

### 7.5 — Update Data (school.db)
Update student with id `17` (Quinn Moore) — their GPA was entered as NULL because of a data entry error. Set their GPA to `3.22`.

---

### 7.6 — Safe Delete (school.db)
You want to remove all grades for students who got an 'F'. Write a `DELETE` statement to do this safely.

> ⚠️ Before deleting, write a `SELECT` to preview what would be deleted!

---

### 7.7 — Transaction: Enroll a Student (school.db)
Write a transaction that:
1. Inserts a new enrollment for student id 1 in course id 13
2. Inserts an initial grade record (all NULL) for that enrollment

If either step fails, both should be rolled back.

---

### 7.8 — Transaction: Library Loan (library.db)
Write a transaction to process a new loan:
1. Decrease `available_copies` by 1 for book id 3
2. Insert a new loan record for member 3, book 3

Make sure the book has available copies before proceeding — add a check!

---

### 7.9 — EXPLAIN Query Plan (school.db)
Run `EXPLAIN QUERY PLAN` on these two versions of the same query and compare:

**Version A (slow):**
```sql
SELECT * FROM students WHERE LOWER(email) = 'alice@school.edu';
```

**Version B (fast, using index):**
```sql
SELECT * FROM students WHERE email = 'alice@school.edu';
```

Why is version A slower even with an index? Write your explanation in a comment.

---

### 7.10 — Challenge: Compound Index (school.db)
The following query runs frequently in your application:

```sql
SELECT * FROM enrollments WHERE student_id = 5 AND course_id = 1;
```

Create the optimal index for this query. Then verify with `EXPLAIN QUERY PLAN`.

---

## Best Practices Summary

| Situation | What to do |
|-----------|-----------|
| Frequently filtered column | `CREATE INDEX` |
| Complex join you reuse | `CREATE VIEW` |
| Multiple related inserts/updates | `BEGIN TRANSACTION` |
| Test data changes safely | `BEGIN` → check → `ROLLBACK` or `COMMIT` |
| Delete risky data | `SELECT` first, then `DELETE` |
