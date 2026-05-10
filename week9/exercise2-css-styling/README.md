# Exercise 2 — CSS Styling 🎨

> **Difficulty:** 🟢 Beginner  
> **Topics:** Selectors, box model, typography, colors, pseudo-classes

---

## 🎯 Learning Objectives

- Link an external CSS file to an HTML document
- Use element, class, and ID selectors
- Understand and manipulate the CSS box model (margin, border, padding, content)
- Style typography (font-family, font-size, font-weight, line-height, color)
- Use pseudo-classes (`:hover`, `:focus`, `:nth-child`)
- Apply CSS custom properties (variables)

---

## 📋 Tasks

### Task 1 — Link Your Stylesheet
A basic `index.html` is provided. Link `style.css` to it using a `<link>` tag in the `<head>`.

### Task 2 — CSS Custom Properties
At the top of `style.css`, define at least **5 CSS custom properties** inside `:root`:
- `--color-primary` (your main brand color)
- `--color-secondary`
- `--color-text`
- `--color-background`
- `--font-heading` (a Google Font of your choice)
- `--font-body`
- `--spacing-unit` (e.g., `1rem`)

Then apply these variables throughout your CSS using `var(--property-name)`.

> **Import a Google Font** by adding a `<link>` to the Google Fonts URL in your HTML `<head>`.

### Task 3 — Selectors Practice
Write CSS rules using each of these selector types at least once:
- Element selector: `p { ... }`
- Class selector: `.card { ... }`
- ID selector: `#hero { ... }`
- Descendant selector: `nav a { ... }`
- Pseudo-class: `a:hover { ... }`, `li:nth-child(odd) { ... }`
- Pseudo-element: `p::first-letter { ... }`

### Task 4 — Box Model
Style a `.card` element so it demonstrates all four box model layers:
- `padding`: at least `1rem` inside
- `border`: a visible border with color and width
- `margin`: space separating cards from other elements
- A `border-radius` for rounded corners

### Task 5 — Typography
Make the page readable and attractive:
- `<h1>` through `<h3>` each have distinct sizes using a modular scale (e.g., `2.5rem`, `1.75rem`, `1.25rem`)
- Body text has a comfortable `line-height` (1.5–1.8)
- Navigation links have no underline by default, but gain one on `:hover`
- The page uses your Google Font from Task 2

### Task 6 — Color & Visual Polish
- The `<header>` has a background color using your custom property
- Alternating `<li>` items have different background colors (use `:nth-child`)
- The `:focus` state on links is visible for accessibility (don't just remove it!)

---

## 📁 Files

```
exercise2-css-styling/
├── README.md
├── index.html      ← HTML structure (provided, don't change)
├── style.css       ← Your work goes here
└── solution/
    ├── index.html
    └── style.css
```

---

## ✅ Done When...

- [ ] No inline styles in HTML — everything is in `style.css`
- [ ] At least 5 custom properties defined and used
- [ ] All 6 selector types demonstrated
- [ ] Cards look polished with box model properties
- [ ] Typography is readable and uses a custom font
- [ ] Hover and focus states are visible

---

## 💡 Hints

- Open DevTools → Computed tab to see the box model visually
- `color` affects text; `background-color` affects the box behind it
- `em` is relative to the parent font size; `rem` is relative to the root (safer for layout)
- `text-decoration: none` removes underlines from links
