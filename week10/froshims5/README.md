# froshims5 — SQLite Database Storage (Exercise)

## 🎯 Goal
Persist registrant data in a **SQLite database** using the `cs50` library.  
After registering, users are redirected to a `/registrants` page that reads from the database and lists everyone who signed up.

---

## 📚 New Concepts to Know

### 1. The cs50 SQL Library
`cs50.SQL` provides a simple way to run SQL queries against a SQLite database:

```python
from cs50 import SQL
db = SQL("sqlite:///froshims.db")
```

- The database file `froshims.db` will be created automatically if it doesn't exist (but the **table** must be created manually with a SQL command first).

### 2. Inserting Rows
```python
db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
```
- `?` are **placeholders** — cs50 safely substitutes the values to prevent SQL injection.

### 3. Selecting Rows
```python
registrants = db.execute("SELECT * FROM registrants")
```
- Returns a **list of dictionaries**, one per row. Each key is a column name.

### 4. `redirect()`
After a successful form submission it is best practice to **redirect** the user to another page (the POST → Redirect → GET pattern). This prevents re-submitting the form on refresh:

```python
from flask import redirect
return redirect("/registrants")
```

### 5. A Second Route for Viewing Data
```python
@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
```

### 6. Displaying a Table in Jinja2
```html
{% for registrant in registrants %}
    <tr>
        <td>{{ registrant["name"] }}</td>
        <td>{{ registrant["sport"] }}</td>
    </tr>
{% endfor %}
```

### 7. Creating the Database Table
Before running the app, create the table in SQLite:

```bash
sqlite3 froshims.db
```
```sql
CREATE TABLE registrants (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, sport TEXT);
```

---

## 📁 File Structure

```
froshims5/
├── app.py                  ← Flask app (routes + database logic)
├── froshims.db             ← SQLite database (you must create this)
├── requirements.txt
├── static/
└── templates/
    ├── layout.html
    ├── index.html          ← Registration form (radio buttons)
    ├── error.html          ← Error page with dynamic message
    └── registrants.html    ← Table of all registered students
```

---

## ✅ What You Need to Implement

### `app.py`
1. Import `SQL` from `cs50`, and `Flask`, `redirect`, `render_template`, `request` from `flask`.
2. Create the app and connect to `sqlite:///froshims.db`.
3. Define the `SPORTS` list.
4. `GET /` → render `index.html` with `sports=SPORTS`.
5. `POST /register` → validate name and sport (same as froshims3), then:
   - **Insert** the new registrant into the database.
   - **Redirect** to `/registrants`.
6. `GET /registrants` → query all registrants from the DB and render `registrants.html`.

### `templates/index.html`
- Same as froshims3 (radio buttons generated with a loop).

### `templates/registrants.html`
- Extend `layout.html`.
- Show an `<h1>Registrants</h1>` heading.
- Build an HTML `<table>` with headers: **Name**, **Sport**.
- Use a Jinja2 `for` loop to render one `<tr>` per registrant.

### `templates/error.html`
- Same as froshims3.

---

## 🚀 How to Run

```bash
# 1. Create the database table first
sqlite3 froshims.db "CREATE TABLE registrants (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, sport TEXT);"

# 2. Start Flask
flask run
```

---

## 💡 Tips
- Always use `?` placeholders in SQL — never format values directly into query strings.
- `redirect("/registrants")` sends the browser to a new URL; the browser then makes a fresh GET request.
- `db.execute("SELECT * FROM registrants")` returns a list of dicts — access columns like `registrant["name"]`.
