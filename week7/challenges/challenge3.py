# challenge3.py — CSV Writer
# Read favorites.csv, count votes per language, write results to language_summary.csv.

import csv

def main():
    counts = {}
    total = 0

    try:
        with open("favorites.csv", "r", encoding="utf-8") as file:
            reader = csv.DictReader(file)
            for row in reader:
                lang = row.get("language")
                if lang:
                    counts[lang] = counts.get(lang, 0) + 1
                    total += 1
    except FileNotFoundError:
        print("Error: favorites.csv not found!")
        return

    try:
        with open("language_summary.csv", "w", encoding="utf-8", newline="") as outfile:
            writer = csv.DictWriter(outfile, fieldnames=["language", "votes", "percentage"])
            writer.writeheader()

            for lang in sorted(counts.keys()):
                votes = counts[lang]
                pct = (votes / total) * 100
                writer.writerow({
                    "language": lang,
                    "votes": votes,
                    "percentage": f"{pct:.2f}"
                })
        print("Saved to language_summary.csv")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()