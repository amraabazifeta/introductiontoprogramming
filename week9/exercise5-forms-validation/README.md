# Exercise 5 — Forms & Validation 📝

> **Difficulty:** 🟡 Intermediate  
> **Topics:** HTML forms, input types, JavaScript validation, UX feedback

---

## 🎯 Learning Objectives

- Build a multi-field HTML form with proper input types and attributes
- Understand form events: `submit`, `input`, `change`, `blur`
- Implement client-side validation in JavaScript
- Display helpful error messages without using `alert()`
- Prevent form submission when data is invalid with `event.preventDefault()`
- Give visual feedback via CSS (`:valid`, `:invalid`, `.error`, `.success` classes)

---

## 📋 Tasks

### Task 1 — Build the Form
The `index.html` has placeholders. Fill in the `<form>` with these fields:
| Field | Input Type | Validation Required |
|---|---|---|
| Full Name | `text` | Required, 2+ chars |
| Email | `email` | Required, valid email format |
| Password | `password` | Required, 8+ chars, 1 number |
| Confirm Password | `password` | Must match Password |
| Age | `number` | Required, 18–120 |
| Website | `url` | Optional, must start with https:// |
| Country | `select` | Required, choose from a list |
| Bio | `textarea` | Optional, max 200 chars |
| Accept Terms | `checkbox` | Must be checked |

Each field needs:
- A `<label>` associated via `for`/`id`
- A `<span class="error-msg">` below it (for validation messages, starts empty)

### Task 2 — Real-Time Validation
In `script.js`, validate fields as the user types (`input` event) or leaves them (`blur` event):
- Show the error message span if the field is invalid
- Clear the error if the field becomes valid
- Add a `.valid` or `.invalid` CSS class to the input itself

### Task 3 — Submit Handler
On form `submit`:
1. Run all validations
2. If **any** field is invalid → `event.preventDefault()`, scroll to the first error
3. If **all** fields are valid → show a `#success-message` div, hide the form

### Task 4 — Password Strength Indicator
Below the password field, add a `#password-strength` bar that updates as the user types:
- Weak (< 8 chars): red, label "Weak"
- Fair (8+ chars): yellow, label "Fair"  
- Strong (8+ chars + number + uppercase): green, label "Strong"

### Task 5 — Character Counter
The `<textarea>` for Bio should show a live character count: "47 / 200 characters"
- Count updates on every `input` event
- Text turns red when the user exceeds 200 characters
- Disable the submit button when over the limit

---

## 📁 Files

```
exercise5-forms-validation/
├── README.md
├── index.html      ← Add form fields here
├── style.css       ← Provided base styles, add validation styles
├── script.js       ← Your validation logic goes here
└── solution/
    ├── index.html
    ├── style.css
    └── script.js
```

---

## ✅ Done When...

- [ ] All 9 form fields are present with correct input types
- [ ] Invalid fields show specific, helpful error messages
- [ ] Valid fields show a visual success indicator
- [ ] Submit is blocked when any field is invalid
- [ ] Success message appears after valid submission
- [ ] Password strength bar updates in real time
- [ ] Textarea character counter works and prevents over-limit submission

---

## 💡 Hints

- `event.preventDefault()` stops the browser's default form submission
- `/\d/.test(str)` checks if a string contains a digit
- `input.checkValidity()` returns `true/false` using HTML built-in validation
- Regex for email: `/^[^\s@]+@[^\s@]+\.[^\s@]+$/`
- Use `form.querySelector('.invalid')` to find the first invalid field and `.scrollIntoView()`
