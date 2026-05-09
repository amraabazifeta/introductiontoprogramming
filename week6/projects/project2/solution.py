# Project 2 — Number Guessing Game
# Author: Erinda

import random

# Bonus: difficulty levels
print("Choose difficulty: (1) Easy 1-10  (2) Medium 1-50  (3) Hard 1-100")
difficulty = input("Your choice: ")

if difficulty == "2":
    secret = random.randint(1, 50)
    print("Guessing between 1 and 50.")
elif difficulty == "3":
    secret = random.randint(1, 100)
    print("Guessing between 1 and 100.")
else:
    secret = random.randint(1, 10)
    print("Guessing between 1 and 10.")

guesses = 0
guess = int(input("Guess a number: "))
guesses += 1

while guess != secret:
    if guess < secret:
        print("Too low!")
    else:
        print("Too high!")
    guess = int(input("Try again: "))
    guesses += 1

print(f"Correct! You got it in {guesses} guesses.")