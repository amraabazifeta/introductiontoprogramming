# Project 1 — Temperature Converter
# Author: Erinda
# Date:   session date here

celsius = float(input("Enter temperature in Celsius: "))
fahrenheit = (celsius * 9/5) + 32
print(f"{celsius}°C = {fahrenheit}°F")

# ── Bonus: direction menu ─────────────────────────────────────────────────────
print("1. Celsius → Fahrenheit")
print("2. Fahrenheit → Celsius")
choice = input("Choose direction (1 or 2): ")

if choice == "1":
    celsius = float(input("Enter temperature in Celsius: "))
    fahrenheit = (celsius * 9/5) + 32
    print(f"{celsius}°C = {fahrenheit}°F")
elif choice == "2":
    fahrenheit = float(input("Enter temperature in Fahrenheit: "))
    celsius = (fahrenheit - 32) * 5/9
    print(f"{fahrenheit}°F = {celsius:.2f}°C")
else:
    print("Invalid choice.")