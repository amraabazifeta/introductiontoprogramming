import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)

    next(reader)

    for row in reader:
        print(row[1])
