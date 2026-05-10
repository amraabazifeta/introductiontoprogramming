# Project 2 — Number Guessing Game
<<<<<<< HEAD
# Author: Arda Ok
=======
# Author: your name here
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

import random

# TODO: generate a random secret number between 1 and 10
<<<<<<< HEAD
secret = random.randint(1, 10)

# TODO: set up a guesses counter
guesses = 0

# TODO: get the user's first guess
guess = int(input("Guess a number between 1 and 10: "))
guesses += 1

# TODO: while loop — keep asking until the guess is correct
while guess != secret:
    #   - print "Too low!" or "Too high!" on each wrong guess
    if guess < secret:
        print("Too low!")
    else:
        print("Too high!")
    
    # Yeni tahmini al ve sayacı artır
    guess = int(input("Try again: "))
    guesses += 1

# TODO: print the congratulations message with the number of guesses
print(f"Correct! You got it in {guesses} guesses.")
=======

# TODO: set up a guesses counter

# TODO: get the user's first guess

# TODO: while loop — keep asking until the guess is correct
#   - print "Too low!" or "Too high!" on each wrong guess
#   - count each guess

# TODO: print the congratulations message with the number of guesses
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
