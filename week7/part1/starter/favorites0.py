# favorites0.py
# Task: Print every student's favourite language using csv.reader
#
# Expected output (first few lines):
#   Python
#   C
#   Python
#   ...
#
# Hint: csv.reader returns each row as a LIST.
#       The language column is at index 1.
#       Don't forget to skip the header row with next()

import csv

# TODO: Open favorites.csv for reading
<<<<<<< HEAD
with open("favorites.csv", "r") as file:
    # TODO: Create a csv.reader object
    reader = csv.reader(file)
    
    # TODO: Skip the header row using next()
    next(reader)
    
    # TODO: Loop over the remaining rows and print the language column
    for row in reader:
        print(row[1])
=======
# TODO: Create a csv.reader object
# TODO: Skip the header row using next()
# TODO: Loop over the remaining rows and print the language column
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
