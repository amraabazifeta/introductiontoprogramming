# Exercise 03 — Joins

> **Database:** `school.db` and `library.db`
> **Estimated Time:** 35–50 minutes

---

## Background

Joins let you combine rows from two or more tables based on a related column. This is the heart of relational databases.

### Types of Joins

```
Table A        Table B
┌───┐          ┌───┐
│ 1 │──────────│ 1 │  ← matched
│ 2 │──────────│ 2 │  ← matched
│ 3 │          │   │  ← A only
│   │          │ 4 │  ← B only
└───┘          └───┘
```

| Join Type | Returns |
|-----------|---------|
| `INNER JOIN` | Only rows that match in BOTH tables |
| `LEFT JOIN` | All rows from left table + matching right rows (NULL if no match) |
| `RIGHT JOIN` | All rows from right table (SQLite: use LEFT JOIN instead) |
| `CROSS JOIN` | Every combination of rows (Cartesian product) |

### Syntax

```sql
-- INNER JOIN
SELECT students.first_name, courses.title
FROM enrollments
INNER JOIN students ON enrollments.student_id = students.id
INNER JOIN courses ON enrollments.course_id = courses.id;

-- With aliases (cleaner!)
SELECT s.first_name, c.title
FROM enrollments e
INNER JOIN students s ON e.student_id = s.id
INNER JOIN courses c ON e.course_id = c.id;

-- LEFT JOIN (keeps all left rows)
SELECT s.first_name, e.course_id
FROM students s
LEFT JOIN enrollments e ON s.id = e.student_id;
```

---

## Setup

```bash
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql
```

---

## Exercises

### 3.1 — Student + Course Names (school.db)
Write a query to list every enrollment with the **student's full name** and the **course title** (not just IDs).

**Tables needed:** `enrollments`, `students`, `courses`

---

### 3.2 — Who Teaches What? (school.db)
List every course with the **teacher's full name** who teaches it.

**Tables needed:** `courses`, `teachers`

---

### 3.3 — Department + Teacher (school.db)
List all teachers along with their **department name** (not department_id).

**Tables needed:** `teachers`, `departments`

---

### 3.4 — Full Enrollment Details (school.db)
Write a query showing: student full name, course title, teacher full name, and the student's `letter_grade` for that course.

**Tables needed:** `students`, `enrollments`, `grades`, `courses`, `teachers`

---

### 3.5 — Students Who Haven't Enrolled (school.db)
Use a `LEFT JOIN` to find any students who have **no enrollments** at all.

> 💡 **Hint:** After a LEFT JOIN, rows with no match will have `NULL` in the joined table's columns.

---

### 3.6 — Courses with No Students (school.db)
Find all courses that have **no enrollments** using a `LEFT JOIN`.

---

### 3.7 — Book + Author Names (library.db)
List all books along with their author's full name.

**Tables needed:** `books`, `book_authors`, `authors`

---

### 3.8 — Genre + Book Count (library.db)
List every genre along with the books in that genre. Include genres that have no books.

> 💡 Use a `LEFT JOIN` to keep genres with zero books.

---

### 3.9 — Member Loan History (library.db)
Show every member's full name alongside every book they've borrowed (title). Include members who have never borrowed a book.

---

### 3.10 — Challenge: Multi-Join (library.db)
List all loans with:
- Member's full name
- Book title
- Loan date
- Return date (or "Not returned" if NULL)

> 💡 Use `COALESCE(column, 'fallback')` to replace NULL with a string.

---

## Common Mistakes

- Forgetting the `ON` condition → creates a massive Cartesian product
- Using `WHERE` instead of `ON` for join conditions (they behave differently with LEFT JOINs!)
- Not using table aliases when the same column name appears in multiple tables

---

## Visualizing Joins

```
INNER JOIN          LEFT JOIN
   A ∩ B              A ∪ (A ∩ B)
  ┌───┐               ┌───┐
  │ ■ │               ■ ■ │
  └───┘               └───┘
```
