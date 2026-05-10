# challenge4.py — SQL Explorer
# Present an interactive menu that runs different SQL queries on favorites.db.
# Requires favorites.db — see week2/README.md for setup instructions.

<<<<<<< HEAD

import sqlite3

def main():
    try:
        conn = sqlite3.connect("favorites.db")
        db = conn.cursor()
    except sqlite3.Error as e:
        print(f"Database error: {e}")
        return

    while True:
        print("\n=== SQL Explorer ===")
        print("1. Count by language")
        print("2. Count by problem")
        print("3. Search by problem name")
        print("4. Top 5 problems overall")
        print("5. Quit")
        
        choice = input("Choice: ")

        if choice == "1":
            db.execute("SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC")
            for row in db.fetchall():
                print(f"{row[0]}: {row[1]}")

        elif choice == "2":
            db.execute("SELECT problem, COUNT(*) AS n FROM favorites GROUP BY problem ORDER BY n DESC")
            for row in db.fetchall():
                print(f"{row[0]}: {row[1]}")

        elif choice == "3":
            target = input("Search for problem: ")
            db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", (f"%{target}%",))
            count = db.fetchone()[0]
            print(f"Found {count} entries for '{target}'")

        elif choice == "4":
            db.execute("SELECT problem, COUNT(*) AS n FROM favorites GROUP BY problem ORDER BY n DESC LIMIT 5")
            for row in db.fetchall():
                print(f"{row[0]}: {row[1]}")

        elif choice == "5":
            break
        else:
            print("Invalid choice.")

    conn.close()

if __name__ == "__main__":
    main()
=======
import sqlite3

# Your code here
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
