.headers on
.mode column

-- ============================================================
-- 7.1 Index on students.gpa + EXPLAIN QUERY PLAN
-- ============================================================

CREATE INDEX IF NOT EXISTS idx_students_gpa ON students(gpa);

EXPLAIN QUERY PLAN
SELECT *
FROM students
WHERE gpa > 3.5;

-- ============================================================
-- 7.2 View: enrollment_details (A grades only query later)
-- ============================================================

CREATE VIEW enrollment_details AS
SELECT
    s.first_name || ' ' || s.last_name AS student_name,
    c.title AS course_title,
    g.midterm,
    g.final,
    g.assignments,
    g.letter_grade
FROM enrollments e
JOIN students s ON e.student_id = s.id
JOIN courses c ON e.course_id = c.id
JOIN grades g ON g.enrollment_id = e.id;

-- Query A grades
SELECT *
FROM enrollment_details
WHERE letter_grade = 'A';

-- ============================================================
-- 7.3 View: course_statistics
-- ============================================================

CREATE VIEW course_statistics AS
SELECT
    c.id,
    c.title,
    COUNT(e.student_id) AS student_count,
    ROUND(AVG(g.final), 2) AS avg_final_score
FROM courses c
LEFT JOIN enrollments e ON c.id = e.course_id
LEFT JOIN grades g ON e.id = g.enrollment_id
GROUP BY c.id;

-- ============================================================
-- 7.4 Insert new student
-- ============================================================

INSERT INTO students (first_name, last_name, email, enrollment_year, gpa)
VALUES ('New', 'Student', 'newstudent@school.edu', 2024, NULL);

-- ============================================================
-- 7.5 Update Quinn Moore GPA
-- ============================================================

UPDATE students
SET gpa = 3.22
WHERE id = 17;

-- ============================================================
-- 7.6 DELETE F grades (preview first)
-- ============================================================

-- STEP 1: Preview
SELECT *
FROM grades
WHERE letter_grade = 'F';

-- STEP 2: Delete (uncomment when ready)
-- DELETE FROM grades
-- WHERE letter_grade = 'F';

-- ============================================================
-- 7.7 TRANSACTION: enroll + grade
-- ============================================================

BEGIN TRANSACTION;

INSERT INTO enrollments (student_id, course_id, enrollment_date)
VALUES (1, 13, '2024-09-01');

INSERT INTO grades (enrollment_id, midterm, final, assignments, letter_grade)
VALUES (
    (SELECT id FROM enrollments WHERE student_id = 1 AND course_id = 13),
    85, 90, 88, 'A'
);

COMMIT;

-- ============================================================
-- 7.8 TRANSACTION: library loan + update stock
-- ============================================================

BEGIN TRANSACTION;

UPDATE books
SET available_copies = available_copies - 1
WHERE id = 3;

INSERT INTO loans (member_id, book_id, loan_date, due_date, return_date, fine)
VALUES (1, 3, '2024-05-10', '2024-05-24', NULL, 0);

COMMIT;

-- ============================================================
-- 7.9 EXPLAIN QUERY PLAN comparison
-- ============================================================

-- Version A (no index usage likely)
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE gpa + 0 > 3.5;

-- Version B (index-friendly)
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE gpa > 3.5;

-- Explanation:
-- Version A applies an operation on the column (gpa + 0),
-- so SQLite cannot use the index efficiently.
-- Version B directly uses the indexed column (gpa),
-- so it can perform an index lookup, making it faster.

-- ============================================================
-- 7.10 Compound index
-- ============================================================

CREATE INDEX IF NOT EXISTS idx_enrollments_student_course
ON enrollments(student_id, course_id);
