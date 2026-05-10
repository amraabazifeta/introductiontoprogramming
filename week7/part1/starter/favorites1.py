# favorites1.py
# Task: Same as favorites0, but store the language in a variable called 'favorite'
#       before printing it.
#
# Why? Naming values makes code self-documenting.
#      row[1] tells you nothing. favorite = row[1] tells you exactly what row[1] is.

import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        # TODO: Store row[1] in a variable called 'favorite'
        # TODO: Print favorite
        pass
