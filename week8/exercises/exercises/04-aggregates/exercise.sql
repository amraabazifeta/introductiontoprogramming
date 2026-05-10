.headers on
.mode column

-- =========================
-- 4.1 Total number of students
-- =========================
SELECT COUNT(*) AS total_students
FROM students;

-- =========================
-- 4.2 Students per enrollment year
-- =========================
SELECT enrollment_year,
       COUNT(*) AS student_count
FROM students
GROUP BY enrollment_year;

-- =========================
-- 4.3 Average GPA (2 decimals)
-- =========================
SELECT ROUND(AVG(gpa), 2) AS avg_gpa
FROM students;

-- =========================
-- 4.4 GPA stats (max, min, avg)
-- =========================
SELECT
    MAX(gpa) AS max_gpa,
    MIN(gpa) AS min_gpa,
    ROUND(AVG(gpa), 2) AS avg_gpa
FROM students;

-- =========================
-- 4.5 Courses per department
-- =========================
SELECT department_id,
       COUNT(*) AS course_count
FROM courses
GROUP BY department_id;

-- =========================
-- 4.6 Students per course (desc)
-- =========================
SELECT c.title AS course_title,
       COUNT(e.student_id) AS student_count
FROM courses c
LEFT JOIN enrollments e ON c.id = e.course_id
GROUP BY c.id
ORDER BY student_count DESC;

-- =========================
-- 4.7 Courses with > 3 students
-- =========================
SELECT c.title AS course_title,
       COUNT(e.student_id) AS student_count
FROM courses c
JOIN enrollments e ON c.id = e.course_id
GROUP BY c.id
HAVING COUNT(e.student_id) > 3;

-- =========================
-- 4.8 Avg final exam score per course
-- =========================
SELECT c.title AS course_title,
       ROUND(AVG(e.final_exam_score), 1) AS avg_score
FROM courses c
JOIN enrollments e ON c.id = e.course_id
GROUP BY c.id;

-- =========================
-- 4.9 Department stats (teacher count, avg & max salary)
-- =========================
SELECT d.name AS department_name,
       COUNT(t.id) AS teacher_count,
       ROUND(AVG(t.salary), 2) AS avg_salary,
       MAX(t.salary) AS max_salary
FROM departments d
LEFT JOIN teachers t ON d.id = t.department_id
GROUP BY d.id;

-- =========================
-- 4.10 Library: fines > 0
-- =========================
SELECT SUM(fine) AS total_fines,
       ROUND(AVG(fine), 2) AS avg_fine
FROM loans
WHERE fine > 0;

-- =========================
-- 4.11 Books per genre
-- =========================
SELECT genre_id,
       COUNT(*) AS book_count
FROM books
GROUP BY genre_id;

-- =========================
-- 4.12 Departments avg salary > 75000
-- =========================
SELECT d.name AS department_name,
       ROUND(AVG(t.salary), 2) AS avg_salary
FROM departments d
JOIN teachers t ON d.id = t.department_id
GROUP BY d.id
HAVING AVG(t.salary) > 75000;
