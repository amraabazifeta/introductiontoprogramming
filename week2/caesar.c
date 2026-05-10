// caesar.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Caesar Cipher
// ------------------------
// Encrypt a message by rotating each letter forward in the alphabet
// by a numeric key given as a command-line argument.
//
//   Example (key = 3):  A→D, B→E, Z→C (wraps around)
//   "hello" → "khoor"
//
// Usage:
//   ./caesar KEY       (KEY must be a non-negative integer)
//   ./caesar           → prints usage error
//   ./caesar abc       → prints usage error
//
// How to compile:  make caesar
// How to run:      ./caesar 13
// How to check:    check50 cs50/problems/2024/x/caesar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // ---------------------------------------------------------------------------
    // STEP 1: Validate command-line arguments
    // ---------------------------------------------------------------------------
<<<<<<< HEAD
    // TODO: Check that argc == 2
    // TODO: Check that argv[1] contains only digit characters using only_digits()
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
=======
    // The program must be called with exactly one argument: ./caesar KEY
    // If argc != 2, OR if the key is not all digits, print the usage message
    // and return 1 (indicating an error).
    //
    // TODO: Check that argc == 2
    // TODO: Check that argv[1] contains only digit characters using only_digits()
    // If either check fails:
    //   printf("Usage: ./caesar key\n");
    //   return 1;

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // ---------------------------------------------------------------------------
    // STEP 2: Convert the key from string to int
    // ---------------------------------------------------------------------------
    // TODO: Use atoi() to convert argv[1] to an integer.
<<<<<<< HEAD
    int key = atoi(argv[1]);
=======
    //   int key = atoi(argv[1]);

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // ---------------------------------------------------------------------------
    // STEP 3: Get the plaintext from the user
    // ---------------------------------------------------------------------------
    // TODO: Use get_string() to prompt for plaintext.
<<<<<<< HEAD
    string plaintext = get_string("plaintext:  ");
=======
    //   string plaintext = get_string("plaintext:  ");

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // ---------------------------------------------------------------------------
    // STEP 4: Encrypt and print the ciphertext
    // ---------------------------------------------------------------------------
<<<<<<< HEAD
    printf("ciphertext: ");

    // TODO: Loop through each character of plaintext.
    //       Call rotate(c, key) for each character to get the encrypted version.
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    // After the loop, print a newline:
    printf("\n");

    return 0;
=======
    // TODO: Loop through each character of plaintext.
    //       Call rotate(c, key) for each character to get the encrypted version.
    //       Print each encrypted character WITHOUT a newline inside the loop.
    //
    // After the loop, print a newline:
    //   printf("\n");
    //
    // The output should start with "ciphertext: " (with a trailing space):
    //   printf("ciphertext: ");

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

// ---------------------------------------------------------------------------
// TODO: Implement only_digits
// ---------------------------------------------------------------------------
<<<<<<< HEAD
bool only_digits(string s)
{
    // TODO: Loop through each character of s
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // TODO: If any character is NOT a digit, return false
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    // TODO: If all characters are digits, return true
    return true;
=======
// Return true if every character in s is a digit (0-9), false otherwise.
// Hint: use isdigit() from <ctype.h>
// ---------------------------------------------------------------------------
bool only_digits(string s)
{
    // TODO: Loop through each character of s
    // TODO: If any character is NOT a digit, return false
    // TODO: If all characters are digits, return true

    return true; // placeholder — replace this
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

// ---------------------------------------------------------------------------
// TODO: Implement rotate
// ---------------------------------------------------------------------------
<<<<<<< HEAD
char rotate(char c, int n)
{
    // TODO: If c is uppercase, rotate it and return the result
    if (isupper(c))
    {
        return (c - 'A' + n) % 26 + 'A';
    }
    // TODO: If c is lowercase, rotate it and return the result
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    // TODO: If c is not a letter, return c unchanged
    else
    {
        return c;
    }
}
=======
// Rotate character c forward by n positions in the alphabet.
// Preserve case: uppercase stays uppercase, lowercase stays lowercase.
// Non-letter characters are returned UNCHANGED.
//
// The math (for uppercase):
//   char encrypted = (c - 'A' + n) % 26 + 'A';
//
// The math (for lowercase):
//   char encrypted = (c - 'a' + n) % 26 + 'a';
// ---------------------------------------------------------------------------
char rotate(char c, int n)
{
    // TODO: If c is uppercase, rotate it and return the result
    // TODO: If c is lowercase, rotate it and return the result
    // TODO: If c is not a letter, return c unchanged

    return c; // placeholder — replace this
}
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
