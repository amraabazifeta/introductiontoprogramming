// substitution.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Substitution Cipher
// ------------------------------
// Encrypt a message using a 26-character substitution key.
// Each letter in the key maps to the corresponding letter of the alphabet:
//   Key:  VCHPRZGJNTLSKFBDQWAXEUYMOI
//   A→V, B→C, C→H, D→P, E→R, F→Z, ...
//
// Usage:
//   ./substitution KEY    (KEY = 26 unique letters, case-insensitive)
//   ./substitution        → prints usage error
//   ./substitution ABCD   → prints usage error (not 26 chars)
//   ./substitution AABCDE...  → prints usage error (duplicate letters)
//
// How to compile:  make substitution
// How to run:      ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
// How to check:    check50 cs50/problems/2024/x/substitution
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // ---------------------------------------------------------------------------
    // STEP 1: Validate command-line arguments
    // ---------------------------------------------------------------------------
    // TODO: Check argc == 2
    // TODO: Check is_valid_key(argv[1])
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // ---------------------------------------------------------------------------
    // STEP 2: Get the plaintext from the user
    // ---------------------------------------------------------------------------
    // TODO: Use get_string("plaintext:  ") and store in a variable
    string plaintext = get_string("plaintext:  ");
    string key = argv[1];

    // ---------------------------------------------------------------------------
    // STEP 3: Encrypt and print ciphertext
    // ---------------------------------------------------------------------------
    printf("ciphertext: ");

    // TODO: loop and print each encrypted character
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                // Find position (0-25) and use key's letter in uppercase
                int index = plaintext[i] - 'A';
                printf("%c", toupper(key[index]));
            }
            else
            {
                // Find position (0-25) and use key's letter in lowercase
                int index = plaintext[i] - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // Non-letters are printed unchanged
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------
// TODO: Implement is_valid_key
// ---------------------------------------------------------------------------
bool is_valid_key(string key)
{
    // TODO: Check length is 26
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        // TODO: Check all characters are alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // TODO: Check for duplicates using a seen[] array
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}