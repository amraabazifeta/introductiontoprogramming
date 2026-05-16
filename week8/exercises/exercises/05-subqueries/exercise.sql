.headers on
.mode column

-- =========================
-- 5.1 Above average GPA
-- =========================
SELECT first_name, last_name, gpa
FROM students
WHERE gpa > (SELECT AVG(gpa) FROM students);

-- =========================
-- 5.2 Students in CS50
-- =========================
SELECT first_name, last_name
FROM students
WHERE id IN (
    SELECT student_id
    FROM enrollments
    WHERE course_id = (
        SELECT id FROM courses WHERE code = 'CS50'
    )
);

-- =========================
-- 5.3 Students NOT in CS50
-- =========================
SELECT first_name, last_name
FROM students
WHERE id NOT IN (
    SELECT student_id
    FROM enrollments
    WHERE course_id = (
        SELECT id FROM courses WHERE code = 'CS50'
    )
);

-- =========================
-- 5.4 Courses by highest-paid teacher
-- =========================
SELECT title AS course_title
FROM courses
WHERE teacher_id = (
    SELECT id
    FROM teachers
    WHERE salary = (SELECT MAX(salary) FROM teachers)
);

-- =========================
-- 5.5 Students with 3+ courses
-- =========================
SELECT s.first_name, s.last_name
FROM students s
JOIN (
    SELECT student_id
    FROM enrollments
    GROUP BY student_id
    HAVING COUNT(course_id) >= 3
) ec ON s.id = ec.student_id;

-- =========================
-- 5.6 Members with >2 borrowed books
-- =========================
SELECT m.first_name, m.last_name
FROM members m
JOIN (
    SELECT member_id
    FROM loans
    GROUP BY member_id
    HAVING COUNT(book_id) > 2
) l ON m.id = l.member_id;

-- =========================
-- 5.7 Books above average page count
-- =========================
SELECT title, pages
FROM books
WHERE pages > (SELECT AVG(pages) FROM books);

-- =========================
-- 5.8 Students with at least one grade (EXISTS)
-- =========================
SELECT first_name, last_name
FROM students s
WHERE EXISTS (
    SELECT 1
    FROM enrollments e
    WHERE e.student_id = s.id
    AND e.grade IS NOT NULL
);

-- =========================
-- 5.9 Courses with no grades (NOT EXISTS)
-- =========================
SELECT title
FROM courses c
WHERE NOT EXISTS (
    SELECT 1
    FROM enrollments e
    WHERE e.course_id = c.id
    AND e.grade IS NOT NULL
);

-- =========================
-- 5.10 Course(s) with most enrollments
-- =========================
SELECT title
FROM courses
WHERE id IN (
    SELECT course_id
    FROM enrollments
    GROUP BY course_id
    HAVING COUNT(student_id) = (
        SELECT MAX(cnt)
        FROM (
            SELECT COUNT(student_id) AS cnt
            FROM enrollments
            GROUP BY course_id
        )
    )
);
