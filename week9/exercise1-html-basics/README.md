# Exercise 1 — HTML Basics 🏗️

> **Difficulty:** 🟢 Beginner  
> **Topics:** Semantic HTML, document structure, tags, attributes, accessibility

---

## 🎯 Learning Objectives

By the end of this exercise you will be able to:
- Write a valid, well-structured HTML document
- Use semantic elements (`<header>`, `<nav>`, `<main>`, `<article>`, `<footer>`)
- Add links, images, lists, and tables
- Understand the difference between block and inline elements
- Write accessible HTML using `alt` attributes and proper heading hierarchy

---

## 📋 Tasks

### Task 1 — Basic Document Structure
Open `index.html`. It's currently empty (or broken). Fix it so it has:
- A proper `<!DOCTYPE html>` declaration
- `<html>`, `<head>`, and `<body>` tags
- A `<title>` that shows in the browser tab
- A `<meta charset="UTF-8">` and viewport meta tag

### Task 2 — Semantic Sections
Inside `<body>`, build a personal profile page with:
- A `<header>` containing your name as an `<h1>` and a tagline as a `<p>`
- A `<nav>` with links to: About, Skills, Contact (they can link to `#about`, `#skills`, `#contact`)
- A `<main>` with three `<section>` elements, each with an `id` matching the nav links

### Task 3 — Content Elements
Fill each section with content:
- **About:** At least two paragraphs describing yourself (real or fictional)
- **Skills:** An unordered `<ul>` list of at least 5 skills, and a nested ordered `<ol>` list ranking your top 3
- **Contact:** A `<table>` with two columns — "Method" and "Address" — with at least 3 rows (email, GitHub, LinkedIn, etc.)

### Task 4 — Media
- Add an `<img>` to your header (use any placeholder: `https://placehold.co/150x150`)
- Add a `<figure>` and `<figcaption>` wrapping an image somewhere on the page
- Embed a YouTube video using an `<iframe>` (any video you like)

### Task 5 — Accessibility Check
- Every `<img>` must have a descriptive `alt` attribute
- Headings must be in logical order (don't skip from `h1` to `h4`)
- All links must have meaningful text (no "click here")

---

## 📁 Files

```
exercise1-html-basics/
├── README.md       ← You are here
├── index.html      ← Your work goes here
└── solution/
    └── index.html  ← Reference solution (try yourself first!)
```

---

## ✅ Done When...

- [ ] Page renders without errors
- [ ] All 5 tasks are complete
- [ ] Page has a clear visual structure (even without CSS)
- [ ] Validate at https://validator.w3.org/ — zero errors

---

## 💡 Hints

- Use `<!-- comments -->` to leave notes in your HTML
- The browser doesn't care about whitespace, but humans do — indent nested elements
- `<br>` forces a line break; `<hr>` draws a horizontal rule
- Want to see the page structure? Right-click → Inspect → Elements tab
