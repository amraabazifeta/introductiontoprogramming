#arda_portakal_homework_AIE
sentence = input("Enter a sentence: ")
words = sentence.lower().split()

total_words = len(words)
total_chars = len(sentence.replace(" ", ""))

frequency = {}
for word in words:
    if word in frequency:
        frequency[word] += 1
    else:
        frequency[word] = 1

print(f"Total words: {total_words}")
print(f"Total characters (no spaces): {total_chars}")
print("Word frequency:")
for word, count in frequency.items():
    print(f"  {word:<5} -> {count}")
