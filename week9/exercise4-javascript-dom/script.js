/**
 * Exercise 4: JavaScript & the DOM
 * ==================================
 * Complete each task below. Read the README.md for full instructions.
 * Open the browser console (F12) to debug.
 */

// ============================================================
// TASK 1 — Console Warmup
// ============================================================

// TODO 1a: Select the element with id "main-title" and change its text to
//          "DOM Mastery 🚀" using .textContent
<<<<<<< HEAD
document.querySelector('#main-title').textContent = "DOM Mastery 🚀";

// TODO 1b: Select ALL elements with class "card", log how many there are
const cards = document.querySelectorAll('.card');
console.log("Total cards:", cards.length);

// TODO 1c: Select the element with id "target-box" and change its
//          background color to any color you like using style.backgroundColor
document.querySelector('#target-box').style.backgroundColor = "#4f46e5";
=======


// TODO 1b: Select ALL elements with class "card", log how many there are


// TODO 1c: Select the element with id "target-box" and change its
//          background color to any color you like using style.backgroundColor

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db


// ============================================================
// TASK 2 — Click Counter
// ============================================================

// Step 1: Get references to the elements you need
const countDisplay = document.querySelector('#count-display');
// TODO: get references to the three buttons
<<<<<<< HEAD
const btnIncrement = document.querySelector('#btn-increment');
const btnDecrement = document.querySelector('#btn-decrement');
const btnReset = document.querySelector('#btn-reset');
=======
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

// Step 2: Track the count
let count = 0;

// Helper: update the display and apply color classes
function updateCountDisplay() {
  // TODO: Set countDisplay.textContent to count
<<<<<<< HEAD
  countDisplay.textContent = count;
  
  // TODO: If count is 0, add class 'zero' to countDisplay (and remove 'high')
  if (count === 0) {
    countDisplay.classList.add('zero');
    countDisplay.classList.remove('high');
  } 
  // TODO: If count > 5, add class 'high' (and remove 'zero')
  else if (count > 5) {
    countDisplay.classList.add('high');
    countDisplay.classList.remove('zero');
  } 
  // TODO: Otherwise, remove both classes
  else {
    countDisplay.classList.remove('zero', 'high');
  }
}

// TODO: Add click event listener to increment button
btnIncrement.addEventListener('click', () => {
  count++;
  updateCountDisplay();
});

// TODO: Add click event listener to decrement button (don't go below 0!)
btnDecrement.addEventListener('click', () => {
  if (count > 0) {
    count--;
    updateCountDisplay();
  }
});

// TODO: Add click event listener to reset button
btnReset.addEventListener('click', () => {
  count = 0;
  updateCountDisplay();
});
=======
  // TODO: If count is 0, add class 'zero' to countDisplay (and remove 'high')
  // TODO: If count > 5, add class 'high' (and remove 'zero')
  // TODO: Otherwise, remove both classes
}

// TODO: Add click event listener to increment button
// TODO: Add click event listener to decrement button (don't go below 0!)
// TODO: Add click event listener to reset button
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

// Initialize display
updateCountDisplay();


// ============================================================
// TASK 3 — Dynamic List Builder
// ============================================================

const listInput = document.querySelector('#list-input');
const dynamicList = document.querySelector('#dynamic-list');
<<<<<<< HEAD
const btnAddItem = document.querySelector('#btn-add-item');

// TODO: Add click listener to '#btn-add-item'
btnAddItem.addEventListener('click', () => {
  const value = listInput.value.trim();

  // 2. If it's empty, don't add
  if (value === "") {
    listInput.classList.add('shake');
    setTimeout(() => listInput.classList.remove('shake'), 500);
    return;
  }

  // 3. Create a new <li> element
  const li = document.createElement('li');
  
  // 4. Set its text content (include a × delete button)
  li.innerHTML = `${value} <button class="delete-btn">×</button>`;
  
  // 5. Append the <li> to dynamicList
  dynamicList.appendChild(li);
  
  // 6. Clear listInput.value and focus it
  listInput.value = "";
  listInput.focus();
});

