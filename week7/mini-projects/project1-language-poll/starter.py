# starter.py — Language Poll Analyser
# Project 1 | Easy | 20–25 minutes
#
# Run from this folder:
#   python starter.py
#
# The CSV file is at: ../../week1/favorites.csv

# starter.py - Language Poll Analyser
# Project 1 | Easy | 20-25 minutes

# Run from this folder:
#   python starter.py

# The CSV file is at: ../week1/favorites.csv
import csv
from pathlib import Path

counts = {}

csv_path = Path(__file__).resolve().parents[2] / "part1" / "favorites.csv"

with open(csv_path, "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        language = row["language"]

        if language in counts:
            counts[language] += 1
        else:
            counts[language] = 1

sorted_languages = sorted(counts, key=counts.get, reverse=True)

print("=== Language Popularity Report ===")

for language in sorted_languages:
    print(language, counts[language])

print("Total responses:", sum(counts.values()))