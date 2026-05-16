/**
 * Exercise 6: Fetch & APIs
 * =========================
 */

const quoteDisplay = document.querySelector('#quote-display');
const btnNewQuote  = document.querySelector('#btn-new-quote');

const githubInput  = document.querySelector('#github-input');
const btnSearch    = document.querySelector('#btn-search-user');
const githubResult = document.querySelector('#github-result');

const postsContainer = document.querySelector('#posts-container');
const btnLoadMore    = document.querySelector('#btn-load-more');

const btnFetchAll  = document.querySelector('#btn-fetch-all');
const multiResult  = document.querySelector('#multi-result');

let currentPage = 1;
const postsPerPage = 10;

// =========================
// UTILITIES
// =========================
function showLoading(element) {
  element.innerHTML = '<p>⏳ Loading...</p>';
}

function showError(element, message) {
  element.innerHTML = `<p style="color:red">❌ ${message}</p>`;
}

// =========================
// TASK 1 — QUOTE
// =========================
async function fetchQuote() {
  showLoading(quoteDisplay);

  try {
    const res = await fetch('https://api.quotable.io/random');
    if (!res.ok) throw new Error("HTTP Error");

    const data = await res.json();

    quoteDisplay.innerHTML = `
      <blockquote>"${data.content}"</blockquote>
      <p>— ${data.author}</p>
    `;
  } catch (err) {
    showError(quoteDisplay, "Failed to load quote");
  }
}

fetchQuote();
btnNewQuote.addEventListener('click', fetchQuote);

// =========================
// TASK 2 — GITHUB USER
// =========================
async function searchUser() {
  const username = githubInput.value.trim();
  if (!username) return;

  showLoading(githubResult);

  try {
    const res = await fetch(`https://api.github.com/users/${username}`);

    if (res.status === 404) {
      githubResult.innerHTML = "User not found";
      return;
    }

    if (!res.ok) throw new Error("Request failed");

    const data = await res.json();

    githubResult.innerHTML = `
      <img src="${data.avatar_url}" width="100" />
      <h3>${data.name || data.login}</h3>
      <p>${data.bio || "No bio"}</p>
      <p>Followers: ${data.followers}</p>
      <p>Repos: ${data.public_repos}</p>
      <a href="${data.html_url}" target="_blank">View Profile</a>
    `;

  } catch (err) {
    showError(githubResult, "Search failed");
  }
}

btnSearch.addEventListener('click', searchUser);
githubInput.addEventListener('keydown', e => {
  if (e.key === 'Enter') searchUser();
});

// =========================
// TASK 3 — POSTS
// =========================
async function loadPosts() {
  const start = (currentPage - 1) * postsPerPage;

  try {
    const res = await fetch(
      `https://jsonplaceholder.typicode.com/posts?_start=${start}&_limit=${postsPerPage}`
    );

    if (!res.ok) throw new Error("Posts failed");

    const data = await res.json();

    data.forEach(post => {
      const div = document.createElement('div');
      div.classList.add('post-card');

      div.innerHTML = `
        <h4>${post.title}</h4>
        <p>${post.body}</p>
        <div class="comments"></div>
      `;

      div.addEventListener('click', () => loadComments(post.id, div));

      postsContainer.appendChild(div);
    });

    currentPage++;

  } catch (err) {
    console.error(err);
  }
}

async function loadComments(postId, card) {
  const box = card.querySelector('.comments');

  if (box.innerHTML !== "") {
    box.innerHTML = "";
    return;
  }

  try {
    const res = await fetch(
      `https://jsonplaceholder.typicode.com/posts/${postId}/comments`
    );

    if (!res.ok) throw new Error();

    const data = await res.json();

    box.innerHTML = data
      .map(c => `<p>💬 ${c.body}</p>`)
      .join("");

  } catch (err) {
    box.innerHTML = "Failed to load comments";
  }
}

loadPosts();
btnLoadMore.addEventListener('click', loadPosts);

// =========================
// TASK 5 — PROMISE ALL
// =========================
async function fetchAllParallel() {
  showLoading(multiResult);

  try {
    const [quoteRes, userRes, todoRes] = await Promise.all([
      fetch('https://api.quotable.io/random'),
      fetch('https://jsonplaceholder.typicode.com/users/1'),
      fetch('https://jsonplaceholder.typicode.com/todos/1')
    ]);

    const [quote, user, todo] = await Promise.all([
      quoteRes.json(),
      userRes.json(),
      todoRes.json()
    ]);

    multiResult.innerHTML = `
      <h3>Quote</h3>
      <p>${quote.content} — ${quote.author}</p>

      <h3>User</h3>
      <p>${user.name}</p>

      <h3>Todo</h3>
      <p>${todo.title}</p>
    `;

  } catch (err) {
    showError(multiResult, "One or more requests failed");
  }
}

btnFetchAll.addEventListener('click', fetchAllParallel);
