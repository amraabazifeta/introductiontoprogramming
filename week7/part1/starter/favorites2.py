# favorites2.py
# Task: Print every language using csv.DictReader instead of csv.reader
#
# Key difference:
#   csv.reader  → row is a LIST  → access by index: row[1]
#   DictReader  → row is a DICT → access by name:  row["language"]
#
# Bonus: DictReader automatically uses the first row as keys — no need for next()


import csv

with open("favorites.csv", "r") as file:
    # Create a csv.DictReader (not csv.reader)
    reader = csv.DictReader(file)
    
    # Loop over rows and print the "language" column
    for row in reader:
        print(row["language"])