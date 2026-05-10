# Project 1 — Temperature Converter
# Author: serhan kara
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
print(f"{celsius}°C is equal to {fahrenheit}°F")

# ── Bonus (optional) ─────────────────────────────────────────────────────────
# Add a direction menu (C→F or F→C)
```
