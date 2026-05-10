# favorites9_solution.py
from cs50 import SQL

db = SQL("sqlite:///favorites.db")

rows = db.execute(
    "SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC"
)

for row in rows:
    print(row["language"], row["n"])
