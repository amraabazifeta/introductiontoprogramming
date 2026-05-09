/**
 * script.js — Task Manager Final Project
 */

// ============================================================
// STATE
// ============================================================
let tasks = loadFromStorage();
let currentFilter = 'all';
let currentSort = 'created';

// ============================================================
// STORAGE
// ============================================================
function loadFromStorage() {
    const stored = localStorage.getItem('tasks');
    return stored ? JSON.parse(stored) : [];
}

function saveToStorage() {
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

// ============================================================
// ADD TASK
// ============================================================
const taskInput    = document.querySelector('#task-input');
const priorityInput = document.querySelector('#priority-input');
const dateInput    = document.querySelector('#date-input');
const btnAdd       = document.querySelector('#btn-add');

function addTask() {
    const title = taskInput.value.trim();
    if (!title) {
        taskInput.style.borderColor = '#e74c3c';
        setTimeout(() => taskInput.style.borderColor = '', 1000);
        return;
    }

    const task = {
        id: Date.now(),
        title,
        priority: priorityInput.value,
        dueDate: dateInput.value,
        completed: false,
        createdAt: Date.now()
    };

    tasks.unshift(task);
    saveToStorage();
    render();

    taskInput.value = '';
    dateInput.value = '';
    taskInput.focus();
}

btnAdd.addEventListener('click', addTask);
taskInput.addEventListener('keydown', (e) => { if (e.key === 'Enter') addTask(); });

// ============================================================
// DELETE TASK
// ============================================================
function deleteTask(id) {
    tasks = tasks.filter(t => t.id !== id);
    saveToStorage();
    render();
}

// ============================================================
// TOGGLE COMPLETE
// ============================================================
function toggleTask(id) {
    const task = tasks.find(t => t.id === id);
    if (task) task.completed = !task.completed;
    saveToStorage();
    render();
}

// ============================================================
// CLEAR COMPLETED
// ============================================================
document.querySelector('#btn-clear-completed').addEventListener('click', () => {
    tasks = tasks.filter(t => !t.completed);
    saveToStorage();
    render();
});

// ============================================================
// FILTERS
// ============================================================
document.querySelectorAll('.filter-btn').forEach(btn => {
    btn.addEventListener('click', () => {
        document.querySelectorAll('.filter-btn').forEach(b => b.classList.remove('active'));
        btn.classList.add('active');
        currentFilter = btn.dataset.filter;
        render();
    });
});

// ============================================================
// SORT
// ============================================================
document.querySelector('#sort-input').addEventListener('change', (e) => {
    currentSort = e.target.value;
    render();
});

// ============================================================
// FILTER & SORT LOGIC
// ============================================================
function getFilteredSortedTasks() {
    let filtered = [...tasks];

    if (currentFilter === 'active')    filtered = filtered.filter(t => !t.completed);
    if (currentFilter === 'completed') filtered = filtered.filter(t => t.completed);
    if (currentFilter === 'high')      filtered = filtered.filter(t => t.priority === 'high');
    if (currentFilter === 'medium')    filtered = filtered.filter(t => t.priority === 'medium');
    if (currentFilter === 'low')       filtered = filtered.filter(t => t.priority === 'low');

    const priorityOrder = { high: 0, medium: 1, low: 2 };

    if (currentSort === 'priority') {
        filtered.sort((a, b) => priorityOrder[a.priority] - priorityOrder[b.priority]);
    } else if (currentSort === 'duedate') {
        filtered.sort((a, b) => {
            if (!a.dueDate) return 1;
            if (!b.dueDate) return -1;
            return new Date(a.dueDate) - new Date(b.dueDate);
        });
    } else {
        filtered.sort((a, b) => b.createdAt - a.createdAt);
    }

    return filtered;
}

// ============================================================
// RENDER
// ============================================================
function render() {
    const list = document.querySelector('#task-list');
    const emptyMsg = document.querySelector('#empty-message');
    const stats = document.querySelector('#task-stats');

    const filtered = getFilteredSortedTasks();

    list.innerHTML = '';

    if (filtered.length === 0) {
        emptyMsg.classList.remove('hidden');
    } else {
        emptyMsg.classList.add('hidden');
        filtered.forEach(task => {
            const li = document.createElement('li');
            li.classList.add('task-item', `priority-${task.priority}`);
            if (task.completed) li.classList.add('completed');

            li.innerHTML = `
                <input type="checkbox" class="task-checkbox" ${task.completed ? 'checked' : ''} aria-label="Mark complete" />
                <div class="task-info">
                    <div class="task-title">${task.title}</div>
                    <div class="task-meta">
                        <span class="badge badge-${task.priority}">${task.priority}</span>
                        ${task.dueDate ? `<span>📅 ${task.dueDate}</span>` : ''}
                    </div>
                </div>
                <button class="btn-delete" aria-label="Delete task">🗑️</button>
            `;

            li.querySelector('.task-checkbox').addEventListener('change', () => toggleTask(task.id));
            li.querySelector('.btn-delete').addEventListener('click', () => deleteTask(task.id));

            list.appendChild(li);
        });
    }

    const completed = tasks.filter(t => t.completed).length;
    stats.textContent = `${completed} of ${tasks.length} tasks completed`;
}

// ============================================================
// INIT
// ============================================================
render();
