# 🟡 Project 2 — Number Guessing Game

**Difficulty:** Easy–Medium | **Concepts:** while loop · Conditions · random · Counters

---

## 📋 Problem

The program picks a secret number between 1 and 10. The user guesses until they get it right. Each wrong guess tells them if they were too high or too low.

---

## 📥 Expected Input / Output

```
Guess a number between 1 and 10: 5
Too low! Try again: 8
Too high! Try again: 7
Correct! You got it in 3 guesses.
```

---

## 💬 Group Discussion Questions

1. How do you make Python pick a random number? (Hint: `import random`)
2. Should you use a `for` loop or a `while` loop? What is the key difference?
3. How do you count the number of guesses? Where do you increment the counter?
4. What condition makes the loop stop?

---

## 💻 Starter Code

```python
# Project 2 — Number Guessing Game
# Author: your name here

import random

# Step 1 — Pick a random number between 1 and 10 (inclusive)
secret = random.randint(1, 10)

# Step 2 — Set up a counter
guesses = 0

# Step 3 — Ask the user for their first guess
guess = int(input("Guess a number between 1 and 10: "))

# Step 4 — Loop until the guess is correct
# while ???:
#     guesses += 1
#     ...

print(f"Correct! You got it in {guesses} guesses.")
```

---

## ⭐ Bonus Challenge

Add difficulty levels:

```
Choose difficulty: (1) Easy 1-10  (2) Medium 1-50  (3) Hard 1-100
```
