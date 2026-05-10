# Exercise 7 — Local Storage 💾

> **Difficulty:** 🔴 Advanced  
> **Topics:** `localStorage`, JSON serialization, data persistence, CRUD operations

---

## 🎯 Learning Objectives

- Store and retrieve data using `localStorage`
- Serialize JavaScript objects to JSON with `JSON.stringify()`
- Parse JSON strings back to objects with `JSON.parse()`
- Build a complete CRUD (Create, Read, Update, Delete) interface
- Understand when data persists and when it doesn't

---

## 📋 Tasks

You'll build a **personal note-taking app** that saves notes in `localStorage`. Close the browser and reopen — your notes should still be there.

### Task 1 — Initialize localStorage
On page load:
- Check if `localStorage.getItem('notes')` exists
- If it does: parse it with `JSON.parse()` and load the notes
- If it doesn't: initialize with an empty array `[]`
- Write a `saveNotes()` function that saves the notes array with `JSON.stringify()`

### Task 2 — Create Notes
When the user fills in a title and body and clicks "Save Note":
- Create a note object: `{ id: Date.now(), title, body, createdAt: new Date().toISOString(), pinned: false }`
- Push it to the notes array
- Call `saveNotes()` to persist
- Re-render the notes list
- Clear the form

### Task 3 — Read & Render Notes
Write a `renderNotes()` function that:
- Clears `#notes-container`
- Sorts notes so pinned ones appear first
- For each note, creates a card with: title, body preview (first 100 chars), formatted date, and action buttons (Pin, Edit, Delete)
- Shows a "No notes yet" placeholder when the array is empty

### Task 4 — Update Notes
When the user clicks the **Edit** button on a note:
- Populate the form with the note's current title and body
- Change the form's submit button to "Update Note"
- On submit: find the note by ID, update it in the array, call `saveNotes()`, re-render
- Add a "Cancel" button that resets the form to "Add" mode

### Task 5 — Delete & Pin
- **Delete button**: Remove the note from the array, save, re-render. Ask for confirmation first (`confirm()`).
- **Pin button**: Toggle `note.pinned`. Save, re-render. Pinned notes show a 📌 icon and appear at the top.

### Task 6 — Search Filter (Bonus)
Add a search `<input>` that filters notes in real time:
- Filter by title or body text (case-insensitive)
- Filtering is purely visual — don't modify the saved data
- Show "No results for X" when nothing matches

---

## 📁 Files

```
exercise7-local-storage/
├── README.md
├── index.html      ← Provided
├── style.css       ← Provided
├── script.js       ← Your work goes here
└── solution/
    └── script.js
```

---

## ✅ Done When...

- [ ] Notes persist after page refresh (check localStorage in DevTools → Application tab)
- [ ] New notes are added and immediately visible
- [ ] Edit correctly pre-fills the form and updates the right note
- [ ] Delete removes the note (with confirmation)
- [ ] Pinned notes sort to the top
- [ ] Empty state message shows when there are no notes
- [ ] (Bonus) Search filters notes in real time

---

## 💡 Hints

```javascript
// Save an array to localStorage
localStorage.setItem('notes', JSON.stringify(notesArray));

// Load it back
const stored = localStorage.getItem('notes');
const notes = stored ? JSON.parse(stored) : [];

// Generate a unique ID from timestamp
const id = Date.now(); // e.g., 1700000000000

// Format a date nicely
new Date(note.createdAt).toLocaleDateString('en-US', { month: 'short', day: 'numeric', year: 'numeric' })
```

- DevTools → Application → Local Storage → your page URL, to inspect stored data
- `array.findIndex(n => n.id === id)` finds the index of a note by ID
- `array.filter(n => n.id !== id)` removes a note by ID
