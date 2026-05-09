import csv

with open("favorites.csv", newline="") as f:
    reader = csv.reader(f)
    next(reader)
    for row in reader:
        favorite = row[1]
        print(favorite)