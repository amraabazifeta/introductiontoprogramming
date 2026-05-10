# 🟢 Project 1 — Temperature Converter

**Difficulty:** Easy | **Concepts:** Variables · Arithmetic · f-strings · Type conversion

---

## 📋 Problem

Write a program that converts a temperature from **Celsius to Fahrenheit**.

**Formula:** `F = (C × 9/5) + 32`

---

## 📥 Expected Input / Output

```
Enter temperature in Celsius: 100
100.0°C = 212.0°F
```

```
Enter temperature in Celsius: 0
0.0°C = 32.0°F
```

---

## 💬 Group Discussion Questions

Before coding, talk through these with your group:

1. What data type should the user's input be? Why can't you use it directly from `input()`?
2. How do you apply the formula using Python arithmetic operators?
3. What does `f"..."` do, and why is it useful here?
4. What happens if someone types `"abc"` instead of a number?

---

## 🗂 Files

| File | What to do |
|---|---|
| `solution.py` | Write your solution here |
| `README.md` | This file — read before starting |

---

## 💻 Starter Code

```python
# Project 1 — Temperature Converter
# Author: your name here
# Branch: firstname-project1

# Step 1 — Get input from the user and convert to float
celsius = float(input("Enter temperature in Celsius: "))

# Step 2 — Apply the formula
# fahrenheit = ???

# Step 3 — Print the result using an f-string
# print(f"...")
```

---

## ✅ Peer-Learning Steps

1. **Think alone (5 min):** Read the problem, write pseudocode (plain English steps) in a comment block.
2. **Discuss in group (10 min):** Compare approaches. Agree on a plan.
3. **Teach-back:** One student explains the solution to the group before anyone codes.
4. **Code individually:** Each student writes their version on their own branch.
5. **Open a PR** using the template and request your group as reviewers.

---

## ⭐ Bonus Challenge

Add a menu so the user can choose the direction:

```
Convert: (1) Celsius → Fahrenheit  (2) Fahrenheit → Celsius
Choice: 2
Enter temperature in Fahrenheit: 98.6
98.6°F = 37.0°C
```
