-- Exercise 06: Database Design

-- ============================================================
-- 6.1 — Social Media Schema
-- ============================================================

CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    email TEXT UNIQUE NOT NULL,
    bio TEXT,
    join_date TEXT DEFAULT (DATE('now'))
);

CREATE TABLE IF NOT EXISTS posts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    created_at TEXT DEFAULT (DATETIME('now')),
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE IF NOT EXISTS follows (
    follower_id INTEGER NOT NULL,
    following_id INTEGER NOT NULL,
    PRIMARY KEY (follower_id, following_id),
    FOREIGN KEY (follower_id) REFERENCES users(id),
    FOREIGN KEY (following_id) REFERENCES users(id)
);

CREATE TABLE IF NOT EXISTS likes (
    user_id INTEGER NOT NULL,
    post_id INTEGER NOT NULL,
    PRIMARY KEY (user_id, post_id),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (post_id) REFERENCES posts(id)
);

CREATE TABLE IF NOT EXISTS comments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    post_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    created_at TEXT DEFAULT (DATETIME('now')),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (post_id) REFERENCES posts(id)
);

-- ============================================================
-- 6.2 — Movie Rental Schema
-- ============================================================

CREATE TABLE IF NOT EXISTS genres (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    release_year INTEGER,
    rating TEXT CHECK(rating IN ('G', 'PG', 'PG-13', 'R')),
    genre_id INTEGER,
    FOREIGN KEY (genre_id) REFERENCES genres(id)
);

CREATE TABLE IF NOT EXISTS copies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    movie_id INTEGER NOT NULL,
    condition TEXT CHECK(condition IN ('good', 'fair', 'damaged')),
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);

CREATE TABLE IF NOT EXISTS customers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    phone TEXT
);

CREATE TABLE IF NOT EXISTS rentals (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    copy_id INTEGER NOT NULL,
    rental_date TEXT NOT NULL,
    due_date TEXT NOT NULL,
    return_date TEXT,
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (copy_id) REFERENCES copies(id)
);

CREATE TABLE IF NOT EXISTS reviews (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    movie_id INTEGER NOT NULL,
    stars INTEGER CHECK(stars BETWEEN 1 AND 5),
    review_text TEXT,
    FOREIGN KEY (customer_id) REFERENCES customers(id),
    FOREIGN KEY (movie_id) REFERENCES movies(id)
);

-- ============================================================
-- 6.3 — E-Commerce Schema
-- ============================================================

CREATE TABLE IF NOT EXISTS categories (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    parent_id INTEGER,
    FOREIGN KEY (parent_id) REFERENCES categories(id)
);

CREATE TABLE IF NOT EXISTS products (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    description TEXT,
    price REAL NOT NULL,
    stock INTEGER DEFAULT 0,
    category_id INTEGER,
    FOREIGN KEY (category_id) REFERENCES categories(id)
);

CREATE TABLE IF NOT EXISTS customers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS orders (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    order_date TEXT DEFAULT (DATETIME('now')),
    status TEXT CHECK(status IN ('pending', 'shipped', 'delivered', 'cancelled')),
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

CREATE TABLE IF NOT EXISTS order_items (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    order_id INTEGER NOT NULL,
    product_id INTEGER NOT NULL,
    quantity INTEGER NOT NULL,
    price_at_purchase REAL NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(id),
    FOREIGN KEY (product_id) REFERENCES products(id)
);

-- ============================================================
-- 6.4 — Fix the Bad Schema
-- ============================================================

-- Problems identified:
-- 1. 'info' is vague — no clear purpose or type
-- 2. 'name_and_email' mixes two values in one column — violates 1NF
-- 3. 'courses' stores a list in one column — violates 1NF
-- 4. 'gpa' should be REAL not TEXT
-- 5. 'teacher_name' duplicates data — should be a foreign key
-- 6. 'teacher_salary' duplicates data — belongs in a teachers table

CREATE TABLE IF NOT EXISTS students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    gpa REAL
);

CREATE TABLE IF NOT EXISTS teachers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    salary REAL NOT NULL
);

CREATE TABLE IF NOT EXISTS courses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    teacher_id INTEGER,
    FOREIGN KEY (teacher_id) REFERENCES teachers(id)
);

CREATE TABLE IF NOT EXISTS enrollments (
    student_id INTEGER NOT NULL,
    course_id INTEGER NOT NULL,
    PRIMARY KEY (student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (course_id) REFERENCES courses(id)
);

-- ============================================================
-- 6.5 — Seed Social Media Database
-- ============================================================

INSERT INTO users (username, email, bio) VALUES
    ('alice', 'alice@email.com', 'Loves coding'),
    ('bob', 'bob@email.com', 'Coffee enthusiast'),
    ('carol', 'carol@email.com', 'Traveller'),
    ('david', 'david@email.com', 'Gamer'),
    ('eva', 'eva@email.com', 'Foodie');

INSERT INTO posts (user_id, content) VALUES
    (1, 'Hello world!'),
    (1, 'Learning SQL today'),
    (2, 'Coffee is life'),
    (2, 'Good morning everyone'),
    (3, 'Just landed in Paris!'),
    (3, 'Amazing food here'),
    (4, 'New high score!'),
    (4, 'Anyone up for gaming?'),
    (5, 'Made homemade pasta'),
    (5, 'Best tacos ever');

INSERT INTO follows (follower_id, following_id) VALUES
    (1, 2), (1, 3), (2, 1), (3, 4), (4, 5);

INSERT INTO likes (user_id, post_id) VALUES
    (1, 3), (1, 5), (2, 1), (2, 7),
    (3, 2), (3, 9), (4, 6), (4, 10),
    (5, 1), (5, 4);

INSERT INTO comments (user_id, post_id, content) VALUES
    (2, 1, 'Welcome!'),
    (3, 2, 'SQL is fun!'),
    (1, 3, 'Agreed!'),
    (4, 5, 'So jealous!'),
    (5, 9, 'Looks delicious!');

-- Q1: Who does user 1 follow?
SELECT u.username
FROM follows f
INNER JOIN users u ON f.following_id = u.id
WHERE f.follower_id = 1;

-- Q2: Most liked posts?
SELECT p.content, COUNT(*) AS likes
FROM likes l
INNER JOIN posts p ON l.post_id = p.id
GROUP BY l.post_id
ORDER BY likes DESC;

-- Q3: User who posted the most?
SELECT u.username, COUNT(*) AS post_count
FROM posts p
INNER JOIN users u ON p.user_id = u.id
GROUP BY p.user_id
ORDER BY post_count DESC
LIMIT 1;
