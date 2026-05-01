# Project 2 — Number Guessing Game
# Author: Esra Eylul LOfca

import random

# generate a random secret number between 1 and 10
secret_number = random.randint(1, 10)

# set up guesses counter
guesses = 0

# get user's first guess
guess = int(input("Guess a number between 1 and 10: "))

# while loop until correct guess
while guess != secret_number:
    guesses += 1

    if guess < secret_number:
        print("Too low!")
    else:
        print("Too high!")

    guess = int(input("Try again: "))

# count the final correct guess
guesses += 1

print(f"Correct! You guessed it in {guesses} tries.")
