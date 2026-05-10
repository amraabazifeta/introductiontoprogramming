# froshims3 — Specific Error Messages (Exercise)

## 🎯 Goal
Improve the user experience by showing **specific, descriptive error messages** instead of a generic failure page.  
You will also switch the form's sport input from a dropdown to **radio buttons** generated with a Jinja2 loop.

---

## 📚 New Concepts to Know

### 1. Specific Error Messages via a Template Variable
Instead of a plain `failure.html`, use a single `error.html` that accepts a `message` variable:

```python
return render_template("error.html", message="Missing name")
return render_template("error.html", message="Missing sport")
return render_template("error.html", message="Invalid sport")
```

Inside `error.html`, display it with:
```html
<p>{{ message }}</p>
```

### 2. Radio Buttons in HTML
Radio buttons let the user pick **one** option from a visible list.  
All radios in a group share the same `name` attribute:

```html
<input name="sport" type="radio" value="Basketball"> Basketball
```

Generate them dynamically with a Jinja2 loop:
```html
{% for sport in sports %}
    <input name="sport" type="radio" value="{{ sport }}"> {{ sport }}
{% endfor %}
```

### 3. Step-by-Step Validation
Validate each field separately and return a specific error immediately if it fails:

```python
name = request.form.get("name")
if not name:
    return render_template("error.html", message="Missing name")

sport = request.form.get("sport")
if not sport:
    return render_template("error.html", message="Missing sport")
if sport not in SPORTS:
    return render_template("error.html", message="Invalid sport")
```

### 4. Static Files
The `error.html` page displays an image from the `static/` folder using:
```html
<img alt="Grumpy Cat" src="/static/cat.jpg">
```
Flask automatically serves files placed in the `static/` directory.

---

## 📁 File Structure

```
froshims3/
├── app.py                  ← Flask app (routes, SPORTS list, validation with messages)
├── requirements.txt
├── static/                 ← Static assets (images, CSS, etc.)
└── templates/
    ├── layout.html         ← Base HTML layout
    ├── index.html          ← Registration form with radio buttons
    ├── error.html          ← Error page that displays a dynamic message
    └── success.html        ← Shown on successful registration
```

---

## ✅ What You Need to Implement

### `app.py`
1. Import Flask, `render_template`, and `request`.
2. Create the app instance and define the `SPORTS` list.
3. `GET /` → render `index.html` with `sports=SPORTS`.
4. `POST /register` → validate step by step:
   - If `name` is missing → `render_template("error.html", message="Missing name")`.
   - If `sport` is missing → `render_template("error.html", message="Missing sport")`.
   - If `sport` is not in `SPORTS` → `render_template("error.html", message="Invalid sport")`.
   - If all valid → render `success.html`.

### `templates/index.html`
- Extend `layout.html`.
- Form posts to `/register`.
- Text input for `name`.
- Use a **Jinja2 for loop** to render one **radio button** per sport (all with `name="sport"`).
- Submit button.

### `templates/error.html`
- Extend `layout.html`.
- Show an `<h1>Error</h1>` heading.
- Display the dynamic `{{ message }}` in a `<p>` tag.
- Show an image from `/static/` (e.g. a grumpy cat image).

### `templates/success.html`
- Extend `layout.html`.
- Display a success message.

### `templates/layout.html`
- Standard base HTML with a `{% block body %}{% endblock %}`.

---

## 🚀 How to Run

```bash
flask run
```

Then open [http://127.0.0.1:5000](http://127.0.0.1:5000).

---

## 💡 Tips
- Radio buttons always send **one** value under the shared `name` — `request.form.get("sport")` works exactly as before.
- The `message` variable in `error.html` must match what you pass in `render_template(...)`.
- Put any image you want to use in the `static/` folder and reference it as `/static/filename`.
