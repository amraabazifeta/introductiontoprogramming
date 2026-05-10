.headers on
.mode column

-- 2.1: Students whose last name contains 's' (school.db)

SELECT *
FROM students
WHERE last_name LIKE '%s%';

-- 2.2: Teachers with email ending in @cs50.harvard.edu (school.db)

SELECT *
FROM teachers
WHERE email LIKE '%@cs50.harvard.edu';

-- 2.3: Top 5 students by GPA, highest first (school.db)

SELECT first_name, last_name, gpa
FROM students
ORDER BY gpa DESC
LIMIT 5;

-- 2.4: Distinct enrollment years (school.db)

SELECT DISTINCT enrollment_year
FROM students
ORDER BY enrollment_year;

-- 2.5: Courses in department 1 OR 2, using IN (school.db)

SELECT *
FROM courses
WHERE department_id IN (1, 2);

-- 2.6: Students who did NOT enroll in 2018, using NOT IN (school.db)

SELECT *
FROM students
WHERE enrollment_year NOT IN (2018);

-- 2.7: Courses sorted by credits (desc), then title (asc) (school.db)

SELECT *
FROM courses
ORDER BY credits DESC, title ASC;

-- 2.8: Books whose title starts with 'The' (library.db)

SELECT *
FROM books
WHERE title LIKE 'The%';

-- 2.9: Loans where return_date is NULL (library.db)

SELECT id, member_id, due_date
FROM loans
WHERE return_date IS NULL;

-- 2.10: British authors sorted by last name (library.db)

SELECT *
FROM authors
WHERE nationality = 'British'
ORDER BY last_name ASC;

-- 2.11: Members with membership_type 'premium' or 'student' (library.db)

SELECT *
FROM members
WHERE membership_type IN ('premium', 'student');

-- 2.12 CHALLENGE: Students with exactly 4-letter first names (school.db)

SELECT *
FROM students
WHERE first_name LIKE '____';
