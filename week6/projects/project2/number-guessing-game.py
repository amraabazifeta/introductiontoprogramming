#arda_portakal_homework_AIE
import random

secret = random.randint(1, 10)
guesses = 0

guess = int(input("Guess a number between 1 and 10: "))
guesses += 1

while guess != secret:
    if guess < secret:
        guess = int(input("Too low! Try again: "))
    else:
        guess = int(input("Too high! Try again: "))
    guesses += 1

print(f"Correct! You got it in {guesses} guesses.")
