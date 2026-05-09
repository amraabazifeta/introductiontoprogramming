/**
 * Exercise 6: Fetch & APIs
 */

function showLoading(element) {
    element.innerHTML = '<div class="spinner"></div>';
}

function showError(element, message) {
    element.innerHTML = `<p class="error-text">❌ ${message}</p>`;
}

// ============================================================
// TASK 1 — Random Quote
// ============================================================
const quoteDisplay = document.querySelector('#quote-display');
const btnNewQuote  = document.querySelector('#btn-new-quote');

async function fetchQuote() {
    showLoading(quoteDisplay);
    try {
        const response = await fetch('https://api.quotable.io/random');
        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const data = await response.json();
        quoteDisplay.innerHTML = `
            <blockquote>"${data.content}"</blockquote>
            <p class="quote-author">— ${data.author}</p>
        `;
    } catch (error) {
        showError(quoteDisplay, 'Could not load quote. Check your connection.');
        console.error(error);
    }
}

fetchQuote();
btnNewQuote.addEventListener('click', fetchQuote);


// ============================================================
// TASK 2 — GitHub User Search
// ============================================================
const githubInput  = document.querySelector('#github-input');
const btnSearch    = document.querySelector('#btn-search-user');
const githubResult = document.querySelector('#github-result');

async function searchUser() {
    const username = githubInput.value.trim();
    if (!username) return;

    showLoading(githubResult);

    try {
        const response = await fetch(`https://api.github.com/users/${username}`);
        if (response.status === 404) {
            showError(githubResult, 'User not found. Check the username and try again.');
            return;
        }
        if (!response.ok) throw new Error(`HTTP ${response.status}`);

        const data = await response.json();
        githubResult.innerHTML = `
            <div class="github-card">
                <img src="${data.avatar_url}" alt="Avatar of ${data.login}" />
                <div class="github-info">
                    <h3>${data.name || data.login}</h3>
                    <p>@${data.login}</p>
                    <p>${data.bio || 'No bio available.'}</p>
                    <div class="github-stats">
                        <span>👥 ${data.followers} followers</span>
                        <span>📦 ${data.public_repos} repos</span>
                    </div>
                    <p><a href="${data.html_url}" target="_blank">View GitHub Profile →</a></p>
                </div>
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
// ============================================================
const postsContainer = document.querySelector('#posts-container');
const btnLoadMore    = document.querySelector('#btn-load-more');
let currentPage = 1;
const postsPerPage = 10;

async function loadPosts() {
    const start = (currentPage - 1) * postsPerPage;
    try {
        const response = await fetch(
            `https://jsonplaceholder.typicode.com/posts?_start=${start}&_limit=${postsPerPage}`
        );
        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const posts = await response.json();

        if (posts.length === 0) {
            btnLoadMore.textContent = 'No more posts';
            btnLoadMore.disabled = true;
            return;
        }

        posts.forEach(post => {
            const card = document.createElement('div');
            card.classList.add('post-card');
            card.innerHTML = `
                <h3>${post.title}</h3>
                <p>${post.body}</p>
            `;
            card.addEventListener('click', () => loadComments(post.id, card));
            postsContainer.appendChild(card);
        });

        currentPage++;
    } catch (error) {
        showError(postsContainer, 'Could not load posts. Try again.');
    }
}

async function loadComments(postId, cardElement) {
    const existing = cardElement.querySelector('.comments-list');
    if (existing) {
        existing.remove();
        return;
    }

    try {
        const response = await fetch(
            `https://jsonplaceholder.typicode.com/posts/${postId}/comments`
        );
        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const comments = await response.json();

        const commentsList = document.createElement('div');
        commentsList.classList.add('comments-list');
        comments.forEach(comment => {
            const div = document.createElement('div');
            div.classList.add('comment');
            div.innerHTML = `<strong>${comment.name}</strong><p>${comment.body}</p>`;
            commentsList.appendChild(div);
        });
        cardElement.appendChild(commentsList);
    } catch (error) {
        console.error('Could not load comments:', error);
    }
}

loadPosts();
btnLoadMore.addEventListener('click', loadPosts);


// ============================================================
// TASK 5 — Promise.all: Parallel Fetches
// ============================================================
const btnFetchAll = document.querySelector('#btn-fetch-all');
const multiResult = document.querySelector('#multi-result');

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
            <div class="multi-grid">
                <div class="multi-card">
                    <h4>🗣️ Quote</h4>
                    <p><em>"${quote.content}"</em></p>
                    <p>— ${quote.author}</p>
                </div>
                <div class="multi-card">
                    <h4>👤 User</h4>
                    <p><strong>${user.name}</strong></p>
                    <p>${user.email}</p>
                    <p>${user.company.name}</p>
                </div>
                <div class="multi-card">
                    <h4>✅ Todo</h4>
                    <p>${user.name}'s task:</p>
                    <p>${todo.title}</p>
                    <p>Status: ${todo.completed ? '✅ Done' : '⏳ Pending'}</p>
                </div>
            </div>
        `;
    } catch (error) {
        showError(multiResult, 'One or more requests failed.');
    }
}

btnFetchAll.addEventListener('click', fetchAllParallel);