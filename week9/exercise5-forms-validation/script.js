/**
 * Exercise 5: Forms & Validation
 * ================================
 * Add real-time validation and submit handling.
 * Read README.md for full instructions.
 */

const form = document.querySelector('#registration-form');

// ============================================================
// HELPER: Show or clear an error on a field
// ============================================================
function showError(inputId, message) {
  // TODO: Add class 'invalid' to the input element
<<<<<<< HEAD
  const input = document.querySelector(`#${inputId}`);
  input.classList.add('invalid');
  input.classList.remove('valid');
  
  // TODO: Set the text of the corresponding error-msg span to `message`
  const errorSpan = document.querySelector(`#error-${inputId}`);
  if (errorSpan) {
    errorSpan.textContent = message;
  }
=======
  // TODO: Set the text of the corresponding error-msg span to `message`
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function clearError(inputId) {
  // TODO: Remove class 'invalid', add class 'valid' to the input
<<<<<<< HEAD
  const input = document.querySelector(`#${inputId}`);
  input.classList.remove('invalid');
  input.classList.add('valid');
  
  // TODO: Clear the error-msg span text
  const errorSpan = document.querySelector(`#error-${inputId}`);
  if (errorSpan) {
    errorSpan.textContent = '';
  }
=======
  // TODO: Clear the error-msg span text
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}


// ============================================================
// TASK 2: Individual Field Validators
// (Return true if valid, false if invalid)
// ============================================================

function validateName() {
  // TODO: Get #full-name value
<<<<<<< HEAD
  const nameInput = document.querySelector('#full-name');
  const value = nameInput.value.trim();
  
  // If < 2 chars: showError, return false
  if (value.length < 2) {
    showError('full-name', 'Full name must be at least 2 characters long.');
    return false;
  } else {
    // Else: clearError, return true
    clearError('full-name');
    return true;
  }
=======
  // If < 2 chars: showError, return false
  // Else: clearError, return true
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validateEmail() {
  // TODO: Get #email value
<<<<<<< HEAD
  const emailInput = document.querySelector('#email');
  const value = emailInput.value.trim();
  const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  
  // Use regex /^[^\s@]+@[^\s@]+\.[^\s@]+$/ to test
  if (!emailRegex.test(value)) {
    showError('email', 'Please enter a valid email address.');
    return false;
  } else {
    clearError('email');
    return true;
  }
=======
  // Use regex /^[^\s@]+@[^\s@]+\.[^\s@]+$/ to test
  // showError or clearError appropriately
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validatePassword() {
  // TODO: Get #password value
<<<<<<< HEAD
  const passwordInput = document.querySelector('#password');
  const value = passwordInput.value;
  const hasDigit = /\d/.test(value);
  
  // Update #password-strength indicator (Task 4)
  updatePasswordStrength(value);

  // Must be 8+ chars AND contain at least one digit
  if (value.length < 8 || !hasDigit) {
    showError('password', 'Password must be 8+ characters and include at least one number.');
    return false;
  } else {
    clearError('password');
    return true;
  }
=======
  // Must be 8+ chars AND contain at least one digit
  // Update #password-strength indicator (Task 4)
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validateConfirmPassword() {
  // TODO: Get #password and #confirm-password values
<<<<<<< HEAD
  const password = document.querySelector('#password').value;
  const confirmPassword = document.querySelector('#confirm-password').value;
  
  // They must match
  if (confirmPassword === "" || confirmPassword !== password) {
    showError('confirm-password', 'Passwords do not match.');
    return false;
  } else {
    clearError('confirm-password');
    return true;
  }
=======
  // They must match
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validateAge() {
  // TODO: Get #age value (convert to Number)
<<<<<<< HEAD
  const ageValue = Number(document.querySelector('#age').value);
  
  // Must be 18–120
  if (isNaN(ageValue) || ageValue < 18 || ageValue > 120) {
    showError('age', 'You must be between 18 and 120 years old.');
    return false;
  } else {
    clearError('age');
    return true;
  }
=======
  // Must be 18–120
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validateCountry() {
  // TODO: Get #country value
<<<<<<< HEAD
  const country = document.querySelector('#country').value;
  
  // Must not be the default empty option
  if (country === "") {
    showError('country', 'Please select a country.');
    return false;
  } else {
    clearError('country');
    return true;
  }
=======
  // Must not be the default empty option
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

function validateTerms() {
  // TODO: Get #terms checkbox
<<<<<<< HEAD
  const termsCheckbox = document.querySelector('#terms');
  
  // Must be checked
  if (!termsCheckbox.checked) {
    showError('terms', 'You must accept the terms and conditions.');
    return false;
  } else {
    clearError('terms');
    return true;
  }
=======
  // Must be checked
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}


// ============================================================
// TASK 4: Password Strength Indicator
// ============================================================
function updatePasswordStrength(password) {
  // TODO: Get #password-strength element
<<<<<<< HEAD
  const strengthMeter = document.querySelector('#password-strength');
  
  // Determine strength: weak / fair / strong
  if (password.length === 0) {
    strengthMeter.textContent = '';
    strengthMeter.className = 'strength-meter';
  } else if (password.length < 8) {
    strengthMeter.textContent = 'Weak';
    strengthMeter.className = 'strength-meter weak';
  } else if (password.length >= 8 && (!/\d/.test(password) || !/[A-Z]/.test(password))) {
    strengthMeter.textContent = 'Fair';
    strengthMeter.className = 'strength-meter fair';
  } else {
    strengthMeter.textContent = 'Strong';
    strengthMeter.className = 'strength-meter strong';
  }
=======
  // Determine strength: weak / fair / strong
  // Update element's class and text
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}


// ============================================================
// TASK 5: Bio Character Counter
// ============================================================
const bioTextarea = document.querySelector('#bio');
<<<<<<< HEAD
const charCounter = document.querySelector('#char-counter');
const submitBtn = document.querySelector('#submit-btn');

// TODO: Add 'input' event listener to bioTextarea
bioTextarea.addEventListener('input', function() {
  const count = bioTextarea.value.length;
  // Update #char-count text: "X / 200 characters"
  charCounter.textContent = `${count} / 200 characters`;
  
  // If over 200: add 'over-limit' class, disable submit button
  if (count > 200) {
    charCounter.classList.add('over-limit');
    submitBtn.disabled = true;
  } else {
    charCounter.classList.remove('over-limit');
    submitBtn.disabled = false;
  }
});
=======
// TODO: Add 'input' event listener to bioTextarea
// Update #char-count text: "X / 200 characters"
// If over 200: add 'over-limit' class, disable submit button
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db


// ============================================================
// TASK 2: Attach real-time listeners
// ============================================================
// TODO: Add 'blur' (or 'input') event listeners to each field
<<<<<<< HEAD
document.querySelector('#full-name').addEventListener('input', validateName);
document.querySelector('#email').addEventListener('input', validateEmail);
document.querySelector('#password').addEventListener('input', validatePassword);
document.querySelector('#confirm-password').addEventListener('input', validateConfirmPassword);
document.querySelector('#age').addEventListener('input', validateAge);
document.querySelector('#country').addEventListener('change', validateCountry);
document.querySelector('#terms').addEventListener('change', validateTerms);
document.querySelector('#website').addEventListener('input', function() {
  const website = document.querySelector('#website');
  if (website.value !== "" && !website.value.startsWith('https://')) {
    showError('website', 'URL must start with https://');
  } else {
    clearError('website');
  }
});
=======
// that call its validator function
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db


// ============================================================
// TASK 3: Submit Handler
// ============================================================
form.addEventListener('submit', function(event) {
  event.preventDefault(); // Always prevent default first

  // TODO: Run all validators and collect results
<<<<<<< HEAD
  const results = [
    validateName(),
    validateEmail(),
    validatePassword(),
    validateConfirmPassword(),
    validateAge(),
    validateCountry(),
    validateTerms()
  ];

  const isFormValid = results.every(result => result === true);

  // TODO: If all true → show #success-message, hide form
  if (isFormValid) {
    form.classList.add('hidden');
    document.querySelector('#success-message').classList.remove('hidden');
  } else {
    // TODO: If any false → scroll to first invalid field
    const firstInvalid = document.querySelector('.invalid');
    if (firstInvalid) {
      firstInvalid.scrollIntoView({ behavior: 'smooth', block: 'center' });
    }
  }
});
=======
  // const results = [validateName(), validateEmail(), ...]

  // TODO: If all true → show #success-message, hide form
  // TODO: If any false → scroll to first invalid field
});
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
