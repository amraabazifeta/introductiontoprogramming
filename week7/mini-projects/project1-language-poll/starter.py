# starter.py — Language Poll Analyser

import csv

# Step 1: Read the CSV and count languages
counts = {}

with open("../../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        language = row["language"]

        if language in counts:
            counts[language] += 1
        else:
            counts[language] = 1

# Step 2: Sort by popularity (most popular first)
sorted_languages = sorted(counts, key=counts.get, reverse=True)

# Step 3: Print the report
print("=== Language Popularity Report ===")

for rank, language in enumerate(sorted_languages, start=1):
    print(f"{rank}. {language:<10}: {counts[language]} students")

# Print total responses
print(f"\nTotal responses: {sum(counts.values())}")
