-- Exercise 07: Advanced SQL
-- Databases: school.db and library.db

.headers on
.mode column

-- 7.1: Create an index on students.gpa, then EXPLAIN QUERY PLAN



-- 7.2: Create view 'enrollment_details', then query for 'A' grades



-- 7.3: Create view 'course_statistics' with count and avg final score



-- 7.4: Insert a new student (newstudent@school.edu, 2024, NULL gpa)



-- 7.5: Update student id=17 (Quinn Moore) to set gpa = 3.22



-- 7.6: Preview and then DELETE all grades with letter_grade = 'F'
-- Step 1: SELECT to preview (run this first!)

-- Step 2: DELETE (uncomment when ready)



-- 7.7: Transaction to enroll student 1 in course 13 + add grade record



-- 7.8: Transaction: decrease available_copies for book 3, insert loan (library.db)



-- 7.9: EXPLAIN QUERY PLAN comparison
-- Run both and compare the output:

-- Version A (may not use index well):

-- Version B (index-friendly):

-- Your explanation of the difference (as a comment):
-- ...



-- 7.10 CHALLENGE: Create compound index for enrollments(student_id, course_id)


