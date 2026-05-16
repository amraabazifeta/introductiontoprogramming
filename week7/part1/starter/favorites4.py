import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    python = 0
    c = 0
    scratch = 0

    for row in reader:
        favorite = row["language"]

        if favorite == "Python":
            python += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Scratch":
            scratch += 1

print(f"Python: {python}")
print(f"C: {c}")
print(f"Scratch: {scratch}")
