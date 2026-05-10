-- Exercise 07: Advanced SQL
-- Databases: school.db and library.db

.headers on
.mode column

-- 7.1: Create an index on students.gpa, then EXPLAIN QUERY PLAN
<<<<<<< HEAD
CREATE INDEX idx_students_gpa ON students(gpa);

EXPLAIN QUERY PLAN
SELECT * FROM students WHERE gpa > 3.5;

-- 7.2: Create view 'enrollment_details', then query for 'A' grades
CREATE VIEW enrollment_details AS
SELECT 
    s.first_name || ' ' || s.last_name AS student_full_name,
    c.code,
    c.title,
    g.letter_grade
FROM enrollments e
JOIN students s ON e.student_id = s.id
JOIN courses c ON e.course_id = c.id
JOIN grades g ON e.id = g.enrollment_id;

SELECT * FROM enrollment_details WHERE letter_grade = 'A';

-- 7.3: Create view 'course_statistics' with count and avg final score
CREATE VIEW course_statistics AS
SELECT 
    c.code,
    c.title,
    COUNT(e.id) AS student_count,
    ROUND(AVG(g.final), 1) AS avg_final_score
FROM courses c
LEFT JOIN enrollments e ON c.id = e.course_id
LEFT JOIN grades g ON e.id = g.enrollment_id
GROUP BY c.id;

SELECT * FROM course_statistics;

-- 7.4: Insert a new student (newstudent@school.edu, 2024, NULL gpa)
INSERT INTO students (first_name, last_name, email, enrollment_year, gpa)
VALUES ('Arda', 'Skopje', 'newstudent@school.edu', 2024, NULL);

SELECT * FROM students WHERE email = 'newstudent@school.edu';

-- 7.5: Update student id=17 (Quinn Moore) to set gpa = 3.22
UPDATE students 
SET gpa = 3.22 
WHERE id = 17;

SELECT * FROM students WHERE id = 17;

-- 7.6: Preview and then DELETE all grades with letter_grade = 'F'
-- Step 1: SELECT to preview (run this first!)
SELECT * FROM grades WHERE letter_grade = 'F';

-- Step 2: DELETE (uncomment when ready)
DELETE FROM grades WHERE letter_grade = 'F';

-- 7.7: Transaction to enroll student 1 in course 13 + add grade record
BEGIN TRANSACTION;
INSERT INTO enrollments (student_id, course_id) VALUES (1, 13);
INSERT INTO grades (enrollment_id, midterm, final, letter_grade) 
VALUES (last_insert_rowid(), NULL, NULL, NULL);
COMMIT;

-- 7.8: Transaction: decrease available_copies for book 3, insert loan (library.db)
BEGIN TRANSACTION;
UPDATE books SET available_copies = available_copies - 1 
WHERE id = 3 AND available_copies > 0;
INSERT INTO loans (member_id, book_id, loan_date, due_date)
VALUES (3, 3, DATE('now'), DATE('now', '+14 days'));
COMMIT;
=======



-- 7.2: Create view 'enrollment_details', then query for 'A' grades



-- 7.3: Create view 'course_statistics' with count and avg final score



-- 7.4: Insert a new student (newstudent@school.edu, 2024, NULL gpa)



-- 7.5: Update student id=17 (Quinn Moore) to set gpa = 3.22



-- 7.6: Preview and then DELETE all grades with letter_grade = 'F'
-- Step 1: SELECT to preview (run this first!)

-- Step 2: DELETE (uncomment when ready)



-- 7.7: Transaction to enroll student 1 in course 13 + add grade record



-- 7.8: Transaction: decrease available_copies for book 3, insert loan (library.db)


>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

-- 7.9: EXPLAIN QUERY PLAN comparison
-- Run both and compare the output:

-- Version A (may not use index well):
<<<<<<< HEAD
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE LOWER(email) = 'alice@school.edu';

-- Version B (index-friendly):
EXPLAIN QUERY PLAN
SELECT * FROM students WHERE email = 'alice@school.edu';

-- Your explanation of the difference (as a comment):
-- Version A is slower because the LOWER() function prevents SQLite from using 
-- the index on the email column directly. It must perform a Full Table Scan. 
-- Version B uses the index for a fast lookup.

-- 7.10 CHALLENGE: Create compound index for enrollments(student_id, course_id)
CREATE INDEX idx_enrollments_student_course ON enrollments(student_id, course_id);

EXPLAIN QUERY PLAN
SELECT * FROM enrollments WHERE student_id = 5 AND course_id = 1;
=======

-- Version B (index-friendly):

-- Your explanation of the difference (as a comment):
-- ...



-- 7.10 CHALLENGE: Create compound index for enrollments(student_id, course_id)


>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
