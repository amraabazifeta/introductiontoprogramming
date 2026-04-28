# starter.py — Survey Dashboard
# Project 4 | Hard | 60–90 minutes (split across 2 sessions)
#
# Run from this folder:
#   python starter.py
#
# Split the work across four roles — see README.md for the role breakdown.

import csv
import sqlite3

# ══════════════════════════════════════════════════════════════════════════════
# STEP 1 — CREATE THE DATABASE AND TABLE
# (Coder A)
# ══════════════════════════════════════════════════════════════════════════════

conn = sqlite3.connect("survey.db")
db   = conn.cursor()

# TODO: Create the responses table if it doesn't already exist
db.execute('''CREATE TABLE IF NOT EXISTS responses (
    student_id TEXT, 
    faculty TEXT, 
    year INTEGER,
    satisfaction INTEGER, 
    favourite_tool TEXT, 
    comments TEXT
)''')


# ══════════════════════════════════════════════════════════════════════════════
# STEP 2 — READ ALL THREE CSV FILES AND INSERT ROWS
# (Coder A)
# ══════════════════════════════════════════════════════════════════════════════

csv_files = [
    "faculty_science.csv",
    "faculty_arts.csv",
    "faculty_business.csv",
]

for filename in csv_files:
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            # TODO: Insert each row into the responses table
            db.execute("INSERT INTO responses VALUES (?, ?, ?, ?, ?, ?)", 
                       (row["student_id"], row["faculty"], row["year"], 
                        row["satisfaction"], row["favourite_tool"], row["comments"]))

conn.commit()
print("Database loaded successfully.\n")


# ══════════════════════════════════════════════════════════════════════════════
# STEP 3 — DASHBOARD QUERIES
# ══════════════════════════════════════════════════════════════════════════════

print("=" * 30)
print("  UNIVERSITY SURVEY DASHBOARD")
print("=" * 30)

# ── Query 1: Total responses by faculty (Coder B) ────────────────────────────
print("\n1. Total Responses by Faculty")

# TODO: SELECT faculty, COUNT(*) AS n FROM responses GROUP BY faculty ORDER BY faculty
rows = db.execute("SELECT faculty, COUNT(*) AS n FROM responses GROUP BY faculty ORDER BY faculty").fetchall()
total = 0
for row in rows:
    # TODO: print each faculty and count, aligned
    print(f"   {row[0]:<10}: {row[1]}")
    # TODO: add count to total
    total += row[1]
print(f"   {'TOTAL':<10}: {total}")


# ── Query 2: Average satisfaction by year (Coder B) ──────────────────────────
print("\n2. Average Satisfaction by Year of Study")

# TODO: SELECT year, ROUND(AVG(satisfaction), 1) AS avg_sat
#       FROM responses GROUP BY year ORDER BY year
rows = db.execute("SELECT year, ROUND(AVG(satisfaction), 1) AS avg_sat FROM responses GROUP BY year ORDER BY year").fetchall()
for row in rows:
    # TODO: print "   Year X : Y.Y / 5"
    print(f"   Year {row[0]} : {row[1]} / 5")


# ── Query 3: Favourite tool popularity (Coder B) ─────────────────────────────
print("\n3. Favourite Tool Popularity")

# TODO: SELECT favourite_tool, COUNT(*) AS n
#       FROM responses GROUP BY favourite_tool ORDER BY n DESC
rows = db.execute("SELECT favourite_tool, COUNT(*) AS n FROM responses GROUP BY favourite_tool ORDER BY n DESC").fetchall()
for row in rows:
    # TODO: print each tool and count, right-aligned count
    print(f"   {row[0]:<12} {row[1]:>5}")


# ── Query 4: Faculty comparison table (Coder C) ──────────────────────────────
print("\n4. Faculty Comparison")
print(f"   {'Faculty':<12} | {'Avg Satisfaction':<18} | Most Popular Tool")
print("   " + "-" * 50)

# For each faculty, find average satisfaction and most popular tool
faculties = ["Arts", "Business", "Science"]
for faculty in faculties:
    # TODO: Query average satisfaction for this faculty (use ? placeholder)
    avg_row = db.execute(
        "SELECT ROUND(AVG(satisfaction), 1) AS avg FROM responses WHERE faculty = ?",
        (faculty,)
    ).fetchone()

    # TODO: Query the most popular tool for this faculty
    tool_row = db.execute(
        "SELECT favourite_tool FROM responses WHERE faculty = ? GROUP BY favourite_tool ORDER BY COUNT(*) DESC LIMIT 1",
        (faculty,)
    ).fetchone()

    # TODO: Print the row
    avg_val = avg_row[0] if avg_row[0] else 0
    tool_val = tool_row[0] if tool_row else "N/A"
    print(f"   {faculty:<12} | {avg_val:<18} | {tool_val}")


# ── Query 5: Interactive filter (Coder C) ────────────────────────────────────
print()
try:
    min_score = int(input("Enter minimum satisfaction score (1-5): "))
except ValueError:
    print("Invalid input. Defaulting to 4.")
    min_score = 4

# TODO: SELECT student_id, faculty, year, favourite_tool
#       FROM responses WHERE satisfaction >= ?
#       ORDER BY faculty, year
rows = db.execute("SELECT student_id, faculty, year, favourite_tool FROM responses WHERE satisfaction >= ? ORDER BY faculty, year", (min_score,)).fetchall()

print(f"\nStudents with satisfaction >= {min_score}:")
if not rows:
    print("  No results found.")
for row in rows:
    # TODO: print each result formatted as:
    # "  S002 | Science  | Year 2 | Python"
    print(f"  {row[0]} | {row[1]:<8} | Year {row[2]} | {row[3]}")


# ══════════════════════════════════════════════════════════════════════════════
# CLEANUP
# ══════════════════════════════════════════════════════════════════════════════
conn.close()