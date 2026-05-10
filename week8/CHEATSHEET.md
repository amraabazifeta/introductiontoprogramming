# SQL Quick Reference Cheat Sheet

> Week 8 — SQL | CS50-style

---

## SELECT Statement Structure

```sql
SELECT column1, column2, ...    -- What to retrieve
FROM table_name                 -- Where to get it
JOIN other_table ON condition   -- Connect tables
WHERE condition                 -- Filter rows
GROUP BY column                 -- Group for aggregation
HAVING condition                -- Filter groups
ORDER BY column ASC|DESC        -- Sort results
LIMIT n                         -- Restrict output rows
OFFSET n;                       -- Skip first n rows
```

---

## Comparison Operators

```sql
=          -- equal
<> or !=   -- not equal
<  >  <=  >= -- numeric comparisons
BETWEEN x AND y
IN (val1, val2, val3)
NOT IN (...)
IS NULL
IS NOT NULL
LIKE 'pattern'   -- % = any chars, _ = one char
```

---

## Logical Operators

```sql
WHERE condition1 AND condition2
WHERE condition1 OR condition2
WHERE NOT condition
```

---

## String Functions

```sql
UPPER(text)          -- 'hello' → 'HELLO'
LOWER(text)          -- 'HELLO' → 'hello'
LENGTH(text)         -- number of characters
SUBSTR(text, start, length)
TRIM(text)           -- remove whitespace
text1 || text2       -- concatenation
REPLACE(text, old, new)
```

---

## Numeric Functions

```sql
ROUND(n, decimals)
ABS(n)
MAX(a, b)     -- not aggregate — greatest of two values
MIN(a, b)
```

---

## Aggregate Functions

```sql
COUNT(*)           -- all rows
COUNT(column)      -- non-NULL values only
SUM(column)
AVG(column)
MIN(column)
MAX(column)
GROUP_CONCAT(column, separator)  -- join text values
```

---

## NULL Handling

```sql
COALESCE(a, b, c)     -- first non-NULL value
IFNULL(a, fallback)   -- if a is NULL, use fallback
NULLIF(a, b)          -- returns NULL if a = b

-- NULL comparisons MUST use IS / IS NOT:
WHERE col IS NULL
WHERE col IS NOT NULL
-- NOT: WHERE col = NULL  ← always false!
```

---

## Joins

```sql
-- INNER JOIN — only matching rows
FROM a INNER JOIN b ON a.id = b.a_id

-- LEFT JOIN — all from left, NULLs from right if no match
FROM a LEFT JOIN b ON a.id = b.a_id

-- Chain multiple joins:
FROM a
INNER JOIN b ON a.id = b.a_id
INNER JOIN c ON b.id = c.b_id
```

---

## Subqueries

```sql
-- Scalar (returns one value)
WHERE gpa > (SELECT AVG(gpa) FROM students)

-- List (returns column)
WHERE id IN (SELECT student_id FROM enrollments WHERE ...)

-- Derived table (used as FROM source)
FROM (SELECT ...) AS alias

-- EXISTS
WHERE EXISTS (SELECT 1 FROM ... WHERE ...)
WHERE NOT EXISTS (SELECT 1 FROM ... WHERE ...)
```

---

## Data Modification

```sql
-- Insert
INSERT INTO table (col1, col2) VALUES (val1, val2);
INSERT OR IGNORE INTO ...   -- skip if duplicate

-- Update
UPDATE table SET col1 = val1 WHERE condition;

-- Delete
DELETE FROM table WHERE condition;
-- ⚠️  DELETE without WHERE removes ALL rows!
```

---

## Table Creation

```sql
CREATE TABLE IF NOT EXISTS table_name (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    value REAL DEFAULT 0,
    type TEXT CHECK(type IN ('a', 'b', 'c')),
    other_id INTEGER,
    FOREIGN KEY (other_id) REFERENCES other_table(id)
);
```

---

## Views & Indexes

```sql
-- View
CREATE VIEW view_name AS SELECT ...;
DROP VIEW IF EXISTS view_name;

-- Index
CREATE INDEX idx_name ON table(column);
CREATE UNIQUE INDEX idx_name ON table(column);
CREATE INDEX idx_compound ON table(col1, col2);
DROP INDEX IF EXISTS idx_name;

-- Inspect query plan
EXPLAIN QUERY PLAN SELECT ...;
```

---

## Transactions

```sql
BEGIN TRANSACTION;
-- ... SQL statements ...
COMMIT;    -- or ROLLBACK;
```

---

## SQLite CLI Commands

```
.tables              List all tables
.schema table        Show CREATE statement
.headers on          Show column names
.mode column         Column-aligned output
.mode csv            CSV output
.output file.csv     Write output to file
.output stdout       Back to screen
.quit                Exit SQLite
```

---

## Common Patterns

```sql
-- Rank by value (no RANK() in SQLite)
SELECT name, score,
       (SELECT COUNT(*) FROM table t2 WHERE t2.score > t.score) + 1 AS rank
FROM table t;

-- Running total
SELECT date, amount,
       SUM(amount) OVER (ORDER BY date) AS running_total
FROM sales;

-- Find duplicates
SELECT email, COUNT(*) FROM users
GROUP BY email HAVING COUNT(*) > 1;

-- Upsert (insert or replace)
INSERT OR REPLACE INTO table (id, name) VALUES (1, 'updated');
```

---

*Remember: SQL keywords are not case-sensitive, but UPPERCASE is conventional. Always test destructive operations (UPDATE, DELETE) with a SELECT first!*
