# CS50x — Week 2: Arrays 🔐

> **This is a template repository.** Click **"Use this template"** → **"Create a new repository"** to get your own copy.

---

## 👋 Welcome to Week 2

This week's theme is **Arrays**, **Strings**, and **Cryptography**. You'll write programs that iterate through characters, apply formulas, and implement real ciphers used throughout history.

| # | Exercise | Topic | Status |
|---|----------|-------|--------|
| 1 | [Scrabble](#1-scrabble) | Arrays, ASCII math | Required |
| 2 | [Readability](#2-readability) | Strings, loops, math formula | Required |
| 3 | [Caesar](#3-caesar) | Command-line args, cipher | Pick one |
| 4 | [Substitution](#4-substitution) | Command-line args, cipher | Pick one ↑ |

> **Note:** Submit both Caesar and Substitution if you like — CS50 will keep your higher score.

---

## ⚙️ Setup

```bash
# Clone your repo after using the template
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME
cd YOUR_REPO_NAME
```

### Compile & Run
```bash
make pset2/scrabble/scrabble    &&  ./pset2/scrabble/scrabble
make pset2/readability/readability  &&  ./pset2/readability/readability
make pset2/caesar/caesar            &&  ./pset2/caesar/caesar 3
make pset2/substitution/substitution &&  ./pset2/substitution/substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
```

Or build everything at once:
```bash
make all
```

### Check your work
```bash
check50 cs50/problems/2024/x/scrabble
check50 cs50/problems/2024/x/readability
check50 cs50/problems/2024/x/caesar
check50 cs50/problems/2024/x/substitution
```

### Style check
```bash
style50 pset2/scrabble/scrabble.c
```

---

## New C Concepts This Week

| Concept | What it is |
|---------|-----------|
| `string` indexing | Access individual chars: `text[i]` |
| `strlen()` | Returns the length of a string |
| `isupper()` / `islower()` | Check if a char is upper/lowercase |
| `toupper()` / `tolower()` | Convert char case |
| `isalpha()` / `isdigit()` | Check char type |
| `argc` / `argv` | Command-line arguments |
| `atoi()` | Convert string to integer |
| `round()` | Round a float to nearest int |

---

## 📝 Exercises

---

### 1. Scrabble
**File:** `pset2/scrabble/scrabble.c`

Two players each enter a word. Your program computes each word's Scrabble score and announces the winner.

**Letter point values (standard Scrabble):**

| Points | Letters |
|--------|---------|
| 1 | A, E, I, O, U, L, N, S, T, R |
| 2 | D, G |
| 3 | B, C, M, P |
| 4 | F, H, V, W, Y |
| 5 | K |
| 8 | J, X |
| 10 | Q, Z |

The POINTS array maps index 0→A, 1→B, ... 25→Z.

**Expected output:**
```
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!

$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```

**Requirements:**
- Prompt for both words using `get_string()`
- Implement `compute_score(string word)` — do not change its signature
- Ignore non-letter characters (they score 0)
- Case-insensitive: `A` and `a` have the same value
- Print `Player 1 wins!`, `Player 2 wins!`, or `Tie!`

---

### 2. Readability
**File:** `pset2/readability/readability.c`

Compute the **Coleman-Liau index** of a text sample to determine its reading grade level.

**The formula:**
```
index = 0.0588 * L - 0.296 * S - 15.8
```
Where:
- **L** = average number of letters per 100 words
- **S** = average number of sentences per 100 words

**Expected output:**
```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3

$ ./readability
Text: Harry Potter was a highly unusual boy in many ways...
Grade 5
```

**Output rules:**
- If index ≥ 16 → print `Grade 16+`
- If index < 1  → print `Before Grade 1`
- Otherwise      → print `Grade X`

**Requirements:**
- Count **letters**: any `a-z` or `A-Z` character
- Count **words**: number of spaces + 1 (assume no leading/trailing spaces)
- Count **sentences**: occurrences of `.`, `!`, or `?`
- Implement `count_letters()`, `count_words()`, `count_sentences()` — do not change signatures
- Use `round()` from `<math.h>`; compile with `-lm`

---

### 3. Caesar
**File:** `pset2/caesar/caesar.c`

Encrypt a message using the **Caesar cipher** — shift each letter forward in the alphabet by a given key.

```
A → D  (key = 3)
B → E
Z → C  (wraps around!)
```

**The program takes the key as a command-line argument:**
```
$ ./caesar 13
plaintext:  hello
ciphertext: uryyb

$ ./caesar
Usage: ./caesar key

$ ./caesar abc
Usage: ./caesar key
```

**Requirements:**
- Validate that `argc == 2` and `argv[1]` contains only digits
- Convert `argv[1]` to int using `atoi()`
- Prompt for plaintext with `get_string("plaintext:  ")`
- Preserve case: uppercase stays uppercase, lowercase stays lowercase
- Do not shift non-letter characters (spaces, punctuation stay the same)
- Print `ciphertext: ` followed by the encrypted string

**The math:**
```c
// For uppercase letter c, shifted by key k:
char encrypted = (c - 'A' + k) % 26 + 'A';

// For lowercase letter c, shifted by key k:
char encrypted = (c - 'a' + k) % 26 + 'a';
```

---

### 4. Substitution
**File:** `pset2/substitution/substitution.c`

Encrypt a message using a **substitution cipher** — a 26-character key where each letter maps to a different letter.

```
Key:   VCHPRZGJNTLSKFBDQWAXEUYMOI
A→V, B→C, C→H, D→P, ...

"hello, world" → "jrssb, ybwsp"
```

**Expected output:**
```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp

$ ./substitution
Usage: ./substitution key

$ ./substitution ABC
Usage: ./substitution key
```

**Requirements:**
- Key must be exactly 26 alphabetic characters (case-insensitive)
- Key must contain each letter exactly once (no duplicates)
- Preserve case of the original letter (if `H` → `J` then `h` → `j`)
- Non-letter characters are unchanged
- Validate key thoroughly — print `Usage: ./substitution key` if invalid

---

## 📁 Repository Structure

```
cs50-week2/
├── README.md
├── Makefile
├── pset2/
│   ├── scrabble/
│   │   ├── scrabble.c         ← TODO: implement compute_score()
│   │   └── README.md
│   ├── readability/
│   │   ├── readability.c      ← TODO: implement count_* functions
│   │   └── README.md
│   ├── caesar/
│   │   ├── caesar.c           ← TODO: implement cipher logic
│   │   └── README.md
│   └── substitution/
│       ├── substitution.c     ← TODO: implement key validation + cipher
│       └── README.md
└── .github/
    ├── workflows/check.yml    ← Auto-compiles on every push
    └── ISSUE_TEMPLATE/
        └── bug_report.md
```

---

## 📬 Submitting

```bash
# After completing each exercise:
git add pset2/scrabble/scrabble.c
git commit -m "complete scrabble"
git push

# Submit to CS50:
submit50 cs50/problems/2024/x/scrabble
submit50 cs50/problems/2024/x/readability
submit50 cs50/problems/2024/x/caesar
# or
submit50 cs50/problems/2024/x/substitution
```

---

## 💡 Tips

- **ASCII trick:** `'A'` is 65, `'a'` is 97. Subtracting the base letter gives you a 0-25 index.
- **`isupper(c)`** and **`islower(c)`** from `<ctype.h>` are your friends this week.
- **`strlen(s)`** from `<string.h>` returns the number of characters (not counting `\0`).
- **For Caesar/Substitution**, handle uppercase and lowercase separately.
- **`atoi()`** from `<stdlib.h>` converts a string like `"13"` to the integer `13`.

---

## 📜 Academic Honesty

> *"Be reasonable. The essence of all work that you submit must be your own."*  
> — CS50 Academic Honesty Policy

Do not share solutions publicly while the course is active.

---

<p align="center">Made with ❤️ for CS50x students · Week 2: Arrays</p>
