-- Exercise 01: SQL Basics
-- Database: school.db
-- Instructions: Write your SQL queries below each comment.
-- Run with: sqlite3 data/school.db < exercises/01-basics/exercise.sql

.headers on
.mode column
.separator "  "

-- 1.1: Retrieve first_name and last_name of every student
<<<<<<< HEAD
SELECT first_name, last_name FROM students;

-- 1.2: Get the email of every student, ordered alphabetically
SELECT email FROM students ORDER BY email ASC;

-- 1.3: Find all students with a GPA greater than 3.5 (show name and GPA)
SELECT first_name, last_name, gpa FROM students WHERE gpa > 3.5;

-- 1.4: Find all students who enrolled in 2021
SELECT * FROM students WHERE enrollment_year = 2021;

-- 1.5: Find students with GPA between 3.0 and 3.5 (inclusive)
SELECT * FROM students WHERE gpa BETWEEN 3.0 AND 3.5;

-- 1.6: Find the student with email 'grace@school.edu'
SELECT * FROM students WHERE email = 'grace@school.edu';

-- 1.7: Retrieve only the first 5 students (by id)
SELECT * FROM students ORDER BY id LIMIT 5;

-- 1.8: Find students whose gpa is NULL
SELECT * FROM students WHERE gpa IS NULL;

-- 1.9: Find teachers with salary greater than 80000 (show name and salary)
SELECT first_name, last_name, salary FROM teachers WHERE salary > 80000;

-- 1.10: Find all 4-credit courses (show code and title)
SELECT code, title FROM courses WHERE credits = 4;
=======



-- 1.2: Get the email of every student, ordered alphabetically



-- 1.3: Find all students with a GPA greater than 3.5 (show name and GPA)



-- 1.4: Find all students who enrolled in 2021



-- 1.5: Find students with GPA between 3.0 and 3.5 (inclusive)



-- 1.6: Find the student with email 'grace@school.edu'



-- 1.7: Retrieve only the first 5 students (by id)



-- 1.8: Find students whose gpa is NULL



-- 1.9: Find teachers with salary greater than 80000 (show name and salary)



-- 1.10: Find all 4-credit courses (show code and title)


>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
