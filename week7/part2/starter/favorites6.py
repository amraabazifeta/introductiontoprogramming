# favorites6.py
# Task: Count languages using try/except instead of if/else
#
# Python philosophy: "Easier to Ask Forgiveness than Permission" (EAFP)
# Instead of checking IF the key exists, just try to use it.
# If it doesn't exist, a KeyError is raised — catch it and create the key.
#
# The result is identical to favorites5.py — the style is different.

import csv

with open("../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favorite = row["language"]
<<<<<<< HEAD
        
        # TODO: try to increment counts[favorite]
        try:
            counts[favorite] += 1
        # TODO: except KeyError: set counts[favorite] = 1
        except KeyError:
            counts[favorite] = 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
=======
        # TODO: try to increment counts[favorite]
        # TODO: except KeyError: set counts[favorite] = 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
