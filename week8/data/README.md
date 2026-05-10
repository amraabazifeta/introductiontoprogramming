# Data Files

This folder contains SQL scripts to create and populate practice databases.

## Databases

### `school.db` — Generated from `school.sql`

A university database with:
- `departments` — Academic departments (CS, Math, English…)
- `teachers` — 10 instructors with salaries and department
- `students` — 20 students with GPA and enrollment year
- `courses` — 14 courses with credits, capacity, teacher, department
- `enrollments` — Which students are in which courses
- `grades` — Midterm, final, assignment scores, and letter grades

### `library.db` — Generated from `library.sql`

A public library database with:
- `genres` — Book genres
- `authors` — 14 authors with nationality and birth year
- `books` — 20 books with copies, ISBN, and genre
- `book_authors` — Many-to-many link between books and authors
- `members` — 10 library members with membership type
- `loans` — Checkout records with fine tracking

## Setup

```bash
# Create the databases (run from the repo root)
sqlite3 data/school.db < data/school.sql
sqlite3 data/library.db < data/library.sql

# Verify
sqlite3 data/school.db ".tables"
sqlite3 data/library.db ".tables"
```

## Schema Diagrams

### school.db

```
departments ──< teachers ──< courses >──< enrollments >──< students
                                              │
                                           grades
```

### library.db

```
genres ──< books >──< book_authors >──< authors
              │
           loans ──< members
```
