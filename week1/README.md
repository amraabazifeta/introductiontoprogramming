# CS50x — Week 1: C Programming 🎓

> **This is a template repository.** Click **"Use this template"** → **"Create a new repository"** to get your own copy.

---

## 👋 Welcome

This repository contains the starter code for **CS50x Week 1 Problem Set**.  
You will write four programs in C that cover variables, loops, functions, and algorithms.

| # | Exercise | Topic | Points |
|---|----------|-------|--------|
| 1 | [Hello, It's Me](#1-hello-its-me) | `printf`, `get_string` | Required |
| 2 | [Mario (Less)](#2-mario-less-comfortable) | Nested loops, `do-while` | Required |
| 3 | [Mario (More)](#3-mario-more-comfortable) | Double pyramid | Bonus |
| 4 | [Cash](#4-cash) | Greedy algorithm | Required |
| 5 | [Credit](#5-credit) | Luhn's algorithm | Bonus / Alt |

---

## ⚙️ Setup

### Using CS50's VS Code (Recommended)
```bash
# Open cs50.dev in your browser, then clone your repo:
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME
cd YOUR_REPO_NAME
```

### Compiling
Use `make` to compile any file:
```bash
make pset1/hello/hello
make pset1/mario/mario
make pset1/cash/cash
make pset1/credit/credit
```

Or compile manually with `clang`:
```bash
cd pset1/hello
clang -o hello hello.c -lcs50
```

### Running
```bash
./hello
./mario
./cash
./credit
```

### Checking your work
```bash
check50 cs50/problems/2024/x/hello
check50 cs50/problems/2024/x/mario/less
check50 cs50/problems/2024/x/cash
check50 cs50/problems/2024/x/credit
```

---

## 📝 Exercises

---

### 1. Hello, It's Me
**File:** `pset1/hello/hello.c`

Prompt the user for their name, then greet them.

**Expected output:**
```
$ ./hello
What is your name? Alice
hello, Alice
```

**Requirements:**
- Use `get_string()` from the CS50 library
- Use `printf()` with `%s` format specifier
- Output must be exactly: `hello, [name]` with a newline

---

### 2. Mario (Less Comfortable)
**File:** `pset1/mario/mario.c`

Print a right-aligned half-pyramid of `#` symbols.

**Expected output (height = 4):**
```
$ ./mario
Height: 4
   #
  ##
 ###
####
```

**Requirements:**
- Re-prompt if height is not between 1 and 8 (inclusive)
- Use a `do-while` loop for input validation
- Use nested `for` loops to print spaces and hashes

---

### 3. Mario (More Comfortable)
**File:** `pset1/mario/mario_more.c`

Print a **double** pyramid separated by two spaces.

**Expected output (height = 4):**
```
$ ./mario_more
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

**Requirements:**
- Same input validation as Mario Less
- Exactly **two spaces** between the two halves
- Right side is a mirror of the left

---

### 4. Cash
**File:** `pset1/cash/cash.c`

Calculate the **minimum number of coins** to make change using a greedy algorithm.  
Available coins: quarters (25¢), dimes (10¢), nickels (5¢), pennies (1¢).

**Expected output:**
```
$ ./cash
Change owed: 41
4
```
*(1 quarter + 1 dime + 1 nickel + 1 penny = 4 coins)*

**Requirements:**
- Re-prompt if input is negative
- Implement the four `calculate_*` functions — do not change their signatures
- Output only the total coin count

---

### 5. Credit
**File:** `pset1/credit/credit.c`

Validate a credit card number using **Luhn's Algorithm** and identify its type.

**Expected output:**
```
$ ./credit
Number: 4003600000000014
VISA

$ ./credit
Number: 1234567890
INVALID
```

**Card types:**

| Type | Length | Starts with |
|------|--------|-------------|
| AMEX | 15 digits | 34 or 37 |
| MASTERCARD | 16 digits | 51–55 |
| VISA | 13 or 16 digits | 4 |

**Luhn's Algorithm:**
1. Starting from the **second-to-last digit**, multiply every other digit by 2
2. If the product ≥ 10, add its individual digits (e.g., 14 → 1+4 = 5)
3. Sum those results, then add the remaining (un-doubled) digits
4. If the grand total ends in **0**, the number is valid

---

## 📁 Repository Structure

```
cs50-week1/
├── README.md                  ← You are here
├── Makefile                   ← Build all exercises at once
├── pset1/
│   ├── hello/
│   │   ├── hello.c            ← TODO: your code here
│   │   └── README.md
│   ├── mario/
│   │   ├── mario.c            ← TODO: your code here
│   │   ├── mario_more.c       ← TODO (bonus)
│   │   └── README.md
│   ├── cash/
│   │   ├── cash.c             ← TODO: your code here
│   │   └── README.md
│   └── credit/
│       ├── credit.c           ← TODO: your code here
│       └── README.md
└── .github/
    ├── workflows/
    │   └── check.yml          ← Auto-checks on push
    └── ISSUE_TEMPLATE/
        └── bug_report.md
```

---

## 📬 Submitting

When you're done with each exercise:

1. **Commit your changes:**
   ```bash
   git add pset1/hello/hello.c
   git commit -m "complete hello exercise"
   git push
   ```

2. **Submit to CS50:** Go to [submit.cs50.io](https://submit.cs50.io) and follow the instructions.

3. **Check your style:**
   ```bash
   style50 pset1/hello/hello.c
   ```

---

## 💡 Tips

- **Stuck?** Check the [CS50 manual pages](https://manual.cs50.io/) for any C function
- **Ask questions** on [CS50's Ed Discussion](https://cs50.edx.org/ed)
- **Don't share code** — CS50's Academic Honesty policy applies

---

## 📜 Academic Honesty

> *"Be reasonable. The essence of all work that you submit to this course must be your own."*
>
> — CS50 Academic Honesty Policy

This template is for **learning purposes**. Do not copy solutions from others or share your completed code publicly while the course is active.

---

<p align="center">Made with ❤️ for CS50x students</p>
