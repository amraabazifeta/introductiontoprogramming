# challenge2.py — Two-Column Report
# Read favorites.csv, find the most common problem per language, print a table.

import csv

data = {}

with open("../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        lang = row["language"]
        problem = row["problem"]

        if lang not in data:
            data[lang] = {}

        if problem not in data[lang]:
            data[lang][problem] = 0

        data[lang][problem] += 1

# print table
print("Language   | Most Common Problem")
print("-----------+--------------------")

for lang in sorted(data.keys()):
    problems = data[lang]

    most_common = max(problems, key=problems.get)

    print(f"{lang:<10} | {most_common}")
