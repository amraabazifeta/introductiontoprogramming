# Exercise 6 — Fetch & APIs 🌍

> **Difficulty:** 🔴 Advanced  
> **Topics:** `fetch()`, `async`/`await`, JSON, REST APIs, error handling, loading states

---

## 🎯 Learning Objectives

- Use `fetch()` to make HTTP GET requests from the browser
- Use `async`/`await` to handle asynchronous code
- Parse JSON responses with `.json()`
- Handle errors gracefully (network errors, 404s, API errors)
- Show loading spinners while data is being fetched
- Render API data dynamically into the DOM

---

## 📋 Tasks

All tasks use **free, no-auth-required public APIs**.

### Task 1 — Your First Fetch
In `script.js`, complete the `fetchQuote()` function:
- Fetch from `https://api.quotable.io/random`
- Display the `content` and `author` in the `#quote-display` div
- Add a loading spinner while fetching
- Handle errors: show an error message if the request fails

**Expected response shape:**
```json
{
  "content": "The journey of a thousand miles begins with one step.",
  "author": "Lao Tzu"
}
```

### Task 2 — Search Users (GitHub API)
Complete the `searchUser()` function:
- When the user types in `#github-input` and clicks Search (or presses Enter)
- Fetch from `https://api.github.com/users/{username}`
- Display: avatar, name, bio, followers, public repos, link to profile
- Show "User not found" for a 404 response
- Show a loading state while fetching

**Expected response fields:** `avatar_url`, `name`, `login`, `bio`, `followers`, `public_repos`, `html_url`

### Task 3 — Browse Posts (JSONPlaceholder)
Complete the `loadPosts()` function:
- Fetch from `https://jsonplaceholder.typicode.com/posts?_limit=10`
- Render each post as a card showing `title` and `body`
- Add a "Load More" button that fetches the next 10 posts (use `_start` and `_limit` query params)
- Clicking a post card fetches its comments from `https://jsonplaceholder.typicode.com/posts/{id}/comments` and displays them in a modal or below the card

### Task 4 — Error Handling
Your fetch functions must handle these cases gracefully (no unhandled promise rejections!):
- Network failure (no internet) → show user-friendly message
- 404 Not Found → "That resource doesn't exist"
- Server error (5xx) → "Something went wrong, please try again"
- Empty response → show appropriate message

Use try/catch around all async operations.

### Task 5 — Promise.all (Bonus)
In `#multi-fetch-section`, fetch these three endpoints simultaneously using `Promise.all()`:
- `https://api.quotable.io/random` (a quote)
- `https://jsonplaceholder.typicode.com/users/1` (a user)
- `https://jsonplaceholder.typicode.com/todos/1` (a todo)

Display all three results at once, and show a single loading state until all three resolve.

---

## 📁 Files

```
exercise6-fetch-api/
├── README.md
├── index.html      ← Provided
├── style.css       ← Provided
├── script.js       ← Your work goes here
└── solution/
    └── script.js
```

---

## ✅ Done When...

- [ ] Random quote loads on page load and on button click
- [ ] GitHub user search shows profile info or "not found" message
- [ ] Post list loads with pagination working
- [ ] Post comments appear when a post is clicked
- [ ] All fetch calls have try/catch error handling
- [ ] Loading indicators appear while requests are in flight

---

## 💡 Hints

```javascript
// Basic fetch pattern
async function getData() {
  try {
    const response = await fetch('https://api.example.com/data');
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    const data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('Fetch failed:', error.message);
  }
}

// Check response status
if (response.status === 404) { /* not found */ }
if (!response.ok) { /* any non-2xx status */ }
```

- The browser console shows failed network requests in the Network tab
- Test error handling by searching for a non-existent GitHub username like `xxxxxxxxxxx99999`
- `Promise.all([p1, p2, p3])` resolves when all three resolve, rejects if any one rejects
