# 🟠 Project 4 — Word Counter

**Difficulty:** Medium–Challenging | **Concepts:** Strings · Loops · Dictionaries

---

## 📋 Problem

Ask the user to type a sentence. Count:
- Total number of words
- Total characters (excluding spaces)
- How many times each unique word appears

---

## 📥 Expected Input / Output

```
Enter a sentence: the cat sat on the mat the cat
Total words: 8
Total characters (no spaces): 26
Word frequency:
  the  -> 3
  cat  -> 2
  sat  -> 1
  on   -> 1
  mat  -> 1
```

---

## 💬 Group Discussion Questions

1. How do you split a sentence into a list of words? (Hint: `.split()`)
2. What data structure can store word -> count pairs? (Hint: dictionary `{}`)
3. How do you handle "The" and "the" as the same word? (Hint: `.lower()`)
4. How do you check if a key already exists in a dictionary?

---

## 💻 Starter Code

```python
# Project 4 — Word Counter
# Author: your name here

sentence = input("Enter a sentence: ")
words = sentence.lower().split()   # split into a list of lowercase words

# TODO: count total words (hint: len())
# TODO: count total characters without spaces (hint: remove spaces first)
# TODO: build a word frequency dictionary
#   frequency = {}
#   for word in words:
#       if word in frequency:
#           ...
#       else:
#           ...
# TODO: print all results
```

---

## ⭐ Bonus Challenge

- Strip punctuation (commas, periods, `!`, `?`) before counting.
- Sort the word frequency output from most to least common.
