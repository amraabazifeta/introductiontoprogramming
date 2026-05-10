# favorites4.py
# Task: Count how many students chose each language using separate counter variables.
#
# Expected output:
#   Scratch: 28
#   C: 40
#   Python: 196
#
# Note: This approach has a serious limitation — can you spot it?
#       (Think about what happens if a new language appears in the data)

import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    # TODO: Create three counter variables: scratch, c, python — all starting at 0

    for row in reader:
        favorite = row["language"]
        # TODO: Use if/elif to increment the correct counter

    # TODO: Print the three counts using f-strings
