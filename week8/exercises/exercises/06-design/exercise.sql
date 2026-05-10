-- Exercise 06: Database Design
-- Create a new database file for each exercise:
-- sqlite3 data/social.db < exercises/06-design/exercise.sql

-- ============================================================
-- 6.1 — Social Media Schema
-- ============================================================
-- Design entities: Users, Posts, Follows, Likes, Comments
-- Write your CREATE TABLE statements below:

<<<<<<< HEAD
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL UNIQUE,
    bio TEXT,
    join_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE posts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE follows (
    follower_id INTEGER NOT NULL,
    following_id INTEGER NOT NULL,
    PRIMARY KEY (follower_id, following_id),
    FOREIGN KEY (follower_id) REFERENCES users(id),
    FOREIGN KEY (following_id) REFERENCES users(id)
);

CREATE TABLE likes (
    user_id INTEGER NOT NULL,
    post_id INTEGER NOT NULL,
    PRIMARY KEY (user_id, post_id),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (post_id) REFERENCES posts(id)
);

CREATE TABLE comments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    post_id INTEGER NOT NULL,
    user_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (post_id) REFERENCES posts(id),
    FOREIGN KEY (user_id) REFERENCES users(id)
);
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

-- ============================================================
-- 6.2 — Movie Rental Schema
-- ============================================================
-- Entities: Genres, Movies, Copies, Customers, Rentals, Reviews
-- Write your CREATE TABLE statements below:

<<<<<<< HEAD
CREATE TABLE genres (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE
);

CREATE TABLE movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    release_year INTEGER,
    rating TEXT CHECK(rating IN ('G', 'PG', 'PG-13', 'R')),
    genre_id INTEGER,
    FOREIGN KEY (genre_id) REFERENCES genres(id)
);

CREATE TABLE copies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    movie_id INTEGER NOT NULL,
    condition TEXT CHECK(condition IN ('good', 'fair', 'damaged')),
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);

CREATE TABLE customers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE,
    phone TEXT
);

CREATE TABLE rentals (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    copy_id INTEGER NOT NULL,
    customer_id INTEGER NOT NULL,
    rental_date DATE DEFAULT CURRENT_DATE,
    due_date DATE NOT NULL,
    return_date DATE,
    FOREIGN KEY (copy_id) REFERENCES copies(id),
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

CREATE TABLE reviews (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    movie_id INTEGER NOT NULL,
    customer_id INTEGER NOT NULL,
    stars INTEGER CHECK(stars BETWEEN 1 AND 5),
    review_text TEXT,
    FOREIGN KEY (movie_id) REFERENCES movies(id),
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

-- ============================================================
-- 6.3 — E-Commerce Schema
-- ============================================================
-- Entities: Categories, Products, Customers, Orders, OrderItems
-- Write your CREATE TABLE statements below:

<<<<<<< HEAD
CREATE TABLE categories (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    parent_id INTEGER,
    FOREIGN KEY (parent_id) REFERENCES categories(id)
);

CREATE TABLE products (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    description TEXT,
    price REAL NOT NULL,
    stock_count INTEGER DEFAULT 0,
    category_id INTEGER,
    FOREIGN KEY (category_id) REFERENCES categories(id)
);

CREATE TABLE ecommerce_customers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL
);

CREATE TABLE orders (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status TEXT CHECK(status IN ('pending', 'shipped', 'delivered', 'cancelled')) DEFAULT 'pending',
    FOREIGN KEY (customer_id) REFERENCES ecommerce_customers(id)
);

CREATE TABLE order_items (
    order_id INTEGER NOT NULL,
    product_id INTEGER NOT NULL,
    quantity INTEGER NOT NULL,
    price_at_purchase REAL NOT NULL,
    PRIMARY KEY (order_id, product_id),
    FOREIGN KEY (order_id) REFERENCES orders(id),
    FOREIGN KEY (product_id) REFERENCES products(id)
);
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

-- ============================================================
-- 6.4 — Fix the Bad Schema
-- ============================================================
-- What's wrong with this? Write your fixed version:
--
<<<<<<< HEAD
-- Problems identified:
-- 1. No Primary Key defined for unique identification.
-- 2. Non-atomic data: name and email are mixed in one column.
-- 3. 1NF violation: "courses" stores multiple values in a single cell.
-- 4. Type mismatch: GPA and Salary are TEXT but should be REAL/INTEGER.
-- 5. 3NF violation: Teacher salary depends on teacher name, not the student.
-- 6. Redundancy: Teacher information is duplicated for every student record.

-- Fixed schema:
CREATE TABLE fixed_teachers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    salary REAL
);

