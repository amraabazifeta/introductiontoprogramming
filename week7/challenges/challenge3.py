import csv

counts = {}
total = 0

with open("../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        lang = row["language"]

        if lang not in counts:
            counts[lang] = 0

        counts[lang] += 1
        total += 1

# write new file
with open("language_summary.csv", "w", newline="") as file:
    writer = csv.writer(file)

    writer.writerow(["language", "votes", "percentage"])

    for lang, count in counts.items():
        percentage = (count / total) * 100
        writer.writerow([lang, count, f"{percentage:.2f}"])

print("Saved to language_summary.csv")
