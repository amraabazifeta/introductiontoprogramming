# Project 5 — Mini Shopping Cart
# Author: Muhammed Soykan Tekin

menu = {
    1: ("Apple", 0.50),
    2: ("Banana", 0.30),
    3: ("Milk", 1.20),
    4: ("Bread", 2.00),
}

cart = {}   # { item_name: quantity }
total = 0.0

# display menu
print("--- Shop Menu ---")
for number, (name, price) in menu.items():
    print(f"{number}. {name:<10} ${price:.2f}")
print("5. Done")

# shopping loop
while True:
    choice = int(input("\nChoose an item (1-5): "))

    if choice == 5:
        break

    if choice in menu:
        name, price = menu[choice]

        if name in cart:
            cart[name] += 1
        else:
            cart[name] = 1

        total += price

        print(f"Added {name} to cart.")
    else:
        print("Invalid choice, try again.")

# receipt
print("\n--- Receipt ---")

for item, qty in cart.items():
    print(f"{item} x{qty}")

print(f"Total: ${total:.2f}")
print("Thank you!")
