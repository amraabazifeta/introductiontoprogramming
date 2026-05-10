# challenge5.py — Data Cleaner
# Read a messy CSV, detect problems, write a cleaned version, print a report.
# Create your own messy_data.csv with intentional errors to test against.

import csv

def main():
    cleaned_data = []
    errors = {
        "missing_language": 0,
        "missing_problem": 0,
        "invalid_timestamp": 0
    }

    try:
        with open("messy_data.csv", "r", encoding="utf-8") as file:
            reader = csv.DictReader(file)
            for row in reader:
                is_valid = True
                
                lang = row.get("language", "").strip()
                prob = row.get("problem", "").strip()
                time = row.get("Timestamp", "").strip()

                if not lang:
                    errors["missing_language"] += 1
                    is_valid = False
                
                if not prob:
                    errors["missing_problem"] += 1
                    is_valid = False

                if not time or ":" not in time:
                    errors["invalid_timestamp"] += 1
                    is_valid = False

                if is_valid:
                    cleaned_data.append({
                        "Timestamp": time,
                        "language": lang,
                        "problem": prob
                    })
    except FileNotFoundError:
        print("Error: messy_data.csv not found!")
        return

    try:
        with open("cleaned_data.csv", "w", encoding="utf-8", newline="") as outfile:
            writer = csv.DictWriter(outfile, fieldnames=["Timestamp", "language", "problem"])
            writer.writeheader()
            writer.writerows(cleaned_data)
    except Exception as e:
        print(f"Error writing file: {e}")
        return

    print("=== Cleaning Report ===")
    print(f"Rows cleaned and saved: {len(cleaned_data)}")
    print(f"Errors detected:")
    print(f"- Missing languages: {errors['missing_language']}")
    print(f"- Missing problems: {errors['missing_problem']}")
    print(f"- Invalid timestamps: {errors['invalid_timestamp']}")

if __name__ == "__main__":
    main()