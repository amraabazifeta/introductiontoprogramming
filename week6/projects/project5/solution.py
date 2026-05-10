# Project 5 — Mini Shopping Cart
# Author: Arda Ok

menu = {
    1: ("Apple",  0.50),
    2: ("Banana", 0.30),
    3: ("Milk",   1.20),
    4: ("Bread",  2.00),
}

cart  = {}   # { item_name: quantity }
total = 0.0

# TODO: display the menu
print("--- Shop Menu ---")
for number, (name, price) in menu.items():
    print(f"{number}. {name:<8} ${price:.2f}")
print("5. Done")

# TODO: shopping loop
while True:
    choice = int(input("\nChoose an item (1-5): "))
    
    if choice == 5:
        break
        
    if choice in menu:
        name, price = menu[choice]
        
        # Sepete ekle: Eğer ürün zaten varsa miktarını artır, yoksa yeni ekle
        if name in cart:
            cart[name] += 1
        else:
            cart[name] = 1
            
        total += price
        print(f"Added {name}. Total: ${total:.2f}")
    else:
        print("Invalid choice, try again.")

# TODO: print the receipt
print("\n--- Receipt ---")
for item, qty in cart.items():
    # Menüden fiyatı bulmak için küçük bir döngü veya arama yapabiliriz
    # Ama sadece isim ve adet yazdırmak da yeterli
    print(f"{item:<8} x{qty}")

print("---------------------")
print(f"Total: ${total:.2f}")
print("Thank you!")