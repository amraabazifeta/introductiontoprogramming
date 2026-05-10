# 🔴 Project 5 — Mini Shopping Cart

**Difficulty:** Challenging | **Concepts:** Dictionaries · Loops · Conditions · Formatting

---

## 📋 Problem

Build a text-based shopping cart. The program shows a menu, lets the user add items, tracks a running total, and prints a receipt when done.

---

## 📥 Expected Input / Output

```
--- Shop Menu ---
1. Apple    $0.50
2. Banana   $0.30
3. Milk     $1.20
4. Bread    $2.00
5. Done

Choose an item (1-5): 1
Added Apple. Total: $0.50
Choose an item (1-5): 3
Added Milk. Total: $1.70
Choose an item (1-5): 5

--- Receipt ---
Apple    x1   $0.50
Milk     x1   $1.20
---------------------
Total: $1.70
Thank you!
```

---

## 💬 Group Discussion Questions

1. How do you represent the menu? (A list? A dictionary? Both?)
2. How do you keep the program looping until the user picks "Done"?
3. How do you track quantities if the same item is selected twice?
4. How do you format currency to always show 2 decimal places? (Hint: `f"{price:.2f}"`)

---

## 💻 Starter Code

```python
# Project 5 — Mini Shopping Cart
# Author: your name here

menu = {
    1: ("Apple",  0.50),
    2: ("Banana", 0.30),
    3: ("Milk",   1.20),
    4: ("Bread",  2.00),
}

cart  = {}   # { item_name: quantity }
total = 0.0

# TODO: display the menu
# TODO: shopping loop (while True / break on choice 5)
# TODO: add item to cart, update total
# TODO: print the receipt
```

---

## ✅ Required for this PR

In your PR description, explain:
- How your cart handles duplicate items (same item chosen twice).
- What happens if the user enters an invalid number.

---

## ⭐ Bonus Challenge

- Ask "How many?" for each item instead of always adding 1.
- Apply a **10% discount** if the total exceeds $5.00.
