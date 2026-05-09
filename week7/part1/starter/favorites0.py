import csv

with open("favorites.csv", newline="") as f:
    reader = csv.reader(f)
    next(reader)
    for row in reader:
        print(row[1])