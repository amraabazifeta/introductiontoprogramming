# challenge3.py — CSV Writer
import csv

# Read favorites.csv
with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    rows = list(reader)

# Count votes per language
language_counts = {}
for row in rows:
    language = row["language"].strip().lower()
    if language in language_counts:
        language_counts[language] += 1
    else:
        language_counts[language] = 1

# Write results to language_summary.csv
with open("language_summary.csv", "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=["language", "votes"])
    writer.writeheader()
    for language, votes in sorted(language_counts.items(), key=lambda x: x[1], reverse=True):
        writer.writerow({"language": language, "votes": votes})

print("Done! Results written to language_summary.csv")
print(f"\n{'Language':<15} {'Votes'}")
print("-" * 25)
for language, votes in sorted(language_counts.items(), key=lambda x: x[1], reverse=True):
    print(f"{language:<15} {votes}")
