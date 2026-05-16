/* =========================
   TASK 1 — WARMUP
========================= */

// 1a
const title = document.querySelector('#main-title');
title.textContent = "DOM Mastery 🚀";

// 1b
const cards = document.querySelectorAll('.card');
console.log("Card count:", cards.length);

// 1c
const box = document.querySelector('#target-box');
box.style.backgroundColor = "#4f46e5";
box.style.color = "white";


/* =========================
   TASK 2 — COUNTER
========================= */

const countDisplay = document.querySelector('#count-display');
const btnInc = document.querySelector('#btn-increment');
const btnDec = document.querySelector('#btn-decrement');
const btnReset = document.querySelector('#btn-reset');

let count = 0;

function updateCountDisplay() {
  countDisplay.textContent = count;

  countDisplay.classList.remove('zero', 'high');

  if (count === 0) {
    countDisplay.classList.add('zero');
  } else if (count > 5) {
    countDisplay.classList.add('high');
  }
}

btnInc.addEventListener('click', () => {
  count++;
  updateCountDisplay();
});

btnDec.addEventListener('click', () => {
  if (count > 0) count--;
  updateCountDisplay();
});

btnReset.addEventListener('click', () => {
  count = 0;
  updateCountDisplay();
});

updateCountDisplay();


/* =========================
   TASK 3 — LIST BUILDER
========================= */

const input = document.querySelector('#list-input');
const addBtn = document.querySelector('#btn-add-item');
const list = document.querySelector('#dynamic-list');

function createItem(text) {
  const li = document.createElement('li');

  li.innerHTML = `
    <span>${text}</span>
    <button class="delete-btn">×</button>
  `;

  list.appendChild(li);
}

addBtn.addEventListener('click', () => {
  const value = input.value.trim();

  if (value === "") {
    input.classList.add('shake');
    setTimeout(() => input.classList.remove('shake'), 300);
    return;
  }

  createItem(value);
  input.value = "";
  input.focus();
});

// Delete with event delegation
list.addEventListener('click', (event) => {
  if (event.target.classList.contains('delete-btn')) {
    event.target.parentElement.remove();
  }
});


/* =========================
   TASK 4 — TOGGLE
========================= */

const toggleBtn = document.querySelector('#btn-toggle');
const details = document.querySelector('.details');

toggleBtn.addEventListener('click', () => {
  details.classList.toggle('hidden');

  if (details.classList.contains('hidden')) {
    toggleBtn.textContent = "Show Details";
  } else {
    toggleBtn.textContent = "Hide Details";
  }
});


/* =========================
   TASK 5 — COLOR MIXER
========================= */

const r = document.querySelector('#slider-r');
const g = document.querySelector('#slider-g');
const b = document.querySelector('#slider-b');

const rVal = document.querySelector('#val-r');
const gVal = document.querySelector('#val-g');
const bVal = document.querySelector('#val-b');

const preview = document.querySelector('#color-preview');
const hex = document.querySelector('#hex-display');

function updateColor() {
  const red = +r.value;
  const green = +g.value;
  const blue = +b.value;

  rVal.textContent = red;
  gVal.textContent = green;
  bVal.textContent = blue;

  preview.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;

  const hexColor =
    "#" +
    red.toString(16).padStart(2, '0') +
    green.toString(16).padStart(2, '0') +
    blue.toString(16).padStart(2, '0');

  hex.textContent = hexColor.toUpperCase();
}

r.addEventListener('input', updateColor);
g.addEventListener('input', updateColor);
b.addEventListener('input', updateColor);

updateColor();
