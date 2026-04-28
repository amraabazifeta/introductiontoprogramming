print("Convert: (1) Celsius → Fahrenheit  (2) Fahrenheit → Celsius")

choice = input("Choice: ")

if choice == "1":
    celsius = float(input("Enter temperature in Celsius: "))
    fahrenheit = (celsius * 9 / 5) + 32
    print(f"{celsius}°C = {round(fahrenheit, 2)}°F")

elif choice == "2":
    fahrenheit = float(input("Enter temperature in Fahrenheit: "))
    celsius = (fahrenheit - 32) * 5 / 9
    print(f"{fahrenheit}°F = {round(celsius, 2)}°C")

else:
    print("Invalid choice. Please select 1 or 2.")
