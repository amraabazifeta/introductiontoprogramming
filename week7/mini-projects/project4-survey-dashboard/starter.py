import csv
import sqlite3

# ═════════════════════════════════════════════════════════════
# STEP 1 — DATABASE
# ═════════════════════════════════════════════════════════════

conn = sqlite3.connect("survey.db")
db = conn.cursor()

db.execute('''
CREATE TABLE IF NOT EXISTS responses (
    student_id TEXT,
    faculty TEXT,
    year INTEGER,
    satisfaction INTEGER,
    favourite_tool TEXT,
    comments TEXT
)
''')

# ═════════════════════════════════════════════════════════════
# STEP 2 — LOAD CSV FILES
# ═════════════════════════════════════════════════════════════

csv_files = [
    "faculty_science.csv",
    "faculty_arts.csv",
    "faculty_business.csv",
]

for filename in csv_files:
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.execute(
                "INSERT INTO responses VALUES (?, ?, ?, ?, ?, ?)",
                (
                    row["student_id"],
                    row["faculty"],
                    int(row["year"]),
                    int(row["satisfaction"]),
                    row["favourite_tool"],
                    row["comments"]
                )
            )

conn.commit()
print("Database loaded successfully.\n")

# ═════════════════════════════════════════════════════════════
# STEP 3 — DASHBOARD
# ═════════════════════════════════════════════════════════════

print("=" * 30)
print("  UNIVERSITY SURVEY DASHBOARD")
print("=" * 30)

# ── 1. Faculty counts
print("\n1. Total Responses by Faculty")

rows = db.execute('''
SELECT faculty, COUNT(*)
FROM responses
GROUP BY faculty
ORDER BY faculty
''').fetchall()

total = 0
for faculty, count in rows:
    print(f"   {faculty:<10}: {count}")
    total += count

print(f"   {'TOTAL':<10}: {total}")

# ── 2. Average satisfaction by year
print("\n2. Average Satisfaction by Year of Study")

rows = db.execute('''
SELECT year, ROUND(AVG(satisfaction), 1)
FROM responses
GROUP BY year
ORDER BY year
''').fetchall()

for year, avg in rows:
    print(f"   Year {year} : {avg} / 5")

# ── 3. Favourite tool popularity
print("\n3. Favourite Tool Popularity")

rows = db.execute('''
SELECT favourite_tool, COUNT(*)
FROM responses
GROUP BY favourite_tool
ORDER BY COUNT(*) DESC
''').fetchall()

for tool, count in rows:
    print(f"   {tool:<10}: {count}")

# ── 4. Faculty comparison
print("\n4. Faculty Comparison")
print(f"   {'Faculty':<12} | {'Avg Satisfaction':<18} | Most Popular Tool")
print("   " + "-" * 50)

faculties = ["Arts", "Business", "Science"]

for faculty in faculties:
    avg = db.execute('''
        SELECT ROUND(AVG(satisfaction), 1)
        FROM responses
        WHERE faculty = ?
    ''', (faculty,)).fetchone()[0]

    tool = db.execute('''
        SELECT favourite_tool, COUNT(*) as c
        FROM responses
        WHERE faculty = ?
        GROUP BY favourite_tool
        ORDER BY c DESC
        LIMIT 1
    ''', (faculty,)).fetchone()[0]

    print(f"   {faculty:<12} | {avg:<18} | {tool}")

# ── 5. Interactive filter
print()

try:
    min_score = int(input("Enter minimum satisfaction score (1-5): "))
except:
    min_score = 4

rows = db.execute('''
SELECT student_id, faculty, year, favourite_tool
FROM responses
WHERE satisfaction >= ?
ORDER BY faculty, year
''', (min_score,)).fetchall()

print(f"\nStudents with satisfaction >= {min_score}:")

if not rows:
    print("  No results found.")

for sid, faculty, year, tool in rows:
    print(f"  {sid} | {faculty:<8} | Year {year} | {tool}")

# ═════════════════════════════════════════════════════════════
conn.close()
