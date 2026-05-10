-- ============================================================
-- library.db — Practice database for Week 8 SQL exercises
-- ============================================================

DROP TABLE IF EXISTS loans;
DROP TABLE IF EXISTS book_authors;
DROP TABLE IF EXISTS books;
DROP TABLE IF EXISTS authors;
DROP TABLE IF EXISTS members;
DROP TABLE IF EXISTS genres;

CREATE TABLE genres (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT UNIQUE NOT NULL
);

INSERT INTO genres (name) VALUES
    ('Fiction'), ('Non-Fiction'), ('Science Fiction'), ('Mystery'),
    ('Biography'), ('History'), ('Fantasy'), ('Self-Help'),
    ('Programming'), ('Philosophy');

CREATE TABLE authors (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    birth_year INTEGER,
    nationality TEXT
);

INSERT INTO authors (first_name, last_name, birth_year, nationality) VALUES
    ('George', 'Orwell', 1903, 'British'),
    ('J.K.', 'Rowling', 1965, 'British'),
    ('Frank', 'Herbert', 1920, 'American'),
    ('Agatha', 'Christie', 1890, 'British'),
    ('Isaac', 'Asimov', 1920, 'American'),
    ('Toni', 'Morrison', 1931, 'American'),
    ('Gabriel', 'García Márquez', 1927, 'Colombian'),
    ('Donald', 'Knuth', 1938, 'American'),
    ('Walter', 'Isaacson', 1952, 'American'),
    ('Yuval', 'Harari', 1976, 'Israeli'),
    ('J.R.R.', 'Tolkien', 1892, 'British'),
    ('Chimamanda', 'Adichie', 1977, 'Nigerian'),
    ('Stephen', 'King', 1947, 'American'),
    ('Ursula', 'Le Guin', 1929, 'American');

CREATE TABLE books (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    isbn TEXT UNIQUE,
    genre_id INTEGER,
    published_year INTEGER,
    pages INTEGER,
    available_copies INTEGER DEFAULT 1,
    total_copies INTEGER DEFAULT 1,
    FOREIGN KEY (genre_id) REFERENCES genres(id)
);

INSERT INTO books (title, isbn, genre_id, published_year, pages, available_copies, total_copies) VALUES
    ('1984', '978-0451524935', 1, 1949, 328, 2, 3),
    ('Animal Farm', '978-0451526342', 1, 1945, 144, 1, 2),
    ('Harry Potter and the Sorcerer''s Stone', '978-0590353427', 7, 1997, 309, 3, 5),
    ('Dune', '978-0441172719', 3, 1965, 896, 1, 2),
    ('Foundation', '978-0553293357', 3, 1951, 244, 2, 3),
    ('Murder on the Orient Express', '978-0062073501', 4, 1934, 256, 1, 2),
    ('Beloved', '978-1400033416', 1, 1987, 321, 2, 2),
    ('One Hundred Years of Solitude', '978-0060883287', 1, 1967, 417, 1, 2),
    ('The Art of Computer Programming Vol. 1', '978-0201896831', 9, 1968, 672, 1, 1),
    ('Steve Jobs', '978-1451648539', 5, 2011, 656, 2, 3),
    ('Sapiens', '978-0062316097', 2, 2011, 443, 3, 4),
    ('The Lord of the Rings', '978-0618640157', 7, 1954, 1178, 2, 3),
    ('Americanah', '978-0307455925', 1, 2013, 477, 1, 2),
    ('The Shining', '978-0307743657', 4, 1977, 447, 1, 2),
    ('The Left Hand of Darkness', '978-0441478125', 3, 1969, 304, 1, 1),
    ('Homo Deus', '978-0062464316', 2, 2015, 464, 2, 2),
    ('And Then There Were None', '978-0062073488', 4, 1939, 264, 0, 2),
    ('The Hobbit', '978-0547928227', 7, 1937, 310, 2, 3),
    ('It', '978-1501156700', 4, 1986, 1138, 1, 2),
    ('Brave New World', '978-0060850524', 3, 1932, 311, 1, 2);

