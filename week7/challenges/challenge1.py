# challenge1.py — Frequency Filter
import csv

# Read the CSV file
with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    rows = list(reader)

# Show available columns
print("Columns:", rows[0].keys())

# Ask user for the column and minimum vote count
column = input("Which column to filter by? ")
min_votes = int(input("Minimum vote count: "))

# Count frequency of each value in that column
frequency = {}
for row in rows:
    value = row[column].strip().lower()
    if value in frequency:
        frequency[value] += 1
    else:
        frequency[value] = 1

# Filter and print results
print(f"\nResults with at least {min_votes} votes:")
found = False
for value, count in sorted(frequency.items(), key=lambda x: x[1], reverse=True):
    if count >= min_votes:
        print(f"  {value:<20} -> {count} votes")
        found = True

if not found:
    print("No results found.")
