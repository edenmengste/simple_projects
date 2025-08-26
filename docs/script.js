// Particle Background
particlesJS('particles-js', {
  particles: {
    number: { value: 60, density: { enable: true, value_area: 800 } },
    color: { value: ['#7C4DFF', '#FF2E63', '#00F5D4'] },
    shape: { type: 'triangle' },
    opacity: { value: 0.8, random: false },
    size: { value: 5, random: true },
    move: { enable: true, speed: 1, direction: 'none', random: true }
  },
  interactivity: { enable: false }
});

// Smooth Scrolling for Navigation
document.querySelectorAll('.nav-link').forEach(link => {
  link.addEventListener('click', (e) => {
    e.preventDefault();
    const targetId = link.getAttribute('href').substring(1);
    const targetSection = document.getElementById(targetId);
    if (targetSection) {
      targetSection.scrollIntoView({ behavior: 'smooth' });
      document.querySelectorAll('section').forEach(section => {
        section.classList.add('hidden');
      });
      targetSection.classList.remove('hidden');
      if (targetId === 'home') {
        document.getElementById('quiz').classList.add('hidden');
        document.getElementById('modal').classList.add('hidden');
        document.getElementById('incorrect-modal').classList.add('hidden');
        document.body.classList.remove('quiz-active');
      }
    }
  });
});

// Quiz Data
const quizData = {
  html: [
    {
      question: "What does HTML stand for?",
      options: ["Hyper Text Markup Language", "High Text Machine Language", "Hyperlink Text Model", "Home Tool Markup Language"],
      answer: "Hyper Text Markup Language"
    },
    {
      question: "Which HTML tag is used for a paragraph?",
      options: ["<div>", "<p>", "<span>", "<section>"],
      answer: "<p>"
    },
    {
      question: "What is the purpose of the alt attribute in images?",
      options: ["Styling", "Accessibility", "Animation", "Linking"],
      answer: "Accessibility"
    },
    {
      question: "Which tag creates a hyperlink?",
      options: ["<a>", "<link>", "<href>", "<url>"],
      answer: "<a>"
    },
    {
      question: "What is the correct HTML for a line break?",
      options: ["<br>", "<lb>", "<break>", "<hr>"],
      answer: "<br>"
    }
  ],
  css: [
    {
      question: "Which CSS property controls text size?",
      options: ["font-size", "text-size", "font-style", "text-scale"],
      answer: "font-size"
    },
    {
      question: "How do you center an element horizontally in CSS?",
      options: ["margin: auto", "text-align: center", "float: center", "position: center"],
      answer: "margin: auto"
    },
    {
      question: "What does CSS stand for?",
      options: ["Cascading Style Sheets", "Creative Style System", "Colorful Style Sheets", "Computer Style Syntax"],
      answer: "Cascading Style Sheets"
    },
    {
      question: "Which property sets the background color?",
      options: ["color", "background-color", "bg-color", "fill"],
      answer: "background-color"
    },
    {
      question: "What is the default display value for a div?",
      options: ["inline", "block", "flex", "grid"],
      answer: "block"
    }
  ],
  javascript: [
    {
      question: "What is the purpose of JavaScript?",
      options: ["Styling web pages", "Structuring content", "Adding interactivity", "Managing databases"],
      answer: "Adding interactivity"
    },
    {
      question: "How do you declare a variable in JavaScript?",
      options: ["var", "let", "const", "All of the above"],
      answer: "All of the above"
    },
    {
      question: "What is the output of 2 + '2' in JavaScript?",
      options: ["4", "22", "NaN", "undefined"],
      answer: "22"
    },
    {
      question: "Which method adds an element to the end of an array?",
      options: ["push()", "pop()", "shift()", "unshift()"],
      answer: "push()"
    },
    {
      question: "What does DOM stand for?",
      options: ["Document Object Model", "Data Object Module", "Dynamic Output Method", "Document Order Model"],
      answer: "Document Object Model"
    }
  ]
};

let currentQuestion = 0;
let score = 0;
let selectedQuestions = [];
let selectedNiche = 'html';
let questionCount = 3;
let incorrectAnswers = [];

function startQuiz() {
  selectedNiche = document.getElementById('niche').value;
  questionCount = parseInt(document.getElementById('question-count').value);
  selectedQuestions = quizData[selectedNiche].slice(0, questionCount);
  incorrectAnswers = [];
  document.getElementById('home').classList.add('hidden');
  document.getElementById('register').classList.add('hidden');
  document.getElementById('quiz').classList.remove('hidden');
  document.body.classList.add('quiz-active');
  currentQuestion = 0;
  score = 0;
  displayQuestion();
}

function displayQuestion() {
  const questionEl = document.getElementById('question');
  const optionsEl = document.getElementById('options');
  const current = selectedQuestions[currentQuestion];
  questionEl.textContent = current.question;
  optionsEl.innerHTML = '';
  current.options.forEach(option => {
    const btn = document.createElement('button');
    btn.className = 'bg-[#1C2526] border border-[#6B7280] p-3 rounded-lg text-[#FFFFFF] font-inter-regular text-base hover:bg-[#00F5D4]';
    btn.textContent = option;
    btn.onclick = () => checkAnswer(option);
    optionsEl.appendChild(btn);
  });
  updateProgress();
}

