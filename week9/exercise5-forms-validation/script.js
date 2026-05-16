const form = document.querySelector('#registration-form');
const submitBtn = form.querySelector('button[type="submit"]');

// ===============================
// HELPER FUNCTIONS
// ===============================
function showError(inputId, message) {
  const input = document.querySelector(`#${inputId}`);
  const error = input.parentElement.querySelector('.error-msg');

  input.classList.add('invalid');
  input.classList.remove('valid');

  error.textContent = message;
}

function clearError(inputId) {
  const input = document.querySelector(`#${inputId}`);
  const error = input.parentElement.querySelector('.error-msg');

  input.classList.remove('invalid');
  input.classList.add('valid');

  error.textContent = "";
}

// ===============================
// VALIDATORS
// ===============================
function validateName() {
  const value = document.querySelector('#full-name').value.trim();

  if (value.length < 2) {
    showError('full-name', 'Name must be at least 2 characters');
    return false;
  }

  clearError('full-name');
  return true;
}

function validateEmail() {
  const value = document.querySelector('#email').value.trim();
  const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

  if (!regex.test(value)) {
    showError('email', 'Enter a valid email');
    return false;
  }

  clearError('email');
  return true;
}

function validatePassword() {
  const value = document.querySelector('#password').value;

  const hasNumber = /\d/.test(value);

  updatePasswordStrength(value);

  if (value.length < 8 || !hasNumber) {
    showError('password', 'Password must be 8+ chars and include a number');
    return false;
  }

  clearError('password');
  return true;
}

function validateConfirmPassword() {
  const pass = document.querySelector('#password').value;
  const confirm = document.querySelector('#confirm-password').value;

  if (pass !== confirm) {
    showError('confirm-password', 'Passwords do not match');
    return false;
  }

  clearError('confirm-password');
  return true;
}

function validateAge() {
  const value = Number(document.querySelector('#age').value);

  if (value < 18 || value > 120) {
    showError('age', 'Age must be between 18 and 120');
    return false;
  }

  clearError('age');
  return true;
}

function validateCountry() {
  const value = document.querySelector('#country').value;

  if (value === "") {
    showError('country', 'Please select a country');
    return false;
  }

  clearError('country');
  return true;
}

function validateTerms() {
  const checked = document.querySelector('#terms').checked;

  if (!checked) {
    showError('terms', 'You must accept the terms');
    return false;
  }

  clearError('terms');
  return true;
}

// ===============================
// PASSWORD STRENGTH
// ===============================
function updatePasswordStrength(password) {
  const bar = document.querySelector('#password-strength');

  let strength = "Weak";

  if (password.length >= 8 && /\d/.test(password) && /[A-Z]/.test(password)) {
    strength = "Strong";
    bar.className = "strong";
  } else if (password.length >= 8) {
    strength = "Fair";
    bar.className = "fair";
  } else {
    bar.className = "weak";
  }

  bar.textContent = `Strength: ${strength}`;
}

// ===============================
// BIO COUNTER
// ===============================
const bioTextarea = document.querySelector('#bio');
const charCount = document.querySelector('#char-count');

bioTextarea.addEventListener('input', () => {
  const len = bioTextarea.value.length;

  charCount.textContent = `${len} / 200 characters`;

  if (len > 200) {
    charCount.classList.add('over-limit');
    submitBtn.disabled = true;
  } else {
    charCount.classList.remove('over-limit');
    submitBtn.disabled = false;
  }
});

// ===============================
// REAL-TIME EVENTS
// ===============================
document.querySelector('#full-name').addEventListener('blur', validateName);
document.querySelector('#email').addEventListener('blur', validateEmail);
document.querySelector('#password').addEventListener('input', validatePassword);
document.querySelector('#confirm-password').addEventListener('blur', validateConfirmPassword);
document.querySelector('#age').addEventListener('blur', validateAge);
document.querySelector('#country').addEventListener('change', validateCountry);
document.querySelector('#terms').addEventListener('change', validateTerms);

// ===============================
// SUBMIT HANDLER
// ===============================
form.addEventListener('submit', (event) => {
  event.preventDefault();

  const results = [
    validateName(),
    validateEmail(),
    validatePassword(),
    validateConfirmPassword(),
    validateAge(),
    validateCountry(),
    validateTerms()
  ];

  if (results.every(Boolean)) {
    document.querySelector('#success-message').style.display = 'block';
    form.style.display = 'none';
  } else {
    const firstError = document.querySelector('.invalid');
    if (firstError) firstError.scrollIntoView({ behavior: "smooth" });
  }
});