CREATE TABLE book_authors (
    book_id INTEGER,
    author_id INTEGER,
    PRIMARY KEY (book_id, author_id),
    FOREIGN KEY (book_id) REFERENCES books(id),
    FOREIGN KEY (author_id) REFERENCES authors(id)
);

INSERT INTO book_authors (book_id, author_id) VALUES
    (1,1),(2,1),(3,2),(4,3),(5,5),(6,4),(7,6),(8,7),
    (9,8),(10,9),(11,10),(12,11),(13,12),(14,13),(15,14),
    (16,10),(17,4),(18,11),(19,13),(20,5);

CREATE TABLE members (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name TEXT NOT NULL,
    last_name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    phone TEXT,
    join_date TEXT,
    membership_type TEXT CHECK(membership_type IN ('basic', 'premium', 'student'))
);

INSERT INTO members (first_name, last_name, email, phone, join_date, membership_type) VALUES
    ('Alice', 'Johnson', 'alice@email.com', '555-0101', '2020-01-15', 'premium'),
    ('Bob', 'Smith', 'bob@email.com', '555-0102', '2021-03-22', 'basic'),
    ('Carol', 'White', 'carol@email.com', '555-0103', '2019-07-10', 'student'),
    ('David', 'Brown', 'david@email.com', '555-0104', '2022-05-03', 'basic'),
    ('Eva', 'Martinez', 'eva@email.com', '555-0105', '2020-11-18', 'premium'),
    ('Frank', 'Lee', 'frank@email.com', '555-0106', '2023-02-28', 'student'),
    ('Grace', 'Kim', 'grace@email.com', '555-0107', '2018-09-05', 'premium'),
    ('Henry', 'Wilson', 'henry@email.com', '555-0108', '2021-06-14', 'basic'),
    ('Iris', 'Garcia', 'iris@email.com', '555-0109', '2022-12-01', 'student'),
    ('Jack', 'Taylor', 'jack@email.com', '555-0110', '2020-04-19', 'basic');

CREATE TABLE loans (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    member_id INTEGER NOT NULL,
    book_id INTEGER NOT NULL,
    loan_date TEXT NOT NULL,
    due_date TEXT NOT NULL,
    return_date TEXT,
    fine REAL DEFAULT 0,
    FOREIGN KEY (member_id) REFERENCES members(id),
    FOREIGN KEY (book_id) REFERENCES books(id)
);

INSERT INTO loans (member_id, book_id, loan_date, due_date, return_date, fine) VALUES
    (1, 1, '2024-01-10', '2024-01-24', '2024-01-22', 0),
    (1, 3, '2024-02-01', '2024-02-15', '2024-02-20', 2.50),
    (2, 11, '2024-01-15', '2024-01-29', '2024-01-28', 0),
    (3, 4, '2024-01-20', '2024-02-03', '2024-02-03', 0),
    (4, 5, '2024-02-10', '2024-02-24', NULL, 0),
    (5, 3, '2024-02-12', '2024-02-26', '2024-02-25', 0),
    (5, 10, '2024-03-01', '2024-03-15', NULL, 0),
    (6, 11, '2024-03-05', '2024-03-19', '2024-03-18', 0),
    (7, 12, '2024-01-05', '2024-01-19', '2024-01-30', 5.50),
    (7, 18, '2024-02-20', '2024-03-06', '2024-03-06', 0),
    (8, 6, '2024-03-10', '2024-03-24', NULL, 0),
    (9, 20, '2024-02-28', '2024-03-13', '2024-03-12', 0),
    (10, 8, '2024-01-25', '2024-02-08', '2024-02-15', 3.50),
    (1, 15, '2024-03-15', '2024-03-29', NULL, 0),
    (2, 14, '2024-03-20', '2024-04-03', NULL, 0),
    (3, 7, '2024-02-05', '2024-02-19', '2024-02-19', 0),
    (4, 2, '2024-03-12', '2024-03-26', NULL, 0),
    (6, 9, '2024-01-30', '2024-02-13', '2024-02-20', 3.50),
    (8, 13, '2024-03-18', '2024-04-01', NULL, 0),
    (10, 16, '2024-02-22', '2024-03-07', '2024-03-07', 0);
