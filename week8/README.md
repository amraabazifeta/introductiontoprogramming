# 🗄️ Week 8 — SQL

> **CS50-style SQL exercises** covering everything from basic queries to advanced database design.

---

## 📚 Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Setup](#setup)
- [Exercise Structure](#exercise-structure)
- [Topics Covered](#topics-covered)
- [How to Use](#how-to-use)
- [Exercises](#exercises)
- [Resources](#resources)

---

## Overview

This week focuses on **SQL (Structured Query Language)** — the language used to communicate with relational databases. You'll learn how to create, read, update, and delete data, as well as how to design schemas and write complex queries.

By the end of this week, you'll be able to:

- Write `SELECT`, `INSERT`, `UPDATE`, and `DELETE` statements
- Filter and sort data using `WHERE`, `ORDER BY`, and `LIMIT`
- Combine tables using `JOIN`
- Aggregate data using `GROUP BY`, `COUNT`, `SUM`, `AVG`
- Write subqueries and nested queries
- Design normalized database schemas
- Create indexes and understand query optimization

---

## Prerequisites

- Basic understanding of programming concepts (variables, loops, conditions)
- Familiarity with Python (optional, some exercises use Python + SQLite)
- Completion of Weeks 0–7 is helpful but not required

---

## Setup

### Option 1: SQLite (Recommended — No Installation Needed on Most Systems)

```bash
# Check if SQLite is installed
sqlite3 --version

# If not installed, on Ubuntu/Debian:
sudo apt install sqlite3

# On macOS (with Homebrew):
brew install sqlite
```

### Option 2: Use CS50's Online IDE

Visit [cs50.dev](https://cs50.dev) and open a terminal. SQLite is pre-installed.

### Option 3: DB Browser for SQLite (GUI)

Download from [sqlitebrowser.org](https://sqlitebrowser.org) for a visual interface.

---

### Loading the Practice Databases

```bash
# Clone this repository
git clone https://github.com/your-username/week8-sql.git
cd week8-sql

# Load a database
sqlite3 data/movies.db < data/movies.sql
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql
```

---

## Exercise Structure

Each exercise folder contains:

```
exercises/
├── 01-basics/
│   ├── README.md        ← Instructions & hints
│   └── exercise.sql     ← Starter file (write your answers here)
solutions/
├── 01-basics/
│   └── solution.sql     ← Reference solutions (try first before peeking!)
```

---

## Topics Covered

| # | Topic | Concepts |
|---|-------|----------|
| 01 | [SQL Basics](#01-sql-basics) | `SELECT`, `FROM`, `WHERE`, `LIMIT` |
| 02 | [Querying Data](#02-querying-data) | `ORDER BY`, `LIKE`, `NULL`, `DISTINCT` |
| 03 | [Joins](#03-joins) | `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN` |
| 04 | [Aggregates](#04-aggregates) | `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`, `GROUP BY`, `HAVING` |
| 05 | [Subqueries](#05-subqueries) | Nested `SELECT`, `IN`, `EXISTS` |
| 06 | [Database Design](#06-database-design) | Schema design, normalization, foreign keys |
| 07 | [Advanced SQL](#07-advanced-sql) | Indexes, transactions, `CREATE VIEW` |

---

## How to Use

1. **Read** the exercise `README.md` carefully
2. **Write** your SQL in `exercise.sql`
3. **Test** your queries against the provided database
4. **Check** the solution only after you've tried for at least 10 minutes
5. **Reflect** — can you write it a different way?

### Running Your Queries

```bash
# Run a single SQL file against a database
sqlite3 data/movies.db < exercises/01-basics/exercise.sql

# Open interactive mode
sqlite3 data/movies.db

# Inside SQLite interactive mode:
sqlite> .tables          -- list all tables
sqlite> .schema movies   -- show table structure
sqlite> .mode column     -- pretty column output
sqlite> .headers on      -- show column headers
sqlite> .quit            -- exit
```

---

## Exercises

### 01 — SQL Basics
📁 [`exercises/01-basics/`](exercises/01-basics/)

Introduction to `SELECT` statements. Learn to retrieve columns and rows from a table.

**Skills:** `SELECT`, `FROM`, `WHERE`, `LIMIT`, `BETWEEN`

---

### 02 — Querying Data
📁 [`exercises/02-queries/`](exercises/02-queries/)

Go deeper with filtering, sorting, and searching text patterns.

**Skills:** `ORDER BY`, `LIKE`, `IS NULL`, `DISTINCT`, `IN`

---

### 03 — Joins
📁 [`exercises/03-joins/`](exercises/03-joins/)

Combine data from multiple tables to answer complex questions.

**Skills:** `INNER JOIN`, `LEFT JOIN`, multiple joins, table aliases

---

### 04 — Aggregates
📁 [`exercises/04-aggregates/`](exercises/04-aggregates/)

Summarize and group data to find trends and statistics.

**Skills:** `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`, `GROUP BY`, `HAVING`

---

### 05 — Subqueries
📁 [`exercises/05-subqueries/`](exercises/05-subqueries/)

Use queries within queries for powerful multi-step logic.

**Skills:** Nested `SELECT`, `IN`, `NOT IN`, `EXISTS`, correlated subqueries

---

### 06 — Database Design
📁 [`exercises/06-design/`](exercises/06-design/)

Design your own database schema from scratch using real-world requirements.

**Skills:** `CREATE TABLE`, `PRIMARY KEY`, `FOREIGN KEY`, normalization, ER diagrams

---

### 07 — Advanced SQL
📁 [`exercises/07-advanced/`](exercises/07-advanced/)

Optimize queries and learn professional-grade SQL features.

**Skills:** `CREATE INDEX`, `CREATE VIEW`, `BEGIN TRANSACTION`, `EXPLAIN QUERY PLAN`

---

## Resources

- 📖 [CS50's SQL Notes](https://cs50.harvard.edu/x/2024/notes/7/)
- 🎥 [CS50 Week 7 Lecture](https://youtu.be/zrCLRC3Ci1c)
- 📘 [SQLite Documentation](https://www.sqlite.org/docs.html)
- 🛠️ [SQL Cheat Sheet](https://www.sqlite.org/lang.html)
- 🎯 [SQLZoo Practice](https://sqlzoo.net)
- 📊 [DB Diagram Tool](https://dbdiagram.io)

---

## Grading Rubric (Self-Assessment)

| Criteria | Points |
|----------|--------|
| Query returns correct results | 40% |
| Query is efficient (no unnecessary complexity) | 20% |
| Proper use of SQL conventions (uppercase keywords) | 10% |
| Code is readable and well-formatted | 30% |

---

## Academic Honesty

This is a learning resource. You are encouraged to:
- ✅ Look up documentation
- ✅ Discuss concepts with peers
- ✅ Peek at solutions **after** genuine effort

Please do not:
- ❌ Copy solutions without understanding them
- ❌ Submit these as your own work for graded assignments

---

*Happy querying! 🎉*
