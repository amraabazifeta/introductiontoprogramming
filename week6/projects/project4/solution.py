# Project 4 — Word Counter
# Author: Muhammed Soykan Tekin

sentence = input("Enter a sentence: ")
words = sentence.lower().split()

# total word count
word_count = len(words)

# character count (no spaces)
char_count = len(sentence.replace(" ", ""))

# word frequency dictionary
frequency = {}

for word in words:
    if word in frequency:
        frequency[word] += 1
    else:
        frequency[word] = 1

# results
print(f"Total words: {word_count}")
print(f"Total characters (no spaces): {char_count}")

print("\nWord frequency:")
for word, count in frequency.items():
    print(f"{word}: {count}")
