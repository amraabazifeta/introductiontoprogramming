# challenge2.py — Two-Column Report
# Read favorites.csv, find the most common problem per language, print a table.

<<<<<<< HEAD

import csv

def main():
    data = {}

    try:
        with open("favorites.csv", "r", encoding="utf-8") as file:
            reader = csv.DictReader(file)
            for row in reader:
                lang = row.get("language")
                prob = row.get("problem")

                if lang and prob:
                    if lang not in data:
                        data[lang] = {}

                    if prob in data[lang]:
                        data[lang][prob] += 1
                    else:
                        data[lang][prob] = 1
    except FileNotFoundError:
        print("Error: favorites.csv not found!")
        return

    print(f"{'Language':<10} | {'Most Common Problem'}")
    print("-" * 11 + "+" + "-" * 20)

    for lang in sorted(data.keys()):
        problems = data[lang]
        most_common = max(problems, key=problems.get)
        print(f"{lang:<10} | {most_common}")

if __name__ == "__main__":
    main()
=======
import csv

# Your code here
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
