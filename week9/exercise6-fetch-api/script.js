/**
 * Exercise 6: Fetch & APIs
 * =========================
 * Complete each async function below.
 * All APIs used are free and require no authentication.
 */

// ============================================================
// UTILITY: Show a loading spinner inside an element
// ============================================================
function showLoading(element) {
  element.innerHTML = '<div class="spinner"></div>';
}

function showError(element, message) {
  element.innerHTML = `<p class="error-text">❌ ${message}</p>`;
}


// ============================================================
// TASK 1 — Random Quote
// API: https://api.quotable.io/random
// ============================================================
const quoteDisplay = document.querySelector('#quote-display');
const btnNewQuote  = document.querySelector('#btn-new-quote');

async function fetchQuote() {
  showLoading(quoteDisplay);

  try {
    // TODO: fetch from 'https://api.quotable.io/random'
    const response = await fetch('https://api.quotable.io/random');
    
    // TODO: check response.ok, throw if not
    if (!response.ok) throw new Error('Failed to fetch quote');

    // TODO: parse JSON
    const data = await response.json();

    // TODO: update quoteDisplay with the quote content and author
    quoteDisplay.innerHTML = `
      <blockquote>"${data.content}"</blockquote>
      <p class="quote-author">— ${data.author}</p>
    `;

  } catch (error) {
    showError(quoteDisplay, 'Could not load quote. Check your connection.');
    console.error(error);
  }
}

// Fetch a quote when the page loads, and on button click
fetchQuote();
btnNewQuote.addEventListener('click', fetchQuote);


// ============================================================
// TASK 2 — GitHub User Search
// API: https://api.github.com/users/{username}
// ============================================================
const githubInput  = document.querySelector('#github-input');
const btnSearch    = document.querySelector('#btn-search-user');
const githubResult = document.querySelector('#github-result');

async function searchUser() {
  const username = githubInput.value.trim();
  if (!username) return;

  showLoading(githubResult);

  try {
    // TODO: fetch from `https://api.github.com/users/${username}`
    const response = await fetch(`https://api.github.com/users/${username}`);

    // TODO: If response.status === 404, show "User not found"
    if (response.status === 404) {
      githubResult.innerHTML = '<p class="error-text">User not found</p>';
      return;
    }

    // TODO: If !response.ok for other reasons, throw an error
    if (!response.ok) throw new Error('Search failed');

    // TODO: Parse JSON and display
    const data = await response.json();

    githubResult.innerHTML = `
      <div class="github-profile">
        <img src="${data.avatar_url}" alt="${data.login}" class="avatar">
        <h3>${data.name || data.login} (@${data.login})</h3>
        <p>${data.bio || 'No bio available'}</p>
        <div class="stats">
          <span>Followers: ${data.followers}</span> | 
          <span>Public Repos: ${data.public_repos}</span>
        </div>
        <a href="${data.html_url}" target="_blank" class="btn-link">View GitHub Profile</a>
      </div>
    `;

  } catch (error) {
    showError(githubResult, error.message || 'Search failed. Try again.');
  }
}

btnSearch.addEventListener('click', searchUser);
githubInput.addEventListener('keydown', (e) => { if (e.key === 'Enter') searchUser(); });


// ============================================================
// TASK 3 — Posts Feed with Pagination
// API: https://jsonplaceholder.typicode.com/posts
// ============================================================
const postsContainer = document.querySelector('#posts-container');
const btnLoadMore    = document.querySelector('#btn-load-more');
let currentPage = 1;
const postsPerPage = 10;

async function loadPosts() {
  const start = (currentPage - 1) * postsPerPage;
  
  try {
    // TODO: fetch from query params
    const response = await fetch(`https://jsonplaceholder.typicode.com/posts?_start=${start}&_limit=${postsPerPage}`);
    const posts = await response.json();

    // TODO: For each post, create a card element and append to postsContainer
    posts.forEach(post => {
      const card = document.createElement('div');
      card.className = 'post-card';
      card.innerHTML = `
        <h3>${post.title}</h3>
        <p>${post.body}</p>
        <div class="comments-area" style="display: none;"></div>
      `;
      
      // TODO: When a card is clicked, call loadComments
      card.addEventListener('click', () => loadComments(post.id, card));
      postsContainer.appendChild(card);
    });

    // TODO: Increment currentPage after success
    currentPage++;

  } catch (error) {
    console.error('Error loading posts:', error);
  }
}

async function loadComments(postId, cardElement) {
  const commentsArea = cardElement.querySelector('.comments-area');

  // Toggle: if comments already shown, hide them
  if (commentsArea.style.display === 'block') {
    commentsArea.style.display = 'none';
    return;
  }

  // TODO: fetch from comments endpoint
  try {
    commentsArea.innerHTML = '<p>Loading comments...</p>';
    commentsArea.style.display = 'block';

    const response = await fetch(`https://jsonplaceholder.typicode.com/posts/${postId}/comments`);
    const comments = await response.json();

    commentsArea.innerHTML = comments.map(c => `
      <div class="comment">
        <small>${c.email}</small>
        <p>${c.body}</p>
      </div>
    `).join('');

  } catch (error) {
    commentsArea.innerHTML = '<p>Error loading comments.</p>';
  }
}

loadPosts();
btnLoadMore.addEventListener('click', loadPosts);


// ============================================================
// TASK 5 — Promise.all: Parallel Fetches
// ============================================================
const btnFetchAll  = document.querySelector('#btn-fetch-all');
const multiResult  = document.querySelector('#multi-result');

async function fetchAllParallel() {
  showLoading(multiResult);

  try {
    // TODO: Use Promise.all to fetch all three simultaneously
    const [quoteRes, userRes, todoRes] = await Promise.all([
      fetch('https://api.quotable.io/random'),
      fetch('https://jsonplaceholder.typicode.com/users/1'),
      fetch('https://jsonplaceholder.typicode.com/todos/1')
    ]);

    const [quote, user, todo] = await Promise.all([
      quoteRes.json(), userRes.json(), todoRes.json()
    ]);
    
    // TODO: Display all three results in multiResult
    multiResult.innerHTML = `
      <div class="multi-fetch-box">
        <p><strong>Quote:</strong> ${quote.content}</p>
        <p><strong>User Name:</strong> ${user.name}</p>
        <p><strong>Todo Item:</strong> ${todo.title} - ${todo.completed ? '✅' : '❌'}</p>
      </div>
    `;

  } catch (error) {
    showError(multiResult, 'One or more requests failed.');
  }
}

btnFetchAll.addEventListener('click', fetchAllParallel);