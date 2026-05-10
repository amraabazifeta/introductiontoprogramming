/**
 * script.js — Final Project
 * ==========================
 * Mini Notes + Quote + Storage App
 */

console.log('Final project script loaded. 🚀');

/* =========================
   LOCAL STORAGE SETUP
========================= */

const STORAGE_KEY = 'final_notes_app';

// Load notes
let notes = JSON.parse(localStorage.getItem(STORAGE_KEY)) || [];

// Save notes
function saveNotes() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(notes));
}


/* =========================
   NOTES UI ELEMENTS
========================= */

const notesContainer = document.querySelector('#notes-container');
const form = document.querySelector('#note-form');
const titleInput = document.querySelector('#title');
const bodyInput = document.querySelector('#body');


/* =========================
   RENDER NOTES
========================= */

function renderNotes() {
  notesContainer.innerHTML = '';

  if (notes.length === 0) {
    notesContainer.innerHTML = `<p>No notes yet.</p>`;
    return;
  }

  notes
    .sort((a, b) => b.pinned - a.pinned)
    .forEach(note => {
      const div = document.createElement('div');
      div.className = 'note';

      div.innerHTML = `
        <h3>${note.pinned ? '📌 ' : ''}${note.title}</h3>
        <p>${note.body.slice(0, 100)}</p>
        <small>${new Date(note.createdAt).toLocaleDateString()}</small>
        <div class="actions">
          <button onclick="deleteNote(${note.id})">Delete</button>
          <button onclick="pinNote(${note.id})">Pin</button>
        </div>
      `;

      notesContainer.appendChild(div);
    });
}


/* =========================
   CREATE NOTE
========================= */

form.addEventListener('submit', (e) => {
  e.preventDefault();

  const title = titleInput.value.trim();
  const body = bodyInput.value.trim();

  if (!title || !body) return;

  const newNote = {
    id: Date.now(),
    title,
    body,
    createdAt: new Date().toISOString(),
    pinned: false
  };

  notes.push(newNote);

  saveNotes();
  renderNotes();

  form.reset();
});


/* =========================
   DELETE NOTE
========================= */

function deleteNote(id) {
  notes = notes.filter(n => n.id !== id);
  saveNotes();
  renderNotes();
}


/* =========================
   PIN NOTE
========================= */

function pinNote(id) {
  notes = notes.map(n =>
    n.id === id ? { ...n, pinned: !n.pinned } : n
  );

  saveNotes();
  renderNotes();
}


/* =========================
   FETCH API (ASYNC/AWAIT)
========================= */

const quoteBox = document.querySelector('#quote-box');
const btnQuote = document.querySelector('#new-quote');

async function getQuote() {
  quoteBox.textContent = "Loading...";

  try {
    const res = await fetch('https://api.quotable.io/random');

    if (!res.ok) throw new Error('API error');

    const data = await res.json();

    quoteBox.innerHTML = `
      <p>"${data.content}"</p>
      <small>- ${data.author}</small>
    `;

  } catch (err) {
    quoteBox.textContent = "Failed to load quote.";
  }
}

btnQuote.addEventListener('click', getQuote);


/* =========================
   INITIAL LOAD
========================= */

renderNotes();
getQuote();
