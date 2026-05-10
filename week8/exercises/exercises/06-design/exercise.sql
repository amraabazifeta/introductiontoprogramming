CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    email TEXT UNIQUE NOT NULL,
    created_at TEXT
);

CREATE TABLE posts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    created_at TEXT,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE follows (
    follower_id INTEGER,
    following_id INTEGER,
    created_at TEXT,
    PRIMARY KEY (follower_id, following_id),
    FOREIGN KEY (follower_id) REFERENCES users(id),
    FOREIGN KEY (following_id) REFERENCES users(id)
);

CREATE TABLE likes (
    user_id INTEGER,
    post_id INTEGER,
    created_at TEXT,
    PRIMARY KEY (user_id, post_id),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (post_id) REFERENCES posts(id)
);

CREATE TABLE comments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER,
    post_id INTEGER,
    content TEXT,
    created_at TEXT,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (post_id) REFERENCES posts(id)
);

-- ============================================================
-- 6.2 Movie Rental Schema
-- ============================================================

CREATE TABLE genres (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT UNIQUE NOT NULL
);

CREATE TABLE movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    genre_id INTEGER,
    release_year INTEGER,
    FOREIGN KEY (genre_id) REFERENCES genres(id)
);

CREATE TABLE copies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    movie_id INTEGER,
    available INTEGER DEFAULT 1,
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);

CREATE TABLE customers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE
);

CREATE TABLE rentals (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER,
    copy_id INTEGER,
    rent_date TEXT,
    return_date TEXT,
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (copy_id) REFERENCES copies(id)
);

CREATE TABLE reviews (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER,
    movie_id INTEGER,
    rating INTEGER,
    comment TEXT,
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);

-- ============================================================
-- 6.3 E-Commerce Schema
-- ============================================================

CREATE TABLE categories (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT UNIQUE NOT NULL
);

CREATE TABLE products (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    price REAL NOT NULL,
    stock INTEGER,
    category_id INTEGER,
    FOREIGN KEY (category_id) REFERENCES categories(id)
);

CREATE TABLE customers_ecom (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE
);

CREATE TABLE orders (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER,
    order_date TEXT,
    total REAL,
    FOREIGN KEY (customer_id) REFERENCES customers_ecom(id)
);

CREATE TABLE order_items (
    order_id INTEGER,
    product_id INTEGER,
    quantity INTEGER,
    price REAL,
    PRIMARY KEY (order_id, product_id),
    FOREIGN KEY (order_id) REFERENCES orders(id),
    FOREIGN KEY (product_id) REFERENCES products(id)
);

-- ============================================================
-- 6.4 FIXED BAD SCHEMA
-- ============================================================

CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE,
    gpa REAL
);

CREATE TABLE teachers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    salary REAL
);

CREATE TABLE courses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    teacher_id INTEGER,
    FOREIGN KEY (teacher_id) REFERENCES teachers(id)
);

CREATE TABLE enrollments (
    student_id INTEGER,
    course_id INTEGER,
    PRIMARY KEY (student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (course_id) REFERENCES courses(id)
);

-- ============================================================
-- 6.5 SEED DATA (Social Media)
-- ============================================================

INSERT INTO users (username, email) VALUES
('alice', 'alice@mail.com'),
('bob', 'bob@mail.com'),
('carol', 'carol@mail.com');

INSERT INTO posts (user_id, content) VALUES
(1, 'Hello world'),
(1, 'My second post'),
(2, 'Bob here!');

INSERT INTO follows VALUES
(1,2),
(1,3),
(2,3);

INSERT INTO likes VALUES
(2,1),
(3,1),
(3,2);

INSERT INTO comments (user_id, post_id, content) VALUES
(2,1,'Nice post!'),
(3,1,'Cool!'),
(1,3,'Welcome!');

-- ============================================================
-- VERIFICATION QUERIES
-- ============================================================

-- Q1: Who does user 1 follow?
SELECT u.username
FROM follows f
JOIN users u ON f.following_id = u.id
WHERE f.follower_id = 1;

-- Q2: Most liked posts
SELECT post_id, COUNT(*) AS like_count
FROM likes
GROUP BY post_id
ORDER BY like_count DESC;

-- Q3: User who posted most
SELECT u.username, COUNT(p.id) AS post_count
FROM users u
JOIN posts p ON u.id = p.user_id
GROUP BY u.id
ORDER BY post_count DESC;
