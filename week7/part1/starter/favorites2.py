import csv

with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row["language"])