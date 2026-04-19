# Project 4 — Word Counter
# Author: your name here
# Branch: firstname-project4

sentence = input("Enter a sentence: ")

cleaned = ""
for ch in sentence:
    if ch.isalnum() or ch.isspace():
        cleaned += ch

words = cleaned.lower().split()

total_words = len(words)
total_characters = len(cleaned.replace(" ", ""))

frequency = {}
for word in words:
    if word in frequency:
        frequency[word] += 1
    else:
        frequency[word] = 1

print(f"Total words: {total_words}")
print(f"Total characters (no spaces): {total_characters}")
print("Word frequency:")

for word, count in sorted(frequency.items(), key=lambda x: x[1], reverse=True):
    print(f"  {word}  -> {count}")
