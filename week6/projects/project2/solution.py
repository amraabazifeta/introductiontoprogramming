# Project 2 — Number Guessing Game
# Author: your name here
# Branch: firstname-project2

import random

print("Choose difficulty: (1) Easy 1-10  (2) Medium 1-50  (3) Hard 1-100")
level = input("Choice: ")

if level == "1":
    secret = random.randint(1, 10)
elif level == "2":
    secret = random.randint(1, 50)
elif level == "3":
    secret = random.randint(1, 100)
else:
    print("Invalid choice, defaulting to Easy.")
    secret = random.randint(1, 10)

guesses = 0

while True:
    guess = int(input("Guess the number: "))
    guesses += 1

    if guess < secret:
        print("Too low! Try again.")
    elif guess > secret:
        print("Too high! Try again.")
    else:
        print(f"Correct! You got it in {guesses} guesses.")
        break
