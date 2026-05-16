.headers on
.mode column

-- =========================
-- 3.1 Student + Course
-- =========================
SELECT s.first_name || ' ' || s.last_name AS student_name,
       c.title AS course_title
FROM enrollments e
JOIN students s ON e.student_id = s.id
JOIN courses c ON e.course_id = c.id;

-- =========================
-- 3.2 Course + Teacher
-- =========================
SELECT c.title AS course_title,
       t.first_name || ' ' || t.last_name AS teacher_name
FROM courses c
JOIN teachers t ON c.teacher_id = t.id;

-- =========================
-- 3.3 Teacher + Department
-- =========================
SELECT t.first_name || ' ' || t.last_name AS teacher_name,
       d.name AS department_name
FROM teachers t
JOIN departments d ON t.department_id = d.id;

-- =========================
-- 3.4 Student + Course + Teacher + Grade
-- =========================
SELECT s.first_name || ' ' || s.last_name AS student_name,
       c.title AS course_title,
       t.first_name || ' ' || t.last_name AS teacher_name,
       e.grade AS letter_grade
FROM enrollments e
JOIN students s ON e.student_id = s.id
JOIN courses c ON e.course_id = c.id
JOIN teachers t ON c.teacher_id = t.id;

-- =========================
-- 3.5 Students with NO enrollments
-- =========================
SELECT s.first_name || ' ' || s.last_name AS student_name
FROM students s
LEFT JOIN enrollments e ON s.id = e.student_id
WHERE e.student_id IS NULL;

-- =========================
-- 3.6 Courses with NO students
-- =========================
SELECT c.title AS course_title
FROM courses c
LEFT JOIN enrollments e ON c.id = e.course_id
WHERE e.course_id IS NULL;

-- =========================
-- 3.7 Book + Author
-- =========================
SELECT b.title AS book_title,
       a.first_name || ' ' || a.last_name AS author_name
FROM books b
JOIN authors a ON b.author_id = a.id;

-- =========================
-- 3.8 Genre + Books (include empty)
-- =========================
SELECT g.name AS genre_name,
       b.title AS book_title
FROM genres g
LEFT JOIN books b ON g.id = b.genre_id;

-- =========================
-- 3.9 Member + Borrowed Books (include non-borrowers)
-- =========================
SELECT m.first_name || ' ' || m.last_name AS member_name,
       b.title AS book_title
FROM members m
LEFT JOIN loans l ON m.id = l.member_id
LEFT JOIN books b ON l.book_id = b.id;

-- =========================
-- 3.10 Loans + COALESCE
-- =========================
SELECT m.first_name || ' ' || m.last_name AS member_name,
       b.title AS book_title,
       l.loan_date,
       COALESCE(l.return_date, 'Not returned') AS return_status
FROM loans l
JOIN members m ON l.member_id = m.id
JOIN books b ON l.book_id = b.id;
