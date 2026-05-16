import csv

counts = {}

with open("../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        language = row["language"]
        if language not in counts:
            counts[language] = 0
        counts[language] += 1

# ask user
minimum = int(input("Minimum votes to display: "))

# filter + sort
filtered = []
for lang, count in counts.items():
    if count >= minimum:
        filtered.append((lang, count))

filtered.sort(key=lambda x: x[1], reverse=True)

# print
for lang, count in filtered:
    print(f"{lang}: {count}")
