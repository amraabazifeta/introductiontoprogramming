# starter.py — Survey Dashboard
# Project 4 | Hard | 60–90 minutes (split across 2 sessions)
#
# Run from this folder:
#   python starter.py
#
# Split the work across four roles — see README.md for the role breakdown.

import csv
import sqlite3

# ============================================================
# STEP 1 — CREATE THE DATABASE AND TABLE
# (Coder A)
# ============================================================
# connect to database
conn = sqlite3.connect("survey.db")
db = conn.cursor()

# TODO: Create the responses table if it doesn't already exist
# Columns: student_id TEXT, faculty TEXT, year INTEGER,
#          satisfaction INTEGER, favourite_tool TEXT, comments TEXT
#
# Hint:
# db.execute('''CREATE TABLE IF NOT EXISTS responses (
#     ...
# )''')
# create table if it doesn't exist
db.execute("""
CREATE TABLE IF NOT EXISTS responses (
    student_id TEXT,
    faculty TEXT,
    year INTEGER,
    satisfaction INTEGER,
    favourite_tool TEXT,
    comments TEXT
)
""")

# Optional cleanup so repeated runs don’t duplicate rows
# clear old data (so we don’t duplicate rows)
db.execute("DELETE FROM responses")

# ============================================================
# STEP 2 — READ ALL THREE CSV FILES AND INSERT ROWS
# (Coder A)
# ============================================================
# list of CSV files to load
csv_files = [
    "faculty_science.csv",
    "faculty_arts.csv",
    "faculty_business.csv",
]
# read each file and insert into database
for filename in csv_files:
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            # TODO: Insert each row into the responses table
            # Use ? placeholders — NEVER string formatting for SQL
            # db.execute("INSERT INTO responses VALUES (?, ?, ?, ?, ?, ?)", (...))
 # insert row into database safely
            db.execute(
                "INSERT INTO responses VALUES (?, ?, ?, ?, ?, ?)",
                (
                    row["student_id"],
                    row["faculty"],
                    int(row["year"]),
                    int(row["satisfaction"]),
                    row["favourite_tool"],
                    row["comments"],
                )
            )
# save changes
conn.commit()
print("Database loaded successfully.\n")

# ============================================================
# STEP 3 — DASHBOARD QUERIES
# ============================================================
# dashboard title
print("=" * 30)
print("  UNIVERSITY SURVEY DASHBOARD")
print("=" * 30)

# — Query 1: Total responses by faculty (Coder B) ----------------
# dashboard title
print("\n1. Total Responses by Faculty")

# TODO: SELECT faculty, COUNT(*) AS n FROM responses GROUP BY faculty ORDER BY faculty
# get count of each faculty
rows = db.execute(
    "SELECT faculty, COUNT(*) AS n FROM responses GROUP BY faculty ORDER BY faculty"
).fetchall()

total = 0
for row in rows:
    # TODO: print each faculty and count, aligned
    # TODO: add count to total
    print(f"   {row[0]:<8}: {row[1]}")
    total += row[1]

print(f"   {'TOTAL':<8}: {total}")

# — Query 2: Average satisfaction by year (Coder B) ----------------
# -------- Query 2: average satisfaction --------
print("\n2. Average Satisfaction by Year of Study")

# TODO: SELECT year, ROUND(AVG(satisfaction), 1) AS avg_sat
#       FROM responses GROUP BY year ORDER BY year
# get average satisfaction per year
rows = db.execute(
    "SELECT year, ROUND(AVG(satisfaction), 1) AS avg_sat FROM responses GROUP BY year ORDER BY year"
).fetchall()

for row in rows:
    # TODO: print "   Year X : Y.Y / 5"
    print(f"   Year {row[0]} : {row[1]} / 5")

# — Query 3: Favourite tool popularity (Coder B) ----------------
# -------- Query 3: favourite tool ranking --------
print("\n3. Favourite Tool Popularity")

# TODO: SELECT favourite_tool, COUNT(*) AS n
#       FROM responses GROUP BY favourite_tool ORDER BY n DESC
# count tools used
rows = db.execute(
    "SELECT favourite_tool, COUNT(*) AS n FROM responses GROUP BY favourite_tool ORDER BY n DESC"
).fetchall()

for row in rows:
    # TODO: print each tool and count, right-aligned count
    print(f"   {row[0]:<6}: {row[1]} students")

# — Query 4: Faculty comparison table (Coder C) ----------------
# -------- Query 4: faculty comparison --------
print("\n4. Faculty Comparison")
print(f"   {'Faculty':<12} | {'Avg Satisfaction':<18} | Most Popular Tool")
print("   " + "-" * 50)

# For each faculty, find average satisfaction and most popular tool
# Hint: you may need two queries per faculty, or a subquery
faculties = ["Arts", "Business", "Science"]
for faculty in faculties:
    # TODO: Query average satisfaction for this faculty (use ? placeholder)
    avg_row = db.execute(
        "SELECT ROUND(AVG(satisfaction), 1) AS avg FROM responses WHERE faculty = ?",
        (faculty,)
    ).fetchone()

    # TODO: Query the most popular tool for this faculty
    # most used tool per faculty
    tool_row = db.execute(
        """
        SELECT favourite_tool, COUNT(*) AS n
        FROM responses
        WHERE faculty = ?
        GROUP BY favourite_tool
        ORDER BY n DESC, favourite_tool ASC
        LIMIT 1
        """,
        (faculty,)
    ).fetchone()

    # TODO: Print the row
     # print summary row
    print(f"   {faculty:<12} | {avg_row[0]:<18} | {tool_row[0]}")

# — Query 5: Interactive filter (Coder C) ----------------
# -------- Query 5: filter by satisfaction --------
print()
try:
    min_score = int(input("Enter minimum satisfaction score (1-5): "))
except ValueError:
    print("Invalid input. Defaulting to 4.")
    min_score = 4

# TODO: SELECT student_id, faculty, year, favourite_tool
#       FROM responses WHERE satisfaction >= ?
#       ORDER BY faculty, year
# Use ? placeholder — min_score is user input
# get filtered students
rows = db.execute(
    """
    SELECT student_id, faculty, year, favourite_tool
    FROM responses
    WHERE satisfaction >= ?
    ORDER BY faculty, year
    """,
    (min_score,)
).fetchall()

print(f"Students with satisfaction >= {min_score}:")
if not rows:
    print("No results found.")
for row in rows:
   print(f"{row[0]} | {row[1]} | Year {row[2]} | {row[3]}")

conn.close()