// Wire up delete buttons
dynamicList.addEventListener('click', function(event) {
  // TODO: if the clicked element has class 'delete-btn', remove its parent <li>
  if (event.target.classList.contains('delete-btn')) {
    event.target.parentElement.remove();
  }
=======

// TODO: Add click listener to '#btn-add-item'
// Inside the listener:
//   1. Get the value from listInput
//   2. If it's empty (after .trim()), don't add — shake the input or alert
//   3. Create a new <li> element
//   4. Set its text content (include a × delete button)
//   5. Append the <li> to dynamicList
//   6. Clear listInput.value and focus it

// TODO: Handle delete buttons — you'll need event delegation OR
//       attach a listener each time you create a new item.
//       Hint for event delegation:
//       dynamicList.addEventListener('click', function(event) {
//         if (event.target.classList.contains('delete-btn')) { ... }
//       });

// Wire up delete buttons that already exist in the HTML
dynamicList.addEventListener('click', function(event) {
  // TODO: if the clicked element has class 'delete-btn', remove its parent <li>
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
});


// ============================================================
// TASK 4 — Show / Hide Toggle
// ============================================================

const toggleBtn = document.querySelector('#btn-toggle');
const detailsDiv = document.querySelector('.details');

// TODO: Add click listener to toggleBtn
<<<<<<< HEAD
toggleBtn.addEventListener('click', () => {
  detailsDiv.classList.toggle('hidden');
  
  if (detailsDiv.classList.contains('hidden')) {
    toggleBtn.textContent = "Show Details";
  } else {
    toggleBtn.textContent = "Hide Details";
  }
});
=======
// Inside:
//   - Toggle the 'hidden' class on detailsDiv
//   - Change button text: "Show Details" ↔ "Hide Details"
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db


// ============================================================
// TASK 5 — Color Mixer
// ============================================================

const sliderR = document.querySelector('#slider-r');
const sliderG = document.querySelector('#slider-g');
const sliderB = document.querySelector('#slider-b');
const colorPreview = document.querySelector('#color-preview');
const hexDisplay = document.querySelector('#hex-display');

<<<<<<< HEAD
const valR = document.querySelector('#val-r');
const valG = document.querySelector('#val-g');
const valB = document.querySelector('#val-b');

=======
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
function updateColor() {
  const r = parseInt(sliderR.value);
  const g = parseInt(sliderG.value);
  const b = parseInt(sliderB.value);

  // TODO: Update the text of #val-r, #val-g, #val-b spans
<<<<<<< HEAD
  valR.textContent = r;
  valG.textContent = g;
  valB.textContent = b;

  // TODO: Set colorPreview's background to rgb(r, g, b)
  const rgbColor = `rgb(${r}, ${g}, ${b})`;
  colorPreview.style.backgroundColor = rgbColor;

  // TODO: Convert each value to a 2-digit hex string and update #hex-display
  const hexR = r.toString(16).padStart(2, '0');
  const hexG = g.toString(16).padStart(2, '0');
  const hexB = b.toString(16).padStart(2, '0');
  hexDisplay.textContent = `#${hexR}${hexG}${hexB}`.toUpperCase();
}

// TODO: Add 'input' event listeners to all three sliders that call updateColor()
sliderR.addEventListener('input', updateColor);
sliderG.addEventListener('input', updateColor);
sliderB.addEventListener('input', updateColor);

// Initialize
updateColor();
=======

  // TODO: Set colorPreview's background to rgb(r, g, b)

  // TODO: Convert each value to a 2-digit hex string and update #hex-display
  // Hint: const hex = value.toString(16).padStart(2, '0');
}

// TODO: Add 'input' event listeners to all three sliders that call updateColor()

// Initialize
updateColor();
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
