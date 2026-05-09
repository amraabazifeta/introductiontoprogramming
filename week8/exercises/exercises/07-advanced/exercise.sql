-- Exercise 07: Advanced SQL
.headers on
.mode column

-- 7.1: Create an index on students.gpa, then EXPLAIN QUERY PLAN
CREATE INDEX IF NOT EXISTS idx_students_gpa ON students(gpa);

EXPLAIN QUERY PLAN
SELECT * FROM students WHERE gpa > 3.5;

-- 7.2: Create view 'enrollment_details', then query for 'A' grades
DROP VIEW IF EXISTS enrollment_details;

CREATE VIEW enrollment_details AS
SELECT s.first_name || ' ' || s.last_name AS student_name,
       c.code AS course_code,
       c.title AS course_title,
       g.letter_grade
FROM enrollments e
INNER JOIN students s ON e.student_id = s.id
INNER JOIN courses c ON e.course_id = c.id
INNER JOIN grades g ON g.enrollment_id = e.id;

SELECT * FROM enrollment_details WHERE letter_grade = 'A';

-- 7.3: Create view 'course_statistics' with count and avg final score
DROP VIEW IF EXISTS course_statistics;

CREATE VIEW course_statistics AS
SELECT c.code,
       c.title,
       COUNT(e.id) AS enrolled_students,
       ROUND(AVG(g.final), 1) AS avg_final_score
FROM courses c
LEFT JOIN enrollments e ON c.id = e.course_id
LEFT JOIN grades g ON g.enrollment_id = e.id
GROUP BY c.id;

SELECT * FROM course_statistics;

-- 7.4: Insert a new student (newstudent@school.edu, 2024, NULL gpa)
INSERT INTO students (first_name, last_name, email, enrollment_year, gpa)
VALUES ('New', 'Student', 'newstudent@school.edu', 2024, NULL);

SELECT * FROM students WHERE email = 'newstudent@school.edu';

-- 7.5: Update student id=17 (Quinn Moore) to set gpa = 3.22
UPDATE students SET gpa = 3.22 WHERE id = 17;

SELECT first_name, last_name, gpa FROM students WHERE id = 17;

-- 7.6: Preview and then DELETE all grades with letter_grade = 'F'
-- Step 1: SELECT to preview
SELECT * FROM grades WHERE letter_grade = 'F';

-- Step 2: DELETE
DELETE FROM grades WHERE letter_grade = 'F';

-- Verify deletion
SELECT * FROM grades WHERE letter_grade = 'F';

-- 7.7: Transaction to enroll student 1 in course 13 + add grade record
BEGIN TRANSACTION;

INSERT INTO enrollments (student_id, course_id, enrollment_date)
VALUES (1, 13, DATE('now'));

INSERT INTO grades (enrollment_id, midterm, final, assignments, letter_grade)
VALUES (last_insert_rowid(), NULL, NULL, NULL, NULL);

COMMIT;

-- Verify
SELECT e.id, s.first_name, c.title
FROM enrollments e
INNER JOIN students s ON e.student_id = s.id
INNER JOIN courses c ON e.course_id = c.id
WHERE e.student_id = 1 AND e.course_id = 13;

-- 7.8: Transaction: decrease available_copies for book 3, insert loan (library.db)
-- Run this against library.db
BEGIN TRANSACTION;

UPDATE books SET available_copies = available_copies - 1
WHERE id = 3 AND available_copies > 0;

INSERT INTO loans (member_id, book_id, loan_date, due_date)
VALUES (3, 3, DATE('now'), DATE('now', '+14 days'));

COMMIT;

-- Verify
SELECT id, title, available_copies FROM books WHERE id = 3;

-- 7.9: EXPLAIN QUERY PLAN comparison
-- Version A (may not use index well):
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE LOWER(email) = 'alice@school.edu';

-- Version B (index-friendly):
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE email = 'alice@school.edu';

-- Explanation:
-- Version A is slower because LOWER() wraps the email column in a function.
-- SQLite cannot use an index on the raw column when a function is applied to it
-- so it falls back to a full table scan checking every row.
-- Version B queries the column directly so SQLite can use the index
-- and jump straight to the matching row without scanning the whole table.

-- 7.10 CHALLENGE: Create compound index for enrollments(student_id, course_id)
CREATE INDEX IF NOT EXISTS idx_enrollments_student_course
ON enrollments(student_id, course_id);

EXPLAIN QUERY PLAN
SELECT * FROM enrollments WHERE student_id = 5 AND course_id = 1;