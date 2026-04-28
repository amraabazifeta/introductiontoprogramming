import csv
import sqlite3

def setup_db():

    conn = sqlite3.connect("favorites.db")
    db = conn.cursor()


    db.execute("DROP TABLE IF EXISTS favorites")
    db.execute("CREATE TABLE favorites (id INTEGER PRIMARY KEY, timestamp TEXT, language TEXT, problem TEXT)")


    with open("favorites.csv", "r", encoding="utf-8") as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.execute("INSERT INTO favorites (timestamp, language, problem) VALUES (?, ?, ?)",
                       (row["Timestamp"], row["language"], row["problem"]))

    conn.commit()
    conn.close()
    print("Success: favorites.db created!")

if __name__ == "__main__":
    setup_db()