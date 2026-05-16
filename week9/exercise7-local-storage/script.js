/**
 * Exercise 7: Local Storage — Notes App
 */

const STORAGE_KEY = 'week9_notes';

const notesContainer = document.querySelector('#notes-container');
const noteForm     = document.querySelector('#note-form');
const titleInput   = document.querySelector('#note-title');
const bodyInput    = document.querySelector('#note-body');
const submitBtn    = document.querySelector('#btn-submit');
const cancelBtn    = document.querySelector('#btn-cancel');
const searchInput  = document.querySelector('#search-input');

// =========================
// INIT
// =========================
let notes = JSON.parse(localStorage.getItem(STORAGE_KEY)) || [];
let editingId = null;

// =========================
// SAVE
// =========================
function saveNotes() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(notes));
}

// =========================
// RENDER
// =========================
function renderNotes(filter = '') {
  notesContainer.innerHTML = '';

  let filtered = notes.filter(n =>
    n.title.toLowerCase().includes(filter.toLowerCase()) ||
    n.body.toLowerCase().includes(filter.toLowerCase())
  );

  filtered.sort((a, b) => b.pinned - a.pinned);

  if (filtered.length === 0) {
    notesContainer.innerHTML = `
      <div class="empty-state">
        <p>${filter ? `No results for "${filter}"` : 'No notes yet. Create your first one!'}</p>
      </div>`;
    return;
  }

  filtered.forEach(note => {
    const div = document.createElement('div');
    div.classList.add('note-card');

    const preview = note.body.length > 100
      ? note.body.slice(0, 100) + "..."
      : note.body;

    const date = new Date(note.createdAt).toLocaleDateString();

    div.innerHTML = `
      <h3>${note.pinned ? "📌 " : ""}${note.title}</h3>
      <p>${preview}</p>
      <small>${date}</small>
      <div class="actions">
        <button data-action="edit" data-id="${note.id}">Edit</button>
        <button data-action="pin" data-id="${note.id}">Pin</button>
        <button data-action="delete" data-id="${note.id}">Delete</button>
      </div>
    `;

    notesContainer.appendChild(div);
  });
}

// =========================
// CREATE / UPDATE
// =========================
noteForm.addEventListener('submit', (e) => {
  e.preventDefault();

  const title = titleInput.value.trim();
  const body = bodyInput.value.trim();

  if (!title) return titleInput.focus();

  if (editingId !== null) {
    const note = notes.find(n => n.id === editingId);
    note.title = title;
    note.body = body;

    editingId = null;
    submitBtn.textContent = "Save Note";
    cancelBtn.style.display = "none";

  } else {
    const newNote = {
      id: Date.now(),
      title,
      body,
      createdAt: new Date().toISOString(),
      pinned: false
    };

    notes.push(newNote);
  }

  saveNotes();
  renderNotes();
  noteForm.reset();
});

// =========================
// CANCEL EDIT
// =========================
cancelBtn.addEventListener('click', () => {
  editingId = null;
  noteForm.reset();
  submitBtn.textContent = "Save Note";
  cancelBtn.style.display = "none";
});

// =========================
// ACTIONS (DELETE / PIN / EDIT)
// =========================
notesContainer.addEventListener('click', (e) => {
  const btn = e.target.closest('button[data-action]');
  if (!btn) return;

  const id = Number(btn.dataset.id);
  const action = btn.dataset.action;

  if (action === 'delete') {
    if (!confirm("Delete this note?")) return;
    notes = notes.filter(n => n.id !== id);
  }

  if (action === 'pin') {
    const note = notes.find(n => n.id === id);
    note.pinned = !note.pinned;
  }

  if (action === 'edit') {
    const note = notes.find(n => n.id === id);
    titleInput.value = note.title;
    bodyInput.value = note.body;

    editingId = id;
    submitBtn.textContent = "Update Note";
    cancelBtn.style.display = "inline-block";
  }

  saveNotes();
  renderNotes(searchInput.value);
});

// =========================
// SEARCH
// =========================
searchInput.addEventListener('input', (e) => {
  renderNotes(e.target.value);
});

// =========================
// INIT RENDER
// =========================
renderNotes();
