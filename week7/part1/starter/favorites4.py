import csv

scratch = 0
c = 0
python = 0

with open("favorites.csv", newline="") as f:
    reader = csv.DictReader(f)
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")
