#arda_portakal_homework_AIE
menu = {
    1: ("water",  0.50),
    2: ("orange", 0.30),
    3: ("donut",   1.20),
    4: ("tea",  2.00),
}

prices = {name: price for _, (name, price) in menu.items()}
cart = {}
total = 0.0

print("--- Shop Menu ---")
for number, (name, price) in menu.items():
    print(f"{number}. {name:<10} ${price:.2f}")
print("5. Done")

while True:
    choice = int(input("\nChoose an item (1-5): "))
    if choice == 5:
        break
    if choice in menu:
        name, price = menu[choice]
        cart[name] = cart.get(name, 0) + 1
        total += price
        print(f"Added {name}. Total: ${total:.2f}")
    else:
        print("Invalid choice, try again.")

print("\n--- Receipt ---")
for item, qty in cart.items():
    print(f"{item:<10} x{qty}   ${prices[item] * qty:.2f}")
print("---------------------")
print(f"Total: ${total:.2f}")
print("Thank you!")
