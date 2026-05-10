# Week 10 — Flask Exercises

Welcome! This repository contains a series of progressively more complex Flask web applications.  
Each folder is a **standalone exercise**. You will work through them in order, learning one new concept at a time.

---

## 📋 Table of Contents

1. [Prerequisites](#prerequisites)
2. [How to Set Up](#how-to-set-up)
3. [How to Run Any Exercise](#how-to-run-any-exercise)
4. [Repository Structure](#repository-structure)
5. [Exercise Roadmap](#exercise-roadmap)
   - [Series 1 — Hello (hello0 → hello10)](#series-1--hello)
   - [Series 2 — Froshims (froshims0 → froshims7)](#series-2--froshims)
   - [Series 3 — Shows (shows0 → shows3)](#series-3--shows)
   - [Series 4 — Login & Store](#series-4--login--store)
6. [Core Flask Concepts Reference](#core-flask-concepts-reference)
7. [Jinja2 Template Reference](#jinja2-template-reference)
8. [SQLite & cs50 SQL Reference](#sqlite--cs50-sql-reference)
9. [Common Errors & Fixes](#common-errors--fixes)

---

## Prerequisites

Make sure you have the following installed:

- **Python 3.10+** — check with `python3 --version`
- **pip** — comes with Python
- A terminal (zsh / bash / PowerShell)

---

## How to Set Up

A virtual environment (`.venv`) is already included in this repo.  
**Activate it once** at the start of every work session:

```bash
# From the root of this repo:
source .venv/bin/activate
```

You should see `(.venv)` appear at the start of your terminal prompt.  
All required packages (`flask`, `cs50`, `flask-session`, etc.) are already installed inside it.

> If you ever need to install packages manually:
> ```bash
> pip install -r <exercise_folder>/requirements.txt
> ```

---

## How to Run Any Exercise

1. **Activate the virtual environment** (if not already active):
   ```bash
   source .venv/bin/activate
   ```

2. **`cd` into the exercise folder**:
   ```bash
   cd hello0
   ```

3. **Run Flask**:
   ```bash
   flask run
   ```

4. Open your browser at **[http://127.0.0.1:5000](http://127.0.0.1:5000)**

5. To stop the server, press **Ctrl + C** in the terminal.

> **Important:** Always `cd` into the exercise folder before running `flask run`.  
> Flask looks for `app.py` in the **current directory**.

### Exercises that use a database

Some exercises (`froshims5`, `froshims6`, `froshims7`, `shows0`–`shows3`, `store`) require a SQLite database.  
You must create the table(s) before running Flask for the first time:

```bash
# Example for froshims5 / froshims6 / froshims7:
sqlite3 froshims.db "CREATE TABLE registrants (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, sport TEXT);"
```

Each exercise's own `README.md` (where present) will tell you the exact command to run.

---

## Repository Structure

```
week10_flask_exercises/
│
├── README.md               ← You are here (master guide)
│
├── hello0/                 ← Series 1: Hello World progression
├── hello1/
├── ...
├── hello10/
│
├── froshims0/              ← Series 2: Registration form progression
├── froshims1/
├── ...
├── froshims7/
│
├── shows0/                 ← Series 3: TV show search progression
├── shows1/
├── shows2/
├── shows3/
│
├── login/                  ← Series 4: Session-based login
└── store/                  ← Series 4: Shopping cart with sessions
```

Every exercise folder follows the same layout:

```
<exercise>/
├── app.py              ← Flask application (routes + logic)
├── requirements.txt    ← Python dependencies for this exercise
├── README.md           ← Exercise-specific guide (where provided)
├── static/             ← CSS, images, JS (not in every exercise)
└── templates/
    ├── layout.html     ← Base HTML template (extended by others)
    ├── index.html      ← Main page
    └── ...             ← Other pages (greet, success, error, etc.)
```

---

## Exercise Roadmap

### Series 1 — Hello

Learn the absolute basics of Flask step by step.

| Folder | What you learn |
|--------|---------------|
| `hello0` | Return a plain text string from a route |
| `hello1` | Return a string of HTML from a route |
| `hello2` | Render an HTML template with `render_template` |
| `hello3` | Read a query-string parameter with `request.args` |
| `hello4` | Use a URL variable `/<name>` in a route |
| `hello5` | Use `request.args.get()` with a default value |
| `hello6` | Add a second route; submit a form via GET |
| `hello7` | Add a `layout.html` base template with `{% extends %}` |
| `hello8` | Switch the form to POST; use `request.form` |
| `hello9` | Combine GET and POST into a single route |
| `hello10` | Move the default value into the template |

---

### Series 2 — Froshims

Build a sports registration form, adding one feature per step.

| Folder | What you learn |
|--------|---------------|
| `froshims0` ⭐ | Basic form → validate name & sport → success/failure page |
| `froshims1` ⭐ | Add a `SPORTS` list; validate sport with `not in`; dynamic dropdown |
| `froshims2` | Switch from dropdown to radio buttons |
| `froshims3` ⭐ | Show specific error messages via `error.html` + `{{ message }}` |
| `froshims4` | Store registrants in a Python **dictionary** (in-memory) |
| `froshims5` ⭐ | Store registrants in a **SQLite database**; redirect to `/registrants` |
| `froshims6` | Add a **deregister** button (single sport per registrant) |
| `froshims7` ⭐ | Support **multiple sports** with checkboxes + `getlist()`; deregister |

> ⭐ = exercises that have a dedicated `README.md` with full instructions

---

### Series 3 — Shows

Search a TV-shows database, improving the search with each step.

| Folder | What you learn |
|--------|---------------|
| `shows0` | Exact-match search (`WHERE title = ?`) |
| `shows1` | Partial-match search with `LIKE` and `%` wildcards |
| `shows2` | Live search with **AJAX** (JavaScript `fetch` + JSON) |
| `shows3` | Add a result **limit** and return JSON with `jsonify` |

---

### Series 4 — Login & Store

| Folder | What you learn |
|--------|---------------|
| `login` | Server-side **sessions** with `flask-session`; login / logout |
| `store` | **Shopping cart** stored in a session; database-backed product list |

---

## Core Flask Concepts Reference

### Creating an App

```python
from flask import Flask
app = Flask(__name__)
```

### Defining Routes

```python
# GET only (default)
@app.route("/")
def index():
    return "Hello, world"

# POST only
@app.route("/register", methods=["POST"])
def register():
    ...

# Both GET and POST
@app.route("/form", methods=["GET", "POST"])
def form():
    if request.method == "POST":
        ...
    return render_template("form.html")
```

### Reading Form & Query Data

```python
from flask import request

# Query string:  /search?q=hello
value = request.args.get("q")           # None if missing
value = request.args.get("q", "world")  # "world" as default

# Form (POST body)
value = request.form.get("name")        # single value
values = request.form.getlist("sport")  # multiple checkboxes → list
```

### Rendering Templates

```python
from flask import render_template
return render_template("index.html")                    # no variables
return render_template("index.html", name="Alice")      # pass a variable
return render_template("error.html", message="Oops!")   # pass a message
```

### Redirecting

```python
from flask import redirect
return redirect("/")
return redirect("/registrants")
```

### Returning JSON (for AJAX)

```python
from flask import jsonify
return jsonify([{"title": "Breaking Bad"}, {"title": "Fargo"}])
```

### Sessions

```python
from flask import session
from flask_session import Session

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

session["name"] = "Alice"      # store
name = session.get("name")     # read (None if not set)
session.clear()                # clear all session data
```

---

## Jinja2 Template Reference

### Extending a Layout

```html
<!-- layout.html -->
<!DOCTYPE html>
<html lang="en">
  <head><title>My App</title></head>
  <body>
    {% block body %}{% endblock %}
  </body>
</html>
```

```html
<!-- index.html -->
{% extends "layout.html" %}

{% block body %}
    <h1>Hello!</h1>
{% endblock %}
```

### Outputting Variables

```html
<p>Hello, {{ name }}!</p>
<p>{{ message }}</p>
```

### Conditionals

```html
{% if name %}
    <p>Hello, {{ name }}!</p>
{% else %}
    <p>Hello, world!</p>
{% endif %}
```

### Loops

```html
<!-- Loop over a list -->
{% for sport in sports %}
    <p>{{ sport }}</p>
{% endfor %}

<!-- Loop over database rows -->
{% for row in registrants %}
    <tr>
        <td>{{ row["name"] }}</td>
        <td>{{ row["sport"] }}</td>
    </tr>
{% endfor %}
```

### Common HTML Patterns

```html
<!-- Text input -->
<input name="name" type="text" placeholder="Name" autocomplete="off">

<!-- Dropdown (select) -->
<select name="sport">
    <option value="">Choose a sport</option>
    {% for sport in sports %}
        <option value="{{ sport }}">{{ sport }}</option>
    {% endfor %}
</select>

<!-- Radio buttons (pick one) -->
{% for sport in sports %}
    <input name="sport" type="radio" value="{{ sport }}"> {{ sport }}
{% endfor %}

<!-- Checkboxes (pick many) -->
{% for sport in sports %}
    <input name="sport" type="checkbox" value="{{ sport }}"> {{ sport }}
{% endfor %}

<!-- Hidden field (pass data invisibly) -->
<input name="id" type="hidden" value="{{ row.id }}">

<!-- Submit button -->
<button type="submit">Register</button>
```

---

## SQLite & cs50 SQL Reference

### Connecting

```python
from cs50 import SQL
db = SQL("sqlite:///mydb.db")
```

### Creating a Table (run once in terminal)

```bash
sqlite3 mydb.db
```
```sql
CREATE TABLE registrants (
    id    INTEGER PRIMARY KEY AUTOINCREMENT,
    name  TEXT NOT NULL,
    sport TEXT NOT NULL
);
```

Or as a one-liner:
```bash
sqlite3 mydb.db "CREATE TABLE registrants (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, sport TEXT);"
```

### Common Queries

```python
# SELECT — returns a list of dicts
rows = db.execute("SELECT * FROM registrants")
rows = db.execute("SELECT * FROM shows WHERE title LIKE ?", "%" + q + "%")

# INSERT
db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

# DELETE
db.execute("DELETE FROM registrants WHERE id = ?", id)

# UPDATE
db.execute("UPDATE registrants SET sport = ? WHERE id = ?", sport, id)
```

> Always use `?` placeholders — **never** put variables directly in query strings.

### Reading Results

```python
rows = db.execute("SELECT * FROM registrants")
# rows is a list of dicts:
# [{"id": 1, "name": "Alice", "sport": "Soccer"}, ...]

for row in rows:
    print(row["name"], row["sport"])
```

---

## Common Errors & Fixes

| Error | Likely Cause | Fix |
|-------|-------------|-----|
| `Address already in use` | Another `flask run` is still running | Press Ctrl+C in the other terminal |
| `No module named 'flask'` | Virtual environment not active | Run `source .venv/bin/activate` |
| `TemplateNotFound` | Template file missing or wrong name | Check `templates/` folder and spelling |
| `KeyError` / `None` from form | `name` attribute missing on `<input>` | Add `name="..."` to every form field |
| `OperationalError: no such table` | Database table not created yet | Run the `sqlite3` CREATE TABLE command |
| `werkzeug.routing.BuildError` | Wrong route name or URL in a form `action` | Check `action="/route"` matches `@app.route("/route")` |
| Page doesn't update after form submit | Missing `redirect()` after POST | Return `redirect("/page")` instead of `render_template` |

---

## Quick Cheat Sheet

```
Activate venv      →  source .venv/bin/activate
Run an exercise    →  cd <folder> && flask run
Stop Flask         →  Ctrl + C
Open SQLite shell  →  sqlite3 <file>.db
Exit SQLite shell  →  .quit
List DB tables     →  .tables
See table schema   →  .schema <tablename>
```

Happy coding! 🚀
