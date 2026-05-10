-- ============================================================
-- school.db — Practice database for Week 8 SQL exercises
-- ============================================================

DROP TABLE IF EXISTS enrollments;
DROP TABLE IF EXISTS grades;
DROP TABLE IF EXISTS courses;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS teachers;
DROP TABLE IF EXISTS departments;

-- Departments
CREATE TABLE departments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    building TEXT
);

INSERT INTO departments (name, building) VALUES
    ('Computer Science', 'Science Hall'),
    ('Mathematics', 'Science Hall'),
    ('English', 'Humanities Building'),
    ('History', 'Humanities Building'),
    ('Biology', 'Life Sciences Center'),
    ('Physics', 'Science Hall'),
    ('Philosophy', 'Humanities Building');

-- Teachers
CREATE TABLE teachers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    department_id INTEGER,
    hire_date TEXT,
    salary REAL,
    FOREIGN KEY (department_id) REFERENCES departments(id)
);

INSERT INTO teachers (first_name, last_name, email, department_id, hire_date, salary) VALUES
    ('David', 'Malan', 'malan@cs50.harvard.edu', 1, '2007-09-01', 95000),
    ('Brian', 'Yu', 'brian@cs50.harvard.edu', 1, '2019-06-15', 78000),
    ('Doug', 'Lloyd', 'lloyd@cs50.harvard.edu', 1, '2015-01-10', 82000),
    ('Colton', 'Ogden', 'ogden@math.edu', 2, '2018-08-20', 74000),
    ('Lisa', 'Adams', 'adams@english.edu', 3, '2010-09-01', 71000),
    ('James', 'Rivera', 'rivera@history.edu', 4, '2012-01-15', 69000),
    ('Sarah', 'Chen', 'chen@bio.edu', 5, '2016-08-25', 80000),
    ('Marcus', 'Johnson', 'johnson@physics.edu', 6, '2011-03-01', 88000),
    ('Priya', 'Patel', 'patel@cs.edu', 1, '2020-09-01', 77000),
    ('Elena', 'Kowalski', 'kowalski@phil.edu', 7, '2014-08-15', 68000);

-- Students
CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    birth_date TEXT,
    enrollment_year INTEGER,
    gpa REAL
);

INSERT INTO students (first_name, last_name, email, birth_date, enrollment_year, gpa) VALUES
    ('Alice', 'Johnson', 'alice@school.edu', '2001-03-14', 2019, 3.8),
    ('Bob', 'Smith', 'bob@school.edu', '2000-07-22', 2018, 3.2),
    ('Carol', 'White', 'carol@school.edu', '2001-11-05', 2019, 3.9),
    ('David', 'Brown', 'david@school.edu', '2002-01-30', 2020, 2.7),
    ('Eva', 'Martinez', 'eva@school.edu', '2000-05-17', 2018, 3.6),
    ('Frank', 'Lee', 'frank@school.edu', '2001-09-08', 2019, 3.1),
    ('Grace', 'Kim', 'grace@school.edu', '2003-02-25', 2021, 4.0),
    ('Henry', 'Wilson', 'henry@school.edu', '2000-12-11', 2018, 2.5),
    ('Iris', 'Garcia', 'iris@school.edu', '2002-06-19', 2020, 3.7),
    ('Jack', 'Taylor', 'jack@school.edu', '2001-08-03', 2019, 3.4),
    ('Karen', 'Anderson', 'karen@school.edu', '2003-04-22', 2021, 3.85),
    ('Leo', 'Thomas', 'leo@school.edu', '2000-10-30', 2018, 2.9),
    ('Maya', 'Jackson', 'maya@school.edu', '2002-07-14', 2020, 3.95),
    ('Nathan', 'Harris', 'nathan@school.edu', '2001-03-27', 2019, 3.3),
    ('Olivia', 'Martin', 'olivia@school.edu', '2003-01-09', 2021, 3.75),
    ('Peter', 'Thompson', 'peter@school.edu', '2000-11-16', 2018, 3.0),
    ('Quinn', 'Moore', 'quinn@school.edu', '2002-08-28', 2020, NULL),
    ('Rachel', 'Davis', 'rachel@school.edu', '2001-05-04', 2019, 3.55),
    ('Sam', 'Clark', 'sam@school.edu', '2003-09-12', 2021, 3.65),
    ('Tina', 'Rodriguez', 'tina@school.edu', '2000-02-18', 2018, 3.45);

-- Courses
CREATE TABLE courses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    code TEXT UNIQUE NOT NULL,
    title TEXT NOT NULL,
    credits INTEGER NOT NULL,
    department_id INTEGER,
    teacher_id INTEGER,
    capacity INTEGER,
    FOREIGN KEY (department_id) REFERENCES departments(id),
    FOREIGN KEY (teacher_id) REFERENCES teachers(id)
);

INSERT INTO courses (code, title, credits, department_id, teacher_id, capacity) VALUES
    ('CS50', 'Introduction to Computer Science', 4, 1, 1, 300),
    ('CS51', 'Introduction to Programming with Python', 3, 1, 2, 80),
    ('CS61', 'Systems Programming', 4, 1, 3, 60),
    ('CS124', 'Data Structures and Algorithms', 4, 1, 9, 50),
    ('MATH101', 'Calculus I', 4, 2, 4, 100),
    ('MATH201', 'Linear Algebra', 3, 2, 4, 60),
    ('ENG101', 'College Writing', 3, 3, 5, 25),
    ('ENG201', 'Literature and Society', 3, 3, 5, 30),
    ('HIST101', 'World History I', 3, 4, 6, 75),
    ('BIO101', 'Introduction to Biology', 4, 5, 7, 120),
    ('PHYS101', 'Physics I: Mechanics', 4, 6, 8, 80),
    ('PHIL101', 'Introduction to Philosophy', 3, 7, 10, 40),
    ('CS201', 'Web Programming', 3, 1, 2, 70),
    ('CS301', 'Artificial Intelligence', 4, 1, 1, 45);

