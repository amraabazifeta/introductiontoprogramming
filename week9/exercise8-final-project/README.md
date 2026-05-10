# Exercise 8 — Final Project 🏆

> **Difficulty:** 🔴 Advanced  
> **Topics:** Everything from Exercises 1–7 combined

---

## 🎯 Overview

This is your capstone project for Week 9. You'll build a complete, functional web application from scratch — no starter files provided.

Choose **one** of the three project options below, or propose your own (of similar scope).

---

## 🛠️ Project Options

---

### Option A — Weather Dashboard 🌤️

Build a weather app using the [Open-Meteo API](https://open-meteo.com/) (free, no API key).

**Features required:**
1. Search bar to enter a city name
2. Display current weather: temperature, wind speed, weather condition icon
3. 7-day forecast rendered as a horizontal card row
4. Temperature unit toggle: °C ↔ °F
5. Save recent searches in `localStorage` and show them as clickable chips
6. Loading state and error handling

**API hints:**
```
Geocoding: https://geocoding-api.open-meteo.com/v1/search?name=London&count=1
Weather:   https://api.open-meteo.com/v1/forecast?latitude=51.5&longitude=-0.1&daily=temperature_2m_max,temperature_2m_min,weathercode&current_weather=true&timezone=auto
```

---

### Option B — Task Manager 📋

Build a feature-rich todo app.

**Features required:**
1. Add tasks with: title, priority (low/medium/high), due date
2. Mark tasks as complete (strikethrough style)
3. Filter tasks by: All / Active / Completed / Priority
4. Sort tasks by: Due Date / Priority / Created
5. Persist everything in `localStorage`
6. Show task stats: "3 of 7 tasks completed"
7. "Clear Completed" button
8. Keyboard shortcut: pressing Enter in the input adds a task

---

### Option C — Quiz App 🧠

Build an interactive multiple-choice quiz.

**Features required:**
1. Fetch questions from `https://opentdb.com/api.php?amount=10&type=multiple` (Open Trivia Database)
2. Show one question at a time with 4 answer options (shuffled)
3. Highlight correct/incorrect answers after selection
4. Track score and display progress: "Question 3 of 10"
5. 30-second countdown timer per question (auto-advance when time runs out)
6. End screen showing final score with a "Play Again" button
7. Save high scores to `localStorage`

---

## 📋 Requirements (All Options)

Regardless of which project you choose, your submission must:

### HTML
- [ ] Semantic markup (`header`, `main`, `nav`, `section`, `footer`, etc.)
- [ ] All images have `alt` text
- [ ] Logical heading hierarchy
- [ ] Form inputs have associated labels

### CSS
- [ ] External stylesheet (no inline styles)
- [ ] CSS custom properties for colors/fonts
- [ ] Responsive: works on mobile (375px) and desktop (1200px)
- [ ] At least one CSS transition or animation
- [ ] Attractive, polished UI

### JavaScript
- [ ] All in an external `.js` file (no `<script>` tags with code in HTML)
- [ ] No use of `var` — use `const` and `let`
- [ ] At least one `async`/`await` fetch call
- [ ] Error handling with try/catch
- [ ] At least one use of `localStorage`
- [ ] Modular — break code into named functions, not one giant block
- [ ] No `alert()` for user-facing messages (use DOM elements instead)

---

## 📁 File Structure

```
exercise8-final-project/
├── README.md           ← You are here
├── index.html          ← Create this
├── style.css           ← Create this
├── script.js           ← Create this
└── (additional files if needed)
```

---

## 🗓️ Suggested Timeline

| Time | Task |
|------|------|
| 0–20 min | Plan: sketch layout on paper, list features, write HTML structure |
| 20–50 min | Build HTML + CSS to match your sketch |
| 50–90 min | Add core JavaScript functionality |
| 90–110 min | Add API integration and localStorage |
| 110–120 min | Test, fix bugs, polish |

---

## ✅ Submission Checklist

- [ ] Project loads without console errors
- [ ] All required features work
- [ ] Responsive on mobile and desktop
- [ ] Code is clean and commented
- [ ] You can explain any line of code you wrote
- [ ] `localStorage` data persists after page refresh
- [ ] API errors are handled gracefully

---

## 💡 Tips

- **Start with HTML** — get the structure right before writing any JS
- **Use DevTools constantly** — console.log liberally while debugging
- **Commit often** — git commit after every feature that works
- **Read the API docs** — the response structure is everything
- **Don't add features until the basics work**

Good luck — you've got everything you need! 🚀
