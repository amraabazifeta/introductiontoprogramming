# Project 5 — Mini Shopping Cart
# Author:  Erinda

menu = {
    1: ("Apple",  0.50),
    2: ("Banana", 0.30),
    3: ("Milk",   1.20),
    4: ("Bread",  2.00),
}

cart  = {}
total = 0.0

# Display the menu
print("--- Shop Menu ---")
for number, (name, price) in menu.items():
    print(f"{number}. {name:<10} ${price:.2f}")
print("5. Done")

# Shopping loop
while True:
    try:
        choice = int(input("\nChoose an item (1-5): "))
    except ValueError:
        print("Please enter a number between 1 and 5.")
        continue

    if choice == 5:
        break
    elif choice in menu:
        name, price = menu[choice]
        try:
            qty = int(input(f"How many {name}s? "))
            if qty < 1:
                print("Please enter at least 1.")
                continue
        except ValueError:
            print("Invalid quantity, try again.")
            continue

        if name in cart:
            cart[name] += qty
        else:
            cart[name] = qty

        total += price * qty
        print(f"Added {name} x{qty}. Total: ${total:.2f}")
    else:
        print("Invalid choice, please pick 1-5.")

# Bonus: 10% discount
discount_applied = total > 5.00
if discount_applied:
    total -= total * 0.10

# Receipt
print("\n--- Receipt ---")
for item_name, qty in cart.items():
    item_price = next(p for (n, p) in menu.values() if n == item_name)
    print(f"{item_name:<10} x{qty}   ${item_price * qty:.2f}")

if discount_applied:
    print("---------------------")
    print("10% discount applied!")

print("---------------------")
print(f"Total: ${total:.2f}")
print("Thank you!")