function checkAnswer(selected) {
  const current = selectedQuestions[currentQuestion];
  if (selected !== current.answer) {
    incorrectAnswers.push({
      question: current.question,
      selectedAnswer: selected || 'None',
      correctAnswer: current.answer
    });
  }
  if (selected === current.answer) {
    score++;
  }
  currentQuestion++;
  if (currentQuestion < selectedQuestions.length) {
    displayQuestion();
  } else {
    showResults();
  }
}

function updateProgress() {
  const progressFill = document.getElementById('progress-fill');
  const progress = ((currentQuestion + 1) / selectedQuestions.length) * 100;
  progressFill.style.width = `${progress}%`;
}

function showResults() {
  document.getElementById('quiz').classList.add('hidden');
  document.body.classList.remove('quiz-active');
  const modal = document.getElementById('modal');
  const resultText = document.getElementById('result-text');
  resultText.textContent = `You scored ${score} out of ${selectedQuestions.length} in ${selectedNiche.toUpperCase()}! Ready to review your answers?`;
  modal.classList.remove('hidden');
}

function showIncorrectAnswers() {
  document.getElementById('modal').classList.add('hidden');
  const incorrectModal = document.getElementById('incorrect-modal');
  const incorrectAnswersEl = document.getElementById('incorrect-answers');
  incorrectAnswersEl.innerHTML = '';
  if (incorrectAnswers.length === 0) {
    incorrectAnswersEl.innerHTML = '<p class="text-base font-inter-regular text-[#0B132B]">You got all questions correct! Great job!</p>';
    // Trigger confetti for perfect score
    const confettiCanvas = document.getElementById('confetti-canvas');
    const myConfetti = confetti.create(confettiCanvas, { resize: true });
    myConfetti({
      particleCount: 100,
      spread: 70,
      origin: { y: 0.6 },
      colors: ['#7C4DFF', '#FF2E63', '#00F5D4'],
      duration: 3000
    });
  } else {
    incorrectAnswers.forEach((item, index) => {
      const div = document.createElement('div');
      div.className = 'incorrect-item';
      div.innerHTML = `
        <p class="text-base font-inter-bold text-[#0B132B]">${index + 1}. ${item.question}</p>
        <p class="text-sm font-inter-regular text-[#6B7280]">Your answer: <span class="text-[#FF2E63]">${item.selectedAnswer}</span></p>
        <p class="text-sm font-inter-regular text-[#6B7280]">Correct answer: <span class="text-[#00F5D4]">${item.correctAnswer}</span></p>
      `;
      incorrectAnswersEl.appendChild(div);
    });
  }
  incorrectModal.classList.remove('hidden');
}

function closeIncorrectModal() {
  document.getElementById('incorrect-modal').classList.add('hidden');
  document.getElementById('home').classList.remove('hidden');
  document.getElementById('register').classList.add('hidden');
  document.body.classList.remove('quiz-active');
  currentQuestion = 0;
  score = 0;
  selectedQuestions = [];
  incorrectAnswers = [];
  // Clear confetti canvas
  const confettiCanvas = document.getElementById('confetti-canvas');
  confettiCanvas.getContext('2d').clearRect(0, 0, confettiCanvas.width, confettiCanvas.height);
}

function closeModal() {
  document.getElementById('modal').classList.add('hidden');
  document.getElementById('home').classList.remove('hidden');
  document.getElementById('register').classList.add('hidden');
  document.body.classList.remove('quiz-active');
  currentQuestion = 0;
  score = 0;
  selectedQuestions = [];
  incorrectAnswers = [];
}

function nextQuestion() {
  checkAnswer(null);
}

// Sign-In/Sign-Up Form Toggle
function showForm(formType) {
  const signinForm = document.getElementById('signin-form');
  const signupForm = document.getElementById('signup-form');
  const signinTab = document.getElementById('signin-tab');
  const signupTab = document.getElementById('signup-tab');

  if (formType === 'signin') {
    signinForm.classList.remove('hidden');
    signupForm.classList.add('hidden');
    signinTab.classList.add('active');
    signupTab.classList.remove('active');
  } else {
    signinForm.classList.add('hidden');
    signupForm.classList.remove('hidden');
    signinTab.classList.remove('active');
    signupTab.classList.add('active');
  }
}

// Form Submission Handlers
document.getElementById('signin-form').addEventListener('submit', (e) => {
  e.preventDefault();
  const email = document.getElementById('signin-email').value;
  const password = document.getElementById('signin-password').value;
  console.log('Sign In:', { email, password });
  // Placeholder for backend integration
});

document.getElementById('signup-form').addEventListener('submit', (e) => {
  e.preventDefault();
  const username = document.getElementById('signup-username').value;
  const email = document.getElementById('signup-email').value;
  const password = document.getElementById('signup-password').value;
  console.log('Sign Up:', { username, email, password });
  // Placeholder for backend integration
});