-- Enrollments
CREATE TABLE enrollments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    student_id INTEGER NOT NULL,
    course_id INTEGER NOT NULL,
    enrollment_date TEXT,
    UNIQUE(student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (course_id) REFERENCES courses(id)
);

INSERT INTO enrollments (student_id, course_id, enrollment_date) VALUES
    (1, 1, '2022-09-01'), (1, 5, '2022-09-01'), (1, 7, '2022-09-01'),
    (2, 1, '2021-09-01'), (2, 9, '2021-09-01'), (2, 11, '2021-09-01'),
    (3, 1, '2022-09-01'), (3, 4, '2022-09-01'), (3, 6, '2022-09-01'),
    (4, 2, '2023-09-01'), (4, 5, '2023-09-01'), (4, 12, '2023-09-01'),
    (5, 1, '2021-09-01'), (5, 10, '2021-09-01'), (5, 13, '2021-09-01'),
    (6, 3, '2022-09-01'), (6, 5, '2022-09-01'), (6, 11, '2022-09-01'),
    (7, 1, '2024-09-01'), (7, 2, '2024-09-01'), (7, 4, '2024-09-01'),
    (8, 8, '2021-09-01'), (8, 9, '2021-09-01'),
    (9, 2, '2023-09-01'), (9, 10, '2023-09-01'), (9, 12, '2023-09-01'),
    (10, 1, '2022-09-01'), (10, 13, '2022-09-01'),
    (11, 1, '2024-09-01'), (11, 4, '2024-09-01'), (11, 6, '2024-09-01'),
    (12, 9, '2021-09-01'), (12, 11, '2021-09-01'),
    (13, 2, '2023-09-01'), (13, 4, '2023-09-01'), (13, 14, '2023-09-01'),
    (14, 1, '2022-09-01'), (14, 7, '2022-09-01'), (14, 8, '2022-09-01'),
    (15, 1, '2024-09-01'), (15, 5, '2024-09-01'), (15, 10, '2024-09-01'),
    (16, 9, '2021-09-01'), (16, 11, '2021-09-01'), (16, 12, '2021-09-01'),
    (17, 12, '2023-09-01'),
    (18, 1, '2022-09-01'), (18, 3, '2022-09-01'), (18, 5, '2022-09-01'),
    (19, 1, '2024-09-01'), (19, 2, '2024-09-01'), (19, 12, '2024-09-01'),
    (20, 1, '2021-09-01'), (20, 8, '2021-09-01'), (20, 13, '2021-09-01');

-- Grades
CREATE TABLE grades (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    enrollment_id INTEGER NOT NULL,
    midterm REAL,
    final REAL,
    assignments REAL,
    letter_grade TEXT,
    FOREIGN KEY (enrollment_id) REFERENCES enrollments(id)
);

INSERT INTO grades (enrollment_id, midterm, final, assignments, letter_grade) VALUES
    (1, 88, 91, 95, 'A'), (2, 75, 80, 82, 'B'),  (3, 70, 65, 72, 'C'),
    (4, 92, 95, 98, 'A'), (5, 60, 58, 65, 'D'),  (6, 85, 88, 90, 'A'),
    (7, 95, 97, 99, 'A'), (8, 72, 75, 78, 'C'),  (9, 68, 70, 65, 'D'),
    (10, 55, 60, 58, 'D'),(11, 80, 84, 86, 'B'), (12, 78, 82, 80, 'B'),
    (13, 94, 96, 97, 'A'),(14, 82, 85, 88, 'B'), (15, 73, 70, 76, 'C'),
    (16, 90, 88, 92, 'A'),(17, 65, 68, 62, 'D'), (18, 45, 50, 48, 'F'),
    (19, 88, 85, 90, 'B'),(20, 76, 79, 81, 'B'), (21, 62, 65, 68, 'D'),
    (22, 88, 92, 85, 'A'),(23, 71, 74, 77, 'C'), (24, 83, 86, 88, 'B'),
    (25, 91, 94, 96, 'A'),(26, 79, 82, 80, 'B'), (27, 97, 99, 98, 'A'),
    (28, 86, 89, 91, 'A'),(29, 74, 72, 78, 'C'), (30, 88, 90, 92, 'A'),
    (31, 96, 98, 99, 'A'),(32, 81, 83, 85, 'B'), (33, 67, 65, 70, 'D'),
    (34, 77, 80, 78, 'B'),(35, 93, 95, 97, 'A'), (36, 98, 99, 100,'A'),
    (37, NULL, NULL, NULL, NULL),
    (38, 85, 88, 90, 'A'),(39, 73, 76, 78, 'C'), (40, 87, 90, 88, 'A'),
    (41, 96, 98, 97, 'A'),(42, 80, 83, 85, 'B'), (43, 74, 70, 76, 'C'),
    (44, 65, 68, 62, 'D'),(45, 88, 85, 90, 'B'), (46, 55, 52, 58, 'F'),
    (47, 83, 86, 87, 'B'),(48, 71, 74, 73, 'C'), (49, 90, 92, 94, 'A'),
    (50, 84, 87, 86, 'B'),(51, 69, 72, 70, 'C'), (52, 92, 94, 96, 'A'),
    (53, 78, 80, 82, 'B'),(54, 86, 88, 90, 'A'), (55, 73, 76, 75, 'C'),
    (56, 94, 97, 98, 'A'),(57, 81, 84, 83, 'B');
