# favorites0_solution.py

import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)

    # Skip header row
    next(reader)

    for row in reader:
        # Safety check (prevents index errors)
        if len(row) > 1:
            print(row[1])
