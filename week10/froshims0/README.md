# froshims0 — Flask Registration Form (Exercise)

## 🎯 Goal
Build a simple sports registration web app using Flask and Jinja2 templates.  
The app should show a registration form, validate the input on the server side, and display a success or failure page.

---

## 📚 Concepts You Need to Know

### 1. Flask Basics
- **Flask** is a lightweight Python web framework.
- You create an app instance with `app = Flask(__name__)`.
- Routes are defined using the `@app.route()` decorator.
- Run the app with `flask run` in the terminal (make sure `FLASK_APP=app.py` is set, or just name the file `app.py`).

### 2. Routes & HTTP Methods
- A **route** maps a URL path to a Python function.
- By default, routes only accept `GET` requests.
- To accept form submissions, add `methods=["POST"]` to the route.

```python
@app.route("/register", methods=["POST"])
def register():
    ...
```

### 3. Handling Form Data
- When a form is submitted via POST, Flask stores the data in `request.form`.
- Access a field by its `name` attribute: `request.form.get("name")`.
- If the field is empty or missing, `.get()` returns `None` or an empty string `""`.

### 4. Rendering Templates
- Use `render_template("filename.html")` to return an HTML page.
- Templates live in the `templates/` folder.
- Import it at the top: `from flask import Flask, render_template, request`.

### 5. Jinja2 Templates
- Templates can **extend** a base layout using `{% extends "layout.html" %}`.
- Fill in sections using **blocks**:

```html
{% block body %}
    <!-- your content here -->
{% endblock %}
```

- The base layout defines `{% block body %}{% endblock %}` as a placeholder.

### 6. HTML Forms
- Use `<form action="/register" method="post">` to send data to your `/register` route.
- Use `<input>` for text fields and `<select>` / `<option>` for dropdown menus.
- Every field needs a `name` attribute — this is how Flask identifies it.
- Add a `<button type="submit">` to submit the form.

---

## 📁 File Structure

```
froshims0/
├── app.py                  ← Flask app (routes & logic)
├── requirements.txt        ← Python dependencies
└── templates/
    ├── layout.html         ← Base HTML layout
    ├── index.html          ← Registration form page
    ├── success.html        ← Shown when registration succeeds
    └── failure.html        ← Shown when validation fails
```

---

## ✅ What You Need to Implement

### `app.py`
1. Import Flask, `render_template`, and `request`.
2. Create the Flask app instance.
3. Define a `GET` route for `/` that renders `index.html`.
4. Define a `POST` route for `/register` that:
   - Reads `name` and `sport` from the submitted form.
   - If either field is missing/empty → render `failure.html`.
   - Otherwise → render `success.html`.

### `templates/layout.html`
- A standard HTML page (`<!DOCTYPE html>`, `<html>`, `<head>`, `<body>`).
- Inside `<body>`, add a Jinja2 block: `{% block body %}{% endblock %}`.

### `templates/index.html`
- Extend `layout.html`.
- Inside the body block, create an HTML `<form>` that:
  - Posts to `/register`.
  - Has a text `<input>` for the student's **name**.
  - Has a `<select>` dropdown for **sport** with at least 3 sport options.
  - Has a submit button.

### `templates/success.html`
- Extend `layout.html`.
- Display a short message like **"You are registered!"**.

### `templates/failure.html`
- Extend `layout.html`.
- Display a short message like **"You are not registered!"**.

---

## 🚀 How to Run

```bash
# From inside the froshims0/ folder:
flask run
```

Then open your browser at [http://127.0.0.1:5000](http://127.0.0.1:5000).

---

## 💡 Tips
- Make sure each `<input>` and `<select>` has a `name` attribute that matches what your Python code reads with `request.form.get(...)`.
- The empty `<option value="">Sport</option>` as the default ensures the field is considered blank if the user doesn't choose a sport.
- Server-side validation (checking in Python) is important — never rely only on the browser.
