/**
 * script.js — Final Project: Quiz App
 * ===================================
 */

// --- State Management ---
let questions = [];
let currentIndex = 0;
let score = 0;
let timer = null;
let timeLeft = 30;

// --- DOM Elements ---
const startScreen = document.getElementById('start-screen');
const quizScreen = document.getElementById('quiz-screen');
const resultScreen = document.getElementById('result-screen');
const optionsContainer = document.getElementById('options-container');
const questionText = document.getElementById('question-text');
const progressText = document.getElementById('progress');
const timeDisplay = document.getElementById('seconds');
const topScoreText = document.getElementById('top-score');
const finalScoreText = document.getElementById('final-score');

// --- Initialization ---
function init() {
  const savedBest = localStorage.getItem('quiz_high_score') || 0;
  if (topScoreText) topScoreText.textContent = savedBest;
}

// --- TASK: Async/Await Fetch with Try/Catch ---
async function fetchQuestions() {
  updateStatus("Loading questions...");
  try {
    const response = await fetch('https://opentdb.com/api.php?amount=10&type=multiple');
    if (!response.ok) throw new Error("Could not fetch quiz data");
    
    const data = await response.json();
    questions = data.results;
    
    if (questions.length > 0) {
      startQuiz();
    } else {
      throw new Error("No questions found");
    }
  } catch (err) {
    updateStatus("Error: " + err.message + ". Please try again.");
  }
}

// --- Modular Functions ---

function startQuiz() {
  startScreen.classList.add('hidden');
  resultScreen.classList.add('hidden');
  quizScreen.classList.remove('hidden');
  currentIndex = 0;
  score = 0;
  showQuestion();
}

function showQuestion() {
  stopTimer();
  resetTimer();
  
  const current = questions[currentIndex];
  questionText.innerHTML = current.question;
  progressText.textContent = `Question ${currentIndex + 1} of 10`;
  
  // Combine correct and incorrect answers then shuffle
  const choices = [...current.incorrect_answers, current.correct_answer]
                  .sort(() => Math.random() - 0.5);
  
  optionsContainer.innerHTML = '';
  choices.forEach(choice => {
    const btn = document.createElement('button');
    btn.className = 'option-btn';
    btn.innerHTML = choice;
    btn.addEventListener('click', () => handleAnswer(choice, current.correct_answer));
    optionsContainer.appendChild(btn);
  });
  
  startTimer();
}

function handleAnswer(selected, correct) {
  stopTimer();
  const buttons = optionsContainer.querySelectorAll('.option-btn');
  
  buttons.forEach(btn => {
    btn.disabled = true;
    if (btn.innerHTML === correct) {
      btn.classList.add('correct');
    } else if (btn.innerHTML === selected) {
      btn.classList.add('wrong');
    }
  });

  if (selected === correct) {
    score++;
  }
  
  // Wait 1.5 seconds before next question for UX
  setTimeout(() => {
    currentIndex++;
    if (currentIndex < 10) {
      showQuestion();
    } else {
      endQuiz();
    }
  }, 1500);
}

// --- Timer Logic ---
function startTimer() {
  timer = setInterval(() => {
    timeLeft--;
    timeDisplay.textContent = timeLeft;
    if (timeLeft <= 0) {
      stopTimer();
      handleAnswer(null, questions[currentIndex].correct_answer);
    }
  }, 1000);
}

function stopTimer() {
  if (timer) clearInterval(timer);
}

function resetTimer() {
  timeLeft = 30;
  timeDisplay.textContent = timeLeft;
}

// --- TASK: localStorage Usage ---
function endQuiz() {
  quizScreen.classList.add('hidden');
  resultScreen.classList.remove('hidden');
  finalScoreText.textContent = score;
  
  const savedHigh = parseInt(localStorage.getItem('quiz_high_score')) || 0;
  if (score > savedHigh) {
    localStorage.setItem('quiz_high_score', score);
    if (topScoreText) topScoreText.textContent = score;
  }
}

function updateStatus(msg) {
  // Use existing text element to show status instead of alert()
  questionText.textContent = msg;
}

// --- Event Listeners ---
document.getElementById('start-btn').addEventListener('click', fetchQuestions);
document.getElementById('restart-btn').addEventListener('click', fetchQuestions);

// Run init on load
init();