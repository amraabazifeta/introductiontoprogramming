# froshims1 — Server-Side Sport Validation (Exercise)

## 🎯 Goal
Build on froshims0 by introducing **server-side validation** of the sport field.  
Instead of blindly trusting whatever the browser sends, your Python code will check that the submitted sport is one of the allowed options.

---

## 📚 New Concepts to Know

### 1. Python List as a Source of Truth
Define your valid sports in a Python list at the top of `app.py`:

```python
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]
```

This list is used in **two** places:
- Passed to the template to build the dropdown dynamically.
- Checked in the `/register` route to validate the submitted value.

### 2. Passing Data to Templates
`render_template` can pass variables to a template as keyword arguments:

```python
return render_template("index.html", sports=SPORTS)
```

Inside the template, `sports` is now available as a Jinja2 variable.

### 3. Jinja2 `for` Loop
Loop over a list in a template to generate HTML dynamically:

```html
{% for sport in sports %}
    <option value="{{ sport }}">{{ sport }}</option>
{% endfor %}
```

### 4. Validating Against a List
In Python, use the `in` operator to check membership:

```python
if request.form.get("sport") not in SPORTS:
    # invalid sport
```

This prevents users from submitting arbitrary values that bypass the dropdown.

---

## 📁 File Structure

```
froshims1/
├── app.py                  ← Flask app (routes, SPORTS list, validation)
├── requirements.txt        ← Python dependencies
└── templates/
    ├── layout.html         ← Base HTML layout
    ├── index.html          ← Registration form (sport dropdown built from SPORTS)
    ├── success.html        ← Shown on successful registration
    └── failure.html        ← Shown when validation fails
```

---

## ✅ What You Need to Implement

### `app.py`
1. Import Flask, `render_template`, and `request`.
2. Create the Flask app instance.
3. Define a `SPORTS` list with at least 3 sport names.
4. Define a `GET /` route that renders `index.html`, passing `sports=SPORTS`.
5. Define a `POST /register` route that:
   - Validates that `name` is not empty.
   - Validates that `sport` is **in** the `SPORTS` list (reject anything else).
   - Renders `failure.html` if validation fails.
   - Renders `success.html` if everything is valid.

### `templates/index.html`
- Extend `layout.html`.
- Create a form posting to `/register`.
- Add a text input for `name`.
- Add a `<select>` dropdown for `sport`:
  - First option is an empty default (`value=""`).
  - Use a **Jinja2 for loop** to generate one `<option>` per sport from the `sports` variable.
- Add a submit button.

### `templates/layout.html`, `success.html`, `failure.html`
- Same as froshims0 — refer to that README if needed.

---

## 🚀 How to Run

```bash
flask run
```

Then open [http://127.0.0.1:5000](http://127.0.0.1:5000).

---

## 💡 Tips
- The key difference from froshims0: here you **validate the sport value against the list** using `not in SPORTS`, not just check if it's empty.
- Building the dropdown with a loop means adding a new sport to `SPORTS` automatically updates the form — no need to touch the HTML.
