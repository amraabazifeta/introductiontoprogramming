# challenge5.py — Data Cleaner
import csv

problems_found = []
cleaned_rows = []
skipped = 0

with open("messy_data.csv", newline="") as f:
    reader = csv.DictReader(f)
    rows = list(reader)

for i, row in enumerate(rows, start=2):  # start=2 because row 1 is header
    row_problems = []

    # Check for completely empty rows
    if all(v.strip() == "" for v in row.values()):
        row_problems.append("completely empty row")
        skipped += 1
        problems_found.append(f"Row {i}: {', '.join(row_problems)}")
        continue

    # Check for missing name
    if row["name"].strip() == "":
        row_problems.append("missing name")

    # Check for missing age
    if row["age"].strip() == "":
        row_problems.append("missing age")
    else:
        try:
            age = int(row["age"])
            if age < 18:
                row_problems.append(f"underage ({age})")
            elif age > 120:
                row_problems.append(f"invalid age ({age})")
        except ValueError:
            row_problems.append(f"age not a number ({row['age']})")

    # Check for invalid email
    if "@" not in row["email"] or "." not in row["email"]:
        row_problems.append(f"invalid email ({row['email']})")

    # Check for invalid score
    try:
        score = int(row["score"])
        if score < 0 or score > 100:
            row_problems.append(f"score out of range ({score})")
    except ValueError:
        row_problems.append(f"score not a number ({row['score']})")

    if row_problems:
        problems_found.append(f"Row {i} ({row['name'] or 'unknown'}): {', '.join(row_problems)}")
        skipped += 1
    else:
        cleaned_rows.append(row)

# Write cleaned CSV
with open("cleaned_data.csv", "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=["name", "age", "email", "score"])
    writer.writeheader()
    writer.writerows(cleaned_rows)

# Print report
print("=== Data Cleaning Report ===")
print(f"Total rows read:    {len(rows)}")
print(f"Rows kept:          {len(cleaned_rows)}")
print(f"Rows skipped:       {skipped}")
print(f"\nProblems found ({len(problems_found)}):")
for p in problems_found:
    print(f"  ❌ {p}")
print(f"\nCleaned data written to cleaned_data.csv")
