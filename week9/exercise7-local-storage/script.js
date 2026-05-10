/**
 * Exercise 7: Local Storage — Notes App
 * =======================================
 * Build a full CRUD notes app using localStorage.
 * Read README.md for full instructions.
 */

// ============================================================
// TASK 1 — Initialize: Load notes from localStorage
// ============================================================

const STORAGE_KEY = 'week9_notes';

// TODO: Load notes from localStorage, or default to []
let notes = JSON.parse(localStorage.getItem(STORAGE_KEY)) || [];
let editingId = null; // null means we're in "add" mode

function saveNotes() {
  // TODO: JSON.stringify notes and save to localStorage
  localStorage.setItem(STORAGE_KEY, JSON.stringify(notes));
}


// ============================================================
// TASK 3 — Render Notes
// ============================================================

const notesContainer = document.querySelector('#notes-container');

function renderNotes(filter = '') {
  notesContainer.innerHTML = '';

  // TODO: Filter notes by search term (if filter is not empty)
  let filtered = notes.filter(n => 
    n.title.toLowerCase().includes(filter.toLowerCase()) || 
    n.body.toLowerCase().includes(filter.toLowerCase())
  );

  // TODO: Sort so pinned notes appear first
  filtered.sort((a, b) => b.pinned - a.pinned);

  if (filtered.length === 0) {
    notesContainer.innerHTML = `
      <div class="empty-state">
        <p>${filter ? `No results for "${filter}"` : 'No notes yet. Create your first one!'}</p>
      </div>`;
    return;
  }

  // TODO: For each note, create a card element and append
  filtered.forEach(note => {
    const date = new Date(note.createdAt).toLocaleDateString('en-US', { 
      month: 'short', day: 'numeric', year: 'numeric' 
    });
    
    const bodyPreview = note.body.length > 100 
      ? note.body.substring(0, 100) + '...' 
      : note.body;

    const card = document.createElement('div');
    card.className = `note-card ${note.pinned ? 'pinned' : ''}`;
    card.innerHTML = `
      <div class="note-content">
        <h3>${note.pinned ? '📌 ' : ''}${note.title}</h3>
        <p>${bodyPreview}</p>
        <small>${date}</small>
      </div>
      <div class="note-actions">
        <button data-id="${note.id}" data-action="pin">${note.pinned ? 'Unpin' : 'Pin'}</button>
        <button data-id="${note.id}" data-action="edit">Edit</button>
        <button data-id="${note.id}" data-action="delete" class="btn-delete">Delete</button>
      </div>
    `;
    notesContainer.appendChild(card);
  });
}


// ============================================================
// TASK 2 — Create Notes
// ============================================================

const noteForm     = document.querySelector('#note-form');
const titleInput   = document.querySelector('#note-title');
const bodyInput    = document.querySelector('#note-body');
const submitBtn    = document.querySelector('#btn-submit');
const cancelBtn    = document.querySelector('#btn-cancel');

noteForm.addEventListener('submit', function(event) {
  event.preventDefault();

  const title = titleInput.value.trim();
  const body  = bodyInput.value.trim();

  if (!title) { titleInput.focus(); return; }

  if (editingId !== null) {
    // ===== TASK 4: UPDATE existing note =====
    const index = notes.findIndex(n => n.id === editingId);
    if (index !== -1) {
      notes[index].title = title;
      notes[index].body = body;
    }
    editingId = null;
    submitBtn.textContent = 'Save Note';
    cancelBtn.classList.add('hidden');

  } else {
    // ===== TASK 2: CREATE new note =====
    const newNote = {
      id: Date.now(),
      title: title,
      body: body,
      createdAt: new Date().toISOString(),
      pinned: false
    };
    notes.push(newNote);
  }

  saveNotes();
  renderNotes();
  noteForm.reset();
});

cancelBtn.addEventListener('click', function() {
  editingId = null;
  noteForm.reset();
  submitBtn.textContent = 'Save Note';
  cancelBtn.classList.add('hidden');
});


// ============================================================
// TASKS 4 & 5 — Edit, Pin, Delete via Event Delegation
// ============================================================

notesContainer.addEventListener('click', function(event) {
  const btn = event.target.closest('button[data-action]');
  if (!btn) return;

  const id     = parseInt(btn.dataset.id);
  const action = btn.dataset.action;

  if (action === 'delete') {
    if (confirm('Are you sure you want to delete this note?')) {
      notes = notes.filter(n => n.id !== id);
      saveNotes();
      renderNotes();
    }
  }

  if (action === 'pin') {
    const note = notes.find(n => n.id === id);
    if (note) {
      note.pinned = !note.pinned;
      saveNotes();
      renderNotes();
    }
  }

  if (action === 'edit') {
    const note = notes.find(n => n.id === id);
    if (note) {
      editingId = note.id;
      titleInput.value = note.title;
      bodyInput.value = note.body;
      submitBtn.textContent = 'Update Note';
      cancelBtn.classList.remove('hidden');
      window.scrollTo(0, 0);
      titleInput.focus();
    }
  }
});


// ============================================================
// TASK 6 — Search Filter (Bonus)
// ============================================================

const searchInput = document.querySelector('#search-input');
if (searchInput) {
  searchInput.addEventListener('input', () => {
    renderNotes(searchInput.value);
  });
}


// ============================================================
// Initialize
// ============================================================
renderNotes();