CREATE TABLE fixed_students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE,
    gpa REAL
);

CREATE TABLE enrollments (
    student_id INTEGER,
    course_name TEXT,
    teacher_id INTEGER,
    PRIMARY KEY (student_id, course_name),
    FOREIGN KEY (student_id) REFERENCES fixed_students(id),
    FOREIGN KEY (teacher_id) REFERENCES fixed_teachers(id)
);
=======
-- CREATE TABLE student_data (
--     info TEXT,
--     name_and_email TEXT,
--     courses TEXT,
--     gpa TEXT,
--     teacher_name TEXT,
--     teacher_salary TEXT
-- );
--
-- Problems identified:
-- 1. ...
-- 2. ...
-- 3. ...
-- Fixed schema:


>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

-- ============================================================
-- 6.5 — Seed Your Social Media Database
-- ============================================================
-- After creating tables in 6.1, insert sample data:

<<<<<<< HEAD
INSERT INTO users (username, email, bio) VALUES 
('arda_skp', 'arda@mail.com', 'Computer Engineering student'),
('user_two', 'two@mail.com', 'SQL enthusiast'),
('gamer_x', 'gamer@mail.com', 'Sim racing & CS2'),
('skopje_val', 'val@mail.com', 'Photography'),
('f20_driver', 'bmw@mail.com', 'Performance cars');

INSERT INTO posts (user_id, content) VALUES 
(1, 'Database design is interesting!'), (1, 'Running SQL on M4 Mac.'),
(2, 'Always normalize your tables.'), (2, 'Learning SQLite constraints.'),
(3, 'New PB on Assetto Corsa.'), (3, 'CS2 competitive grind.'),
(4, 'Stone Bridge view today.'), (5, 'Oil change done.'),
(5, 'Stage 1 remap complete.'), (1, 'Weekend vibes in Skopje.');

INSERT INTO follows (follower_id, following_id) VALUES (1,2), (1,5), (2,1), (3,5), (5,1);
INSERT INTO likes (user_id, post_id) VALUES (1,8), (1,9), (2,1), (3,5), (4,7), (5,1), (5,2), (2,10), (3,10), (4,1);
INSERT INTO comments (post_id, user_id, content) VALUES (1,2, 'Great work!'), (8,1, 'Which oil did you use?'), (5,1, 'Nice lap!'), (10,3, 'Enjoy!'), (7,2, 'Nice pic.');

-- Verification queries:
-- Q1: Who does user 1 follow?
SELECT username FROM users WHERE id IN (SELECT following_id FROM follows WHERE follower_id = 1);

-- Q2: Most liked posts?
SELECT p.content, COUNT(l.user_id) as total_likes FROM posts p LEFT JOIN likes l ON p.id = l.post_id GROUP BY p.id ORDER BY total_likes DESC;

-- Q3: User who posted the most?
SELECT u.username, COUNT(p.id) as post_count FROM users u JOIN posts p ON u.id = p.user_id GROUP BY u.id ORDER BY post_count DESC LIMIT 1;
=======


-- Verification queries:
-- Q1: Who does user 1 follow?


-- Q2: Most liked posts?


-- Q3: User who posted the most?


>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
