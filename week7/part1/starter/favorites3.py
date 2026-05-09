import csv

with open("favorites.csv", newline="") as f:
    for row in csv.DictReader(f):
        print(row["language"])