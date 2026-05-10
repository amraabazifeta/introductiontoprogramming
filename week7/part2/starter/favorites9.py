# favorites9.py
# Task: Count languages using SQL instead of a Python dictionary.
#
# Before running this file, import the CSV into SQLite:
#   sqlite3 favorites.db
#   .mode csv
#   .import ../week1/favorites.csv favorites
#   .quit
#
# The SQL query replaces the entire counting loop from favorites5–8.
# One query does what 10+ lines of Python did.
#
# Expected output:
#   Python 196
#   C 40
#   Scratch 28

from cs50 import SQL

# Open the database
db = SQL("sqlite:///favorites.db")

# TODO: Write a SQL query that:
#   - SELECTs language and COUNT(*) AS n
#   - FROM the favorites table
#   - GROUPs BY language
#   - ORDERs BY n DESC
# Store the result in a variable called 'rows'
<<<<<<< HEAD
rows = db.execute("SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC")

# TODO: Loop over rows and print row["language"] and row["n"]
for row in rows:
    print(f"{row['language']} {row['n']}")
=======

# TODO: Loop over rows and print row["language"] and row["n"]
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
