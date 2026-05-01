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
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // ---------------------------------------------------------------------------
    // STEP 2: Convert the key from string to int
    // ---------------------------------------------------------------------------
    int key = atoi(argv[1]);

    // Reduce key to range 0–25 to avoid unnecessary rotations
    key = key % 26;

    // ---------------------------------------------------------------------------
    // STEP 3: Get the plaintext from the user
    // ---------------------------------------------------------------------------
    string plaintext = get_string("plaintext: ");

    // ---------------------------------------------------------------------------
    // STEP 4: Encrypt and print the ciphertext
    // ---------------------------------------------------------------------------
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------
// Return true if every character in s is a digit (0-9), false otherwise.
// ---------------------------------------------------------------------------
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// Rotate character c forward by n positions in the alphabet.
// ---------------------------------------------------------------------------
char rotate(char c, int n)
{
    if (isupper(c))
    {
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        return c;
    }
}
