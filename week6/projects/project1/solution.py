# Project 1 — Temperature Converter
# Author: Esra Eylul Lofca
# Date:   18.04.2026
#
# Instructions:
#   1. Read the README.md in this folder first.
#   2. Fill in the missing lines below.
#   3. Test with: 0°C → 32°F | 100°C → 212°F | -40°C → -40°F

# ── Your solution goes here ───────────────────────────────────────────────────

celsius = float(input("Enter temperature in Celsius: "))

# calculate fahrenheit using the formula F = (C × 9/5) + 32
fahrenheit = (celsius * 9/5) + 32

# print the result using an f-string
print(f"{celsius}°C = {fahrenheit}°F")

# ── Bonus (optional) ─────────────────────────────────────────────────────────
# Add a direction menu (C→F or F→C)

print("\nConvert: (1) Celsius → Fahrenheit  (2) Fahrenheit → Celsius")
choice = input("Choice: ")

if choice == "1":
    celsius = float(input("Enter temperature in Celsius: "))
    fahrenheit = (celsius * 9/5) + 32
    print(f"{celsius}°C = {fahrenheit}°F")

elif choice == "2":
    fahrenheit = float(input("Enter temperature in Fahrenheit: "))
    celsius = (fahrenheit - 32) * 5/9
    print(f"{fahrenheit}°F = {celsius}°C")

else:
    print("Invalid choice. Please enter 1 or 2.")
