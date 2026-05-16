import csv

valid_languages = {"C", "Python", "Scratch"}
seen_ids = set()

removed = 0
fixed = 0

cleaned_rows = []

with open("messy_data.csv", "r") as infile:
    reader = csv.DictReader(infile)

    for row in reader:
        student_id = row["id"]
        language = row["language"]
        score = row["score"]

        # blank row
        if not student_id or not language or not score:
            removed += 1
            continue

        # duplicate ID
        if student_id in seen_ids:
            removed += 1
            continue
        seen_ids.add(student_id)

        # invalid score
        try:
            score = int(score)
            if score < 1 or score > 5:
                removed += 1
                continue
        except:
            removed += 1
            continue

        # unknown language → fix it
        if language not in valid_languages:
            language = "Unknown"
            fixed += 1

        cleaned_rows.append({
            "id": student_id,
            "language": language,
            "score": score
        })

# write cleaned file
with open("cleaned_data.csv", "w", newline="") as outfile:
    fieldnames = ["id", "language", "score"]
    writer = csv.DictWriter(outfile, fieldnames=fieldnames)

    writer.writeheader()
    writer.writerows(cleaned_rows)

# report
print("Cleaning Report:")
print(f"Removed rows: {removed}")
print(f"Fixed rows: {fixed}")
print(f"Clean rows: {len(cleaned_rows)}")
