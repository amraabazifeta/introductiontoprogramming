// caesar.c
// CS50x - Week 2, Problem Set 2
// Student: Resul
// ------------------------
// This program encrypts messages using Caesar's cipher.
// It takes a numeric key as a command-line argument and rotates 
// each alphabetical character by that key.

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
    // Step 1: Validate command-line arguments
    // Must have exactly two arguments and the second one must be numeric
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Step 2: Convert the key from string to int
    int key = atoi(argv[1]);

    // Step 3: Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // Step 4: Encrypt and print the ciphertext
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Encrypt each character and print it
        printf("%c", rotate(plaintext[i], key));
    }

    // Print a newline at the end
    printf("\n");
    return 0;
}

// Function to check if a string consists only of digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If any character is not a digit, return false
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by n positions
char rotate(char c, int n)
{
    // If the character is an uppercase letter
    if (isupper(c))
    {
        // Shift ASCII to 0-25 range, rotate, and shift back to 'A'
        return (c - 'A' + n) % 26 + 'A';
    }
    // If the character is a lowercase letter
    else if (islower(c))
    {
        // Shift ASCII to 0-25 range, rotate, and shift back to 'a'
        return (c - 'a' + n) % 26 + 'a';
    }
    // If it's not a letter, return it as it is
    else
    {
        return c;
    }
}
