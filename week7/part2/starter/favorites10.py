# favorites10.py
# Task: Ask the user for a problem name, then count how many students
#       listed it as their favourite — using a parameterised SQL query.
#
# CRITICAL SECURITY RULE:
#   Never build SQL strings with f-strings or string concatenation.
#   Always use ? placeholders. The library substitutes safely.
#
#   WRONG:  db.execute(f"SELECT ... WHERE problem = '{favorite}'")
#   RIGHT:  db.execute("SELECT ... WHERE problem = ?", favorite)
#
# Sample run:
#   Favorite: Speller
#   10

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

# TODO: Ask the user for their favourite problem using input()
<<<<<<< HEAD
favorite = input("Favorite: ")

# TODO: Execute a SQL query: SELECT COUNT(*) AS n FROM favorites WHERE problem = ?
#       Pass the user's input as the second argument to db.execute()
# Store the result in a variable (this returns a list of dictionaries)
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)

# TODO: Get the first (and only) row from the result
row = rows[0]

# TODO: Print row["n"]
print(row["n"])
=======
# TODO: Execute a SQL query: SELECT COUNT(*) AS n FROM favorites WHERE problem = ?
#       Pass the user's input as the second argument to db.execute()
# TODO: Get the first (and only) row from the result
# TODO: Print row["n"]
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
