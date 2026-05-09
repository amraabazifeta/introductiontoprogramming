const form = document.querySelector('#registration-form');
const submitBtn = document.querySelector('#submit-btn');

// ============================================================
// HELPERS
// ============================================================
function showError(inputId, message) {
    const input = document.querySelector('#' + inputId);
    const error = document.querySelector('#error-' + inputId);
    input.classList.add('invalid');
    input.classList.remove('valid');
    if (error) error.textContent = message;
}

function clearError(inputId) {
    const input = document.querySelector('#' + inputId);
    const error = document.querySelector('#error-' + inputId);
    input.classList.remove('invalid');
    input.classList.add('valid');
    if (error) error.textContent = '';
}

// ============================================================
// VALIDATORS
// ============================================================
function validateName() {
    const value = document.querySelector('#full-name').value.trim();
    if (value.length < 2) {
        showError('full-name', 'Name must be at least 2 characters.');
        return false;
    }
    clearError('full-name');
    return true;
}

function validateEmail() {
    const value = document.querySelector('#email').value.trim();
    const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!regex.test(value)) {
        showError('email', 'Please enter a valid email address.');
        return false;
    }
    clearError('email');
    return true;
}

function validatePassword() {
    const value = document.querySelector('#password').value;
    updatePasswordStrength(value);
    if (value.length < 8) {
        showError('password', 'Password must be at least 8 characters.');
        return false;
    }
    if (!/\d/.test(value)) {
        showError('password', 'Password must contain at least one number.');
        return false;
    }
    clearError('password');
    return true;
}

function validateConfirmPassword() {
    const password = document.querySelector('#password').value;
    const confirm = document.querySelector('#confirm-password').value;
    if (password !== confirm) {
        showError('confirm-password', 'Passwords do not match.');
        return false;
    }
    clearError('confirm-password');
    return true;
}

function validateAge() {
    const value = Number(document.querySelector('#age').value);
    if (!value || value < 18 || value > 120) {
        showError('age', 'Age must be between 18 and 120.');
        return false;
    }
    clearError('age');
    return true;
}

function validateWebsite() {
    const value = document.querySelector('#website').value.trim();
    if (value === '') return true;
    if (!value.startsWith('https://')) {
        showError('website', 'Website must start with https://');
        return false;
    }
    clearError('website');
    return true;
}

function validateCountry() {
    const value = document.querySelector('#country').value;
    if (!value) {
        showError('country', 'Please select a country.');
        return false;
    }
    clearError('country');
    return true;
}

function validateTerms() {
    const checked = document.querySelector('#terms').checked;
    if (!checked) {
        showError('terms', 'You must accept the terms and conditions.');
        return false;
    }
    clearError('terms');
    return true;
}

// ============================================================
// TASK 4: Password Strength
// ============================================================
function updatePasswordStrength(password) {
    const bar = document.querySelector('#password-strength');
    bar.classList.remove('hidden', 'weak', 'fair', 'strong');

    if (password.length === 0) {
        bar.classList.add('hidden');
        return;
    }

    const hasNumber = /\d/.test(password);
    const hasUpper = /[A-Z]/.test(password);

    if (password.length >= 8 && hasNumber && hasUpper) {
        bar.classList.add('strong');
        bar.textContent = 'Strong 💪';
    } else if (password.length >= 8) {
        bar.classList.add('fair');
        bar.textContent = 'Fair 👍';
    } else {
        bar.classList.add('weak');
        bar.textContent = 'Weak ❌';
    }
}

// ============================================================
// TASK 5: Bio Character Counter
// ============================================================
const bioTextarea = document.querySelector('#bio');
const charCount = document.querySelector('#char-count');

bioTextarea.addEventListener('input', function() {
    const length = bioTextarea.value.length;
    charCount.textContent = length + ' / 200 characters';
    if (length > 200) {
        charCount.classList.add('over-limit');
        submitBtn.disabled = true;
    } else {
        charCount.classList.remove('over-limit');
        submitBtn.disabled = false;
    }
});

// ============================================================
// TASK 2: Real-time listeners
// ============================================================
document.querySelector('#full-name').addEventListener('blur', validateName);
document.querySelector('#email').addEventListener('blur', validateEmail);
document.querySelector('#password').addEventListener('input', validatePassword);
document.querySelector('#confirm-password').addEventListener('blur', validateConfirmPassword);
document.querySelector('#age').addEventListener('blur', validateAge);
document.querySelector('#website').addEventListener('blur', validateWebsite);
document.querySelector('#country').addEventListener('change', validateCountry);
document.querySelector('#terms').addEventListener('change', validateTerms);

// ============================================================
// TASK 3: Submit Handler
// ============================================================
form.addEventListener('submit', function(event) {
    event.preventDefault();

    const results = [
        validateName(),
        validateEmail(),
        validatePassword(),
        validateConfirmPassword(),
        validateAge(),
        validateWebsite(),
        validateCountry(),
        validateTerms()
    ];

    if (results.every(Boolean)) {
        document.querySelector('#success-message').classList.remove('hidden');
        form.classList.add('hidden');
    } else {
        const firstInvalid = form.querySelector('.invalid');
        if (firstInvalid) firstInvalid.scrollIntoView({ behavior: 'smooth' });
    }
});