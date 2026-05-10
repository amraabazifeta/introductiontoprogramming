# Exercise 3 — Responsive Design 📱

> **Difficulty:** 🟡 Intermediate  
> **Topics:** Flexbox, CSS Grid, media queries, mobile-first design

---

## 🎯 Learning Objectives

- Build layouts using **Flexbox** and **CSS Grid**
- Write **mobile-first CSS** with `min-width` media queries
- Create a **responsive navigation** that works on small and large screens
- Build a **responsive photo grid** that adapts to screen size
- Understand **viewport units** (`vw`, `vh`) and responsive typography

---

## 📋 Tasks

### Task 1 — Mobile-First Reset
Start `style.css` with a mobile-first approach:
- Base styles should target small screens (< 600px)
- Use `min-width` media queries to progressively enhance for larger screens
- Define breakpoints for: `600px` (tablet), `900px` (desktop), `1200px` (wide)

### Task 2 — Responsive Navigation
The `<nav>` should:
- On **mobile**: stack vertically as a column (hamburger menus optional, a stacked column is fine)
- On **tablet (600px+)**: show links in a horizontal row
- Links should have comfortable tap targets (at least `44px` tall on mobile)

### Task 3 — Flexbox Layout
Inside the `#flexbox-demo` section, create a row of `.flex-card` elements that:
- Wrap onto new lines when there isn't enough space (`flex-wrap: wrap`)
- Each card is at least `250px` wide (`flex: 1 1 250px`)
- Cards are vertically centered within the row
- On mobile: single column; on desktop: 3 per row

### Task 4 — CSS Grid Layout
Inside the `#grid-demo` section, build a photo grid with `.grid-item` elements:
- Mobile: 1 column
- Tablet (600px+): 2 columns  
- Desktop (900px+): 3 columns
- Use `gap` for gutters
- Make one item span 2 columns using `grid-column: span 2`

### Task 5 — Responsive Typography
- Use `clamp()` for the `<h1>` font size that scales between `1.5rem` and `3rem` based on viewport width
  ```css
  font-size: clamp(1.5rem, 5vw, 3rem);
  ```
- Body text should not get too wide to read: constrain with `max-width: 70ch`

### Task 6 — Test Your Work
Open DevTools → Toggle Device Toolbar (Ctrl/Cmd + Shift + M) and verify:
- iPhone SE (375px) — stacked layout, readable text
- iPad (768px) — 2-column grid, horizontal nav
- Desktop (1280px) — 3-column grid, full layout

---

## 📁 Files

```
exercise3-responsive-design/
├── README.md
├── index.html      ← Provided
├── style.css       ← Your work goes here
└── solution/
    ├── index.html
    └── style.css
```

---

## ✅ Done When...

- [ ] Page is usable on a 375px screen without horizontal scrolling
- [ ] Navigation collapses/stacks on mobile
- [ ] Flexbox section wraps correctly at all sizes
- [ ] Grid switches from 1 → 2 → 3 columns at breakpoints
- [ ] Typography uses `clamp()` for the main heading

---

## 💡 Hints

- `display: flex` on the parent; `flex` property on children
- `gap` works in both Flexbox and Grid
- Avoid fixed widths on mobile — prefer `max-width` instead
- Use `min-width` (not `max-width`) media queries for mobile-first
- Chrome DevTools lets you simulate any device size
