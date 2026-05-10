# Exercise 4 — JavaScript & the DOM ⚡

> **Difficulty:** 🟡 Intermediate  
> **Topics:** DOM manipulation, event listeners, querySelector, createElement

---

## 🎯 Learning Objectives

- Select elements with `document.querySelector()` and `querySelectorAll()`
- Listen for events with `addEventListener()`
- Read and modify element content (`textContent`, `innerHTML`, `value`)
- Add, remove, and toggle CSS classes
- Create and insert new DOM elements dynamically
- Understand the event object (`event.target`, `event.preventDefault()`)

---

## 📋 Tasks

### Task 1 — Console Warmup
Open `script.js`. The first section has small practice challenges. Complete each one using the browser console or directly in the script:
- Select the `<h1>` and change its text
- Select all `.card` elements and log how many there are
- Change the background color of `#target-box` using JS

### Task 2 — Click Counter
Find the `#counter-section`. Make the buttons work:
- **Increment (+)** button: increases the displayed count by 1
- **Decrement (−)** button: decreases the count by 1, but **never below 0**
- **Reset** button: sets the count back to 0
- The count display should turn **red** when it's 0, **green** when above 5

### Task 3 — Dynamic List Builder
Find the `#list-section`. Make the "Add Item" button work:
- Read the value from the `<input>` field
- If the input is empty, show an alert or shake the input — don't add a blank item
- Create a new `<li>` element with the input text
- Append it to the `<ul>`
- After adding, clear the input and give it focus
- Each list item should have a **delete (×) button** that removes that item when clicked

### Task 4 — Show/Hide Toggle
Find the `#toggle-section`. The "Toggle Details" button should:
- Show a hidden `<div class="details">` if it's currently hidden
- Hide it if it's currently shown
- **Bonus:** Change the button text between "Show Details" and "Hide Details"
- Use `classList.toggle()` rather than directly setting `style.display`

### Task 5 — Color Mixer
Find the `#color-section`. Three range inputs control Red, Green, Blue values (0–255).
- When any slider changes, read all three values
- Update the `#color-preview` box's background color using `rgb(r, g, b)`
- Display the current hex color code in `#hex-display`

> **Hint:** To convert a decimal 0–255 to hex: `value.toString(16).padStart(2, '0')`

---

## 📁 Files

```
exercise4-javascript-dom/
├── README.md
├── index.html      ← Provided
├── style.css       ← Provided (minimal)
├── script.js       ← Your work goes here
└── solution/
    ├── index.html
    ├── style.css
    └── script.js
```

---

## ✅ Done When...

- [ ] All console warmup tasks complete
- [ ] Counter increments, decrements (not below 0), resets, and changes color
- [ ] List builder adds items, rejects empty input, and delete works
- [ ] Toggle button shows/hides content and updates its label
- [ ] Color mixer updates preview and hex code in real time

---

## 💡 Hints

- `document.querySelector('#id')` selects one element; `.querySelectorAll('.class')` selects all
- `element.textContent = 'new text'` changes text safely (no HTML injection risk)
- `element.classList.add('class')`, `.remove()`, `.toggle()`, `.contains()`
- `input.value` reads the current text in an `<input>`
- `element.addEventListener('click', function(event) { ... })`
- To add a new element: `const li = document.createElement('li'); ul.appendChild(li);`
