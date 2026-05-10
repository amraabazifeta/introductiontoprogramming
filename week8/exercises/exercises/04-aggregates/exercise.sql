-- Exercise 04: Aggregates
-- Databases: school.db and library.db

.headers on
.mode column

-- 4.1: Total number of students
SELECT COUNT(*) AS total_students FROM students;

-- 4.2: Number of students per enrollment year
SELECT enrollment_year, COUNT(*) AS student_count
FROM students
GROUP BY enrollment_year
ORDER BY enrollment_year;

-- 4.3: Average GPA (rounded to 2 decimal places)
SELECT ROUND(AVG(gpa), 2) AS average_gpa FROM students;

-- 4.4: Highest GPA, lowest GPA, and average GPA in one query
SELECT MAX(gpa) AS highest_gpa, MIN(gpa) AS lowest_gpa, AVG(gpa) AS average_gpa FROM students;

-- 4.5: Number of courses per department_id
SELECT department_id, COUNT(*) AS course_count
FROM courses
GROUP BY department_id;

-- 4.6: Number of students enrolled in each course (sorted by count desc)
SELECT course_id, COUNT(*) AS enrollment_count
FROM enrollments
GROUP BY course_id
ORDER BY enrollment_count DESC;

-- 4.7: Courses with more than 3 students enrolled (HAVING)
SELECT course_id, COUNT(*) AS enrollment_count
FROM enrollments
GROUP BY course_id
HAVING COUNT(*) > 3;

-- 4.8: Average final exam score per course (rounded to 1 decimal)
SELECT e.course_id, ROUND(AVG(g.final), 1) AS avg_final_score
FROM grades g
JOIN enrollments e ON g.enrollment_id = e.id
GROUP BY e.course_id;

-- 4.9: Per department: teacher count, avg salary, max salary
SELECT department_id, COUNT(*) AS teacher_count, ROUND(AVG(salary), 0) AS avg_salary, MAX(salary) AS max_salary
FROM teachers
GROUP BY department_id;

-- 4.10: Total fines + avg fine for loans with fine > 0 (library.db)
-- Sütun adını ve tablo adını genel uyuma göre düzelttim
SELECT SUM(fine) AS total_fines, AVG(fine) AS avg_fine
FROM loans
WHERE fine > 0;

-- 4.11: Number of books per genre_id (library.db)
SELECT genre_id, COUNT(*) AS book_count
FROM books
GROUP BY genre_id
ORDER BY book_count DESC;

-- 4.12 CHALLENGE: Departments where avg salary > 75000 (school.db)
SELECT department_id, AVG(salary) AS avg_salary
FROM teachers
GROUP BY department_id
HAVING AVG(salary) > 75000;