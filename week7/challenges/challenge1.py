# challenge1.py — Frequency Filter
# Read favorites.csv, ask for a minimum vote count, print filtered results.
# No starter hints — build this from scratch using what you learned in week1 and week2.

import csv

<<<<<<< HEAD
def main():
    counts = {}

    try:
        with open("favorites.csv", "r") as file:
            reader = csv.DictReader(file)
            for row in reader:
                language = row["language"]
                if language in counts:
                    counts[language] += 1
                else:
                    counts[language] = 1
    except FileNotFoundError:
        print("Error: favorites.csv not found!")
        return

    try:
        min_votes = int(input("Minimum votes to display: "))
    except ValueError:
        print("Please enter a valid number.")
        return

    sorted_languages = sorted(counts.items(), key=lambda item: item[1], reverse=True)

    for language, votes in sorted_languages:
        if votes >= min_votes:
            print(f"{language}: {votes}")

if __name__ == "__main__":
    main()
=======
# Your code here
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
