/**
 * Exercise 4: JavaScript & the DOM
 */

// ============================================================
// TASK 1 — Console Warmup
// ============================================================

// 1a: Change the main title text
document.querySelector('#main-title').textContent = 'DOM Mastery 🚀';

// 1b: Select all cards and log how many
const allCards = document.querySelectorAll('.card');
console.log('Number of cards:', allCards.length);

// 1c: Change background color of target-box
document.querySelector('#target-box').style.backgroundColor = '#e8a838';


// ============================================================
// TASK 2 — Click Counter
// ============================================================

const countDisplay = document.querySelector('#count-display');
const btnIncrement = document.querySelector('#btn-increment');
const btnDecrement = document.querySelector('#btn-decrement');
const btnReset = document.querySelector('#btn-reset');

let count = 0;

function updateCountDisplay() {
    countDisplay.textContent = count;
    if (count === 0) {
        countDisplay.classList.add('zero');
        countDisplay.classList.remove('high');
    } else if (count > 5) {
        countDisplay.classList.add('high');
        countDisplay.classList.remove('zero');
    } else {
        countDisplay.classList.remove('zero');
        countDisplay.classList.remove('high');
    }
}

btnIncrement.addEventListener('click', function() {
    count++;
    updateCountDisplay();
});

btnDecrement.addEventListener('click', function() {
    if (count > 0) count--;
    updateCountDisplay();
});

btnReset.addEventListener('click', function() {
    count = 0;
    updateCountDisplay();
});

updateCountDisplay();


// ============================================================
// TASK 3 — Dynamic List Builder
// ============================================================

const listInput = document.querySelector('#list-input');
const dynamicList = document.querySelector('#dynamic-list');
const btnAddItem = document.querySelector('#btn-add-item');

btnAddItem.addEventListener('click', function() {
    const value = listInput.value.trim();

    if (value === '') {
        listInput.classList.add('shake');
        setTimeout(() => listInput.classList.remove('shake'), 300);
        return;
    }

    const li = document.createElement('li');
    li.innerHTML = `<span>${value}</span><button class="delete-btn">×</button>`;
    dynamicList.appendChild(li);

    listInput.value = '';
    listInput.focus();
});

// Allow pressing Enter to add item
listInput.addEventListener('keydown', function(event) {
    if (event.key === 'Enter') btnAddItem.click();
});

// Event delegation for delete buttons
dynamicList.addEventListener('click', function(event) {
    if (event.target.classList.contains('delete-btn')) {
        event.target.parentElement.remove();
    }
});


// ============================================================
// TASK 4 — Show / Hide Toggle
// ============================================================

const toggleBtn = document.querySelector('#btn-toggle');
const detailsDiv = document.querySelector('.details');

toggleBtn.addEventListener('click', function() {
    detailsDiv.classList.toggle('hidden');
    if (detailsDiv.classList.contains('hidden')) {
        toggleBtn.textContent = 'Show Details';
    } else {
        toggleBtn.textContent = 'Hide Details';
    }
});


// ============================================================
// TASK 5 — Color Mixer
// ============================================================

const sliderR = document.querySelector('#slider-r');
const sliderG = document.querySelector('#slider-g');
const sliderB = document.querySelector('#slider-b');
const colorPreview = document.querySelector('#color-preview');
const hexDisplay = document.querySelector('#hex-display');

function updateColor() {
    const r = parseInt(sliderR.value);
    const g = parseInt(sliderG.value);
    const b = parseInt(sliderB.value);

    document.querySelector('#val-r').textContent = r;
    document.querySelector('#val-g').textContent = g;
    document.querySelector('#val-b').textContent = b;

    colorPreview.style.backgroundColor = `rgb(${r}, ${g}, ${b})`;

    const hex = '#' +
        r.toString(16).padStart(2, '0') +
        g.toString(16).padStart(2, '0') +
        b.toString(16).padStart(2, '0');
    hexDisplay.textContent = hex.toUpperCase();
}

sliderR.addEventListener('input', updateColor);
sliderG.addEventListener('input', updateColor);
sliderB.addEventListener('input', updateColor);

updateColor();
