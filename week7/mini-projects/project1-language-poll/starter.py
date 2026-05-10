<<<<<<< HEAD
# Arda Ok Computer Engineering Homework
=======
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
# starter.py — Language Poll Analyser
# Project 1 | Easy | 20–25 minutes
#
# Run from this folder:
#   python starter.py
#
# The CSV file is at: ../../week1/favorites.csv

import csv

# ── Step 1: Read the CSV and count languages ──────────────────────────────────
counts = {}

<<<<<<< HEAD
with open("../../part1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # TODO: Get the language from the row
        language = row["language"]

        # TODO: Update counts — increment if exists, create if new
        if language in counts:
            counts[language] += 1
        else:
            counts[language] = 1

# ── Step 2: Sort by popularity (most popular first) ───────────────────────────
# Hint: sorted(counts, key=counts.get, reverse=True)
sorted_languages = sorted(counts, key=counts.get, reverse=True)
=======
with open("../../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # TODO: Get the language from the row
        language = ???

        # TODO: Update counts — increment if exists, create if new
        ???

# ── Step 2: Sort by popularity (most popular first) ───────────────────────────
# Hint: sorted(counts, key=counts.get, reverse=True)
sorted_languages = ???
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

# ── Step 3: Print the report ──────────────────────────────────────────────────
print("=== Language Popularity Report ===")

# TODO: Loop over sorted_languages with enumerate() to get rank numbers (start=1)
# Format each line like: "1. Python  : 196 students"
<<<<<<< HEAD
for rank, language in enumerate(sorted_languages, start=1):
    count = counts[language]
    print(f"{rank}. {language:<8} : {count:>3} students")

# TODO: Print the total number of responses
# Hint: sum(counts.values())
print(f"\nTotal responses: {sum(counts.values())}")
=======
for rank, language in ???:
    ???

# TODO: Print the total number of responses
# Hint: sum(counts.values())
print(f"\nTotal responses: ???")
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
