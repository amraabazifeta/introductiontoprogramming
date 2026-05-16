import sqlite3

conn = sqlite3.connect("favorites.db")
db = conn.cursor()

while True:
    print("\n=== SQL Explorer ===")
    print("1. Count by language")
    print("2. Count by problem")
    print("3. Search by problem name")
    print("4. Top 5 problems overall")
    print("5. Quit")

    choice = input("Choice: ")

    if choice == "1":
        rows = db.execute("""
            SELECT language, COUNT(*)
            FROM favorites
            GROUP BY language
            ORDER BY COUNT(*) DESC
        """)
        for row in rows:
            print(row)

    elif choice == "2":
        rows = db.execute("""
            SELECT problem, COUNT(*)
            FROM favorites
            GROUP BY problem
            ORDER BY COUNT(*) DESC
        """)
        for row in rows:
            print(row)

    elif choice == "3":
        search = input("Enter problem name: ")
        rows = db.execute("""
            SELECT * FROM favorites
            WHERE problem LIKE ?
        """, (f"%{search}%",))

        for row in rows:
            print(row)

    elif choice == "4":
        rows = db.execute("""
            SELECT problem, COUNT(*)
            FROM favorites
            GROUP BY problem
            ORDER BY COUNT(*) DESC
            LIMIT 5
        """)
        for row in rows:
            print(row)

    elif choice == "5":
        break

conn.close()
