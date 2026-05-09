# challenge4.py — SQL Explorer
import sqlite3

# Connect to the database
con = sqlite3.connect("favorites.db")
db = con.cursor()

while True:
    print("\n--- SQL Explorer Menu ---")
    print("1. Show all languages and vote counts")
    print("2. Show most popular language")
    print("3. Show all problems for a language")
    print("4. Show top 5 most common problems")
    print("5. Search by language name")
    print("6. Exit")

    choice = input("\nChoose an option (1-6): ")

    if choice == "1":
        db.execute("SELECT language, COUNT(*) as votes FROM favorites GROUP BY language ORDER BY votes DESC")
        rows = db.fetchall()
        print(f"\n{'Language':<15} {'Votes'}")
        print("-" * 25)
        for row in rows:
            print(f"{row[0]:<15} {row[1]}")

    elif choice == "2":
        db.execute("SELECT language, COUNT(*) as votes FROM favorites GROUP BY language ORDER BY votes DESC LIMIT 1")
        row = db.fetchone()
        print(f"\nMost popular language: {row[0]} with {row[1]} votes")

    elif choice == "3":
        lang = input("Enter language name: ")
        db.execute("SELECT problem, COUNT(*) as votes FROM favorites WHERE language = ? GROUP BY problem ORDER BY votes DESC", (lang,))
        rows = db.fetchall()
        if rows:
            print(f"\n{'Problem':<30} {'Votes'}")
            print("-" * 40)
            for row in rows:
                print(f"{row[0]:<30} {row[1]}")
        else:
            print(f"No results found for '{lang}'")

    elif choice == "4":
        db.execute("SELECT problem, COUNT(*) as votes FROM favorites GROUP BY problem ORDER BY votes DESC LIMIT 5")
        rows = db.fetchall()
        print(f"\n{'Problem':<30} {'Votes'}")
        print("-" * 40)
        for row in rows:
            print(f"{row[0]:<30} {row[1]}")

    elif choice == "5":
        search = input("Enter language to search: ")
        db.execute("SELECT language, COUNT(*) as votes FROM favorites WHERE language LIKE ? GROUP BY language", (f"%{search}%",))
        rows = db.fetchall()
        if rows:
            for row in rows:
                print(f"{row[0]:<15} {row[1]} votes")
        else:
            print(f"No results found for '{search}'")

    elif choice == "6":
        print("Goodbye!")
        break

    else:
        print("Invalid choice, please pick 1-6.")

con.close()
