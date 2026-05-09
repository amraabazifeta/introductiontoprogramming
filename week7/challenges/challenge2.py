# challenge2.py — Two-Column Report
import csv

# Read the CSV file
with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    rows = list(reader)

# Build a dictionary: language -> {problem: count}
language_problems = {}

for row in rows:
    language = row["language"].strip().lower()
    problem = row["problem"].strip().lower()

    if language not in language_problems:
        language_problems[language] = {}

    if problem in language_problems[language]:
        language_problems[language][problem] += 1
    else:
        language_problems[language][problem] = 1

# Find the most common problem per language
print(f"{'Language':<15} {'Most Common Problem':<25} {'Count'}")
print("-" * 45)

for language, problems in sorted(language_problems.items()):
    most_common = max(problems, key=lambda p: problems[p])
    count = problems[most_common]
    print(f"{language:<15} {most_common:<25} {count}")
