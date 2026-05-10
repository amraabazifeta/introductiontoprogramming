# Exercise 06 — Database Design

> **No starter database needed — you will create your own!**
> **Estimated Time:** 45–60 minutes

---

## Background

Knowing how to *query* data is only half the skill. Great engineers also know how to *design* databases that are efficient, normalized, and represent real-world entities accurately.

### Key Concepts

#### Primary Keys
Every table should have a unique identifier for each row:

```sql
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL
);
```

#### Foreign Keys
Link one table to another:

```sql
CREATE TABLE posts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    content TEXT,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

#### Data Types (SQLite)

| Type | Use for |
|------|---------|
| `INTEGER` | Whole numbers, IDs |
| `REAL` | Decimal numbers |
| `TEXT` | Strings |
| `BLOB` | Binary data |
| `NUMERIC` | Flexible numeric |

#### Constraints

```sql
NOT NULL          -- value is required
UNIQUE            -- no duplicates in this column
DEFAULT value     -- fallback if not provided
CHECK(condition)  -- custom validation
```

#### Normalization (1NF, 2NF, 3NF)

- **1NF:** Each column holds one atomic value (no lists in a cell)
- **2NF:** Every non-key column depends on the whole primary key
- **3NF:** No column depends on another non-key column

**Bad design:**
```sql
-- ❌ Stores multiple values in one column
CREATE TABLE orders (
    id INTEGER PRIMARY KEY,
    customer TEXT,
    items TEXT  -- "apple, banana, cherry" ← BAD
);
```

**Good design:**
```sql
-- ✅ Normalized
CREATE TABLE orders (id INTEGER PRIMARY KEY, customer_id INTEGER);
CREATE TABLE order_items (order_id INTEGER, product_id INTEGER, quantity INTEGER);
```

---

## Exercises

### 6.1 — Design a Social Media Schema

Design a normalized database for a simple social media platform with the following requirements:

- Users have a username, email, bio, and join date
- Users can create **posts** with text content and a timestamp
- Users can **follow** other users
- Users can **like** posts
- Posts can have **comments** (also with text and timestamp)

**Your task:**
1. Write `CREATE TABLE` statements for all needed tables
2. Include appropriate primary keys, foreign keys, and constraints
3. Think about: what should be `NOT NULL`? What needs a `UNIQUE` constraint?

```sql
-- Write your schema here
-- Tip: Think about what the "entities" are first (nouns)
-- Users, Posts, Comments, Likes, Follows...
```

---

### 6.2 — Design a Movie Rental Schema

Design a schema for a video rental shop:

- Movies have a title, release year, rating (G/PG/PG-13/R), and genre
- Each movie has multiple copies (physical DVDs with a condition: good/fair/damaged)
- Customers have a name, email, and phone number
- Customers can **rent** copies (track rental date, due date, return date)
- Customers can **review** movies (1-5 star rating, text review)

**Requirements:**
1. Create all tables with proper keys and constraints
2. Make sure genres are their own table (not just a TEXT column)
3. Ensure `rating` only allows valid MPAA values using `CHECK`

---

### 6.3 — Design an E-Commerce Schema

Design a schema for an online store:

- Products have a name, description, price, and stock count
- Products belong to categories (which can have sub-categories)
- Customers can place orders containing multiple products
- Orders track status (`pending`, `shipped`, `delivered`, `cancelled`)
- Each order-product has a quantity and price at time of purchase

**Challenges:**
- How do you handle categories and sub-categories?
- Why should you store the price at time of purchase, not just reference the product price?

---

### 6.4 — Fix the Bad Schema

The following schema has several design problems. Find and fix them:

```sql
-- BROKEN SCHEMA — Fix all the problems!
CREATE TABLE student_data (
    info TEXT,                          -- Problem 1: ???
    name_and_email TEXT,                -- Problem 2: ???
    courses TEXT,                       -- Problem 3: ???
    gpa TEXT,                           -- Problem 4: ???
    teacher_name TEXT,                  -- Problem 5: ???
    teacher_salary TEXT                 -- Problem 6: ???
);
```

**Your task:**
1. Identify all 6+ problems
2. Write a corrected schema

---

### 6.5 — Seed Your Social Media Schema

Using the schema you created in 6.1, write `INSERT` statements to populate it with:

- At least 5 users
- At least 10 posts
- At least 5 follow relationships
- At least 10 likes
- At least 5 comments

Then write 3 queries to verify your data:
1. Who does user 1 follow?
2. What are the most liked posts?
3. Which user has posted the most?

---

## Design Checklist

Before submitting your schema, verify:

- [ ] Every table has a primary key
- [ ] Foreign keys reference valid tables
- [ ] No storing comma-separated lists in a single column
- [ ] Appropriate `NOT NULL` constraints
- [ ] Junction tables for many-to-many relationships (likes, follows, order_items)
- [ ] Text fields that should be constrained use `CHECK`
- [ ] No duplicated data that could get out of sync (3NF)
