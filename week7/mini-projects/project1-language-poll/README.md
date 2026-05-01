import csv

# Step 1: Read the CSV and count languages
# store counts of each language
counts = {}
# open and read CSV file
with open("../../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
# loop through rows
    for row in reader:
        language = row["Language"]
# count languages
        if language in counts:
            counts[language] += 1
        else:
            counts[language] = 1

# Step 2: Sort by popularity (most popular first)
# sort from most popular to least
sorted_languages = sorted(counts, key=counts.get, reverse=True)

# Step 3: Print the report
# print report title
print("=== Language Popularity Report ===")
# print ranked results
for rank, language in enumerate(sorted_languages, start=1):
    print(f"{rank}. {language}: {counts[language]} students")

# Print the total number of responses
# print total responses
print(f"\nTotal responses: {sum(counts.values())}")
