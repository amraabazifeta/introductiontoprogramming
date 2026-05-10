# froshims7 — Multiple Sports & Deregistration (Exercise)

## 🎯 Goal
Extend the registration app to support **selecting multiple sports** (checkboxes) and add a **deregister** button next to each registrant so they can be removed from the database.

---

## 📚 New Concepts to Know

### 1. Checkboxes — Selecting Multiple Values
Unlike radio buttons (one choice), checkboxes allow **multiple selections**.  
All checkboxes in a group share the same `name`:

```html
{% for sport in sports %}
    <input name="sport" type="checkbox" value="{{ sport }}"> {{ sport }}
{% endfor %}
```

### 2. `request.form.getlist()`
When multiple checkboxes with the same name are submitted, use `.getlist()` instead of `.get()` to retrieve **all selected values** as a Python list:

```python
sports = request.form.getlist("sport")
# e.g. ["Basketball", "Soccer"]
```

- If no checkbox is checked, `getlist` returns an empty list `[]`.

### 3. Inserting Multiple Rows
Each selected sport gets its own row in the database (one row per registrant + sport):

```python
for sport in sports:
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
```

### 4. Validating a List
```python
sports = request.form.getlist("sport")
if not sports:
    return render_template("error.html", message="Missing sport")
for sport in sports:
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")
```

### 5. Deregistration — Deleting a Row by ID
Each row in the database has a unique `id`. A hidden form input sends that ID to a `/deregister` route:

```html
<form action="/deregister" method="post">
    <input name="id" type="hidden" value="{{ registrant.id }}">
    <button type="submit">Deregister</button>
</form>
```

In Python:
```python
@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")
```

### 6. Hidden Inputs
`<input type="hidden">` is invisible to the user but is included in the form submission. It's used to pass data (like a database ID) that the user shouldn't type manually.

---

## 📁 File Structure

```
froshims7/
├── app.py                  ← Flask app (register, deregister, registrants routes)
├── froshims.db             ← SQLite database
├── requirements.txt
├── static/
└── templates/
    ├── layout.html
    ├── index.html          ← Form with checkboxes for multiple sports
    ├── error.html          ← Error page with dynamic message
    └── registrants.html    ← Table with a Deregister button per row
```

---

## ✅ What You Need to Implement

### `app.py`
1. Import `SQL` from `cs50`, and `Flask`, `redirect`, `render_template`, `request` from `flask`.
2. Create the app, connect to the database, define `SPORTS`.
3. `GET /` → render `index.html` with `sports=SPORTS`.
4. `POST /deregister` →
   - Get `id` from the form.
   - If `id` exists, `DELETE` that row from the database.
   - Redirect to `/registrants`.
5. `POST /register` → validate name and sports list (using `getlist`), insert **one row per sport**, redirect to `/registrants`.
6. `GET /registrants` → query all registrants, render `registrants.html`.

### `templates/index.html`
- Extend `layout.html`.
- Form posts to `/register`.
- Text input for `name`.
- Use a Jinja2 loop to render **checkboxes** (not radio buttons) for each sport.
- Submit button.

### `templates/registrants.html`
- Extend `layout.html`.
- HTML table with headers: **Name**, **Sport**, and an empty header for the button column.
- For each registrant, show a row with:
  - Name, Sport.
  - A small `<form>` with a **hidden input** carrying `registrant.id` and a **Deregister** submit button.

### `templates/error.html`
- Same as froshims3/5.

---

## 🚀 How to Run

```bash
sqlite3 froshims.db "CREATE TABLE registrants (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, sport TEXT);"
flask run
```

---

## 💡 Tips
- Use `request.form.getlist("sport")` — not `.get()` — when handling checkboxes.
- Each sport a student selects creates a **separate row** in the database.
- The hidden `id` input is what tells the server **which row** to delete on deregistration.
- A student registered for 3 sports will appear as **3 rows** in the table, each with its own Deregister button.
