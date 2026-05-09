import csv

counts = {}

with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for language, count in counts.items():
    print(f"{language}: {count}")
