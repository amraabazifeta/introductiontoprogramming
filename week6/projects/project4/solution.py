# Project 4 — Word Counter
# Author:  Erinda

import string

sentence = input("Enter a sentence: ")

# Bonus: strip punctuation
cleaned = sentence.lower().translate(str.maketrans("", "", string.punctuation))
words = cleaned.split()

total_words = len(words)
total_chars = len(sentence.replace(" ", ""))

frequency = {}
for word in words:
    if word in frequency:
        frequency[word] += 1
    else:
        frequency[word] = 1

# Bonus: sort by most common
sorted_freq = sorted(frequency.items(), key=lambda x: x[1], reverse=True)

print(f"Total words: {total_words}")
print(f"Total characters (no spaces): {total_chars}")
print("Word frequency:")
for word, count in sorted_freq:
    print(f"  {word:<10} -> {count}")