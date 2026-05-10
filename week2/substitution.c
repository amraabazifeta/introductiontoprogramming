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
<<<<<<< HEAD
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
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
<<<<<<< HEAD
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
=======
    // Must be called with exactly one argument.
    // The key must be valid (see is_valid_key below).
    //
    // If invalid:
    //   printf("Usage: ./substitution key\n");
    //   return 1;

    // TODO: Check argc == 2
    // TODO: Check is_valid_key(argv[1])

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // ---------------------------------------------------------------------------
    // STEP 2: Get the plaintext from the user
    // ---------------------------------------------------------------------------
    // TODO: Use get_string("plaintext:  ") and store in a variable
<<<<<<< HEAD
    string plaintext = get_string("plaintext:  ");
    string key = argv[1];
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // ---------------------------------------------------------------------------
    // STEP 3: Encrypt and print ciphertext
    // ---------------------------------------------------------------------------
<<<<<<< HEAD
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
=======
    // For each character in plaintext:
    //   - If it's a letter, find its position in the alphabet (0-25)
    //   - Look up the substituted letter from argv[1] at that position
    //   - Preserve the original case
    //   - Non-letters are printed unchanged
    //
    // TODO: Print "ciphertext: " then loop through each character
    //
    // Hints:
    //   Position of uppercase C: 'C' - 'A' = 2
    //   Position of lowercase c: 'c' - 'a' = 2
    //   The substituted letter: argv[1][position]
    //   To preserve case: if original was uppercase, use toupper(substituted_letter)
    //                     if original was lowercase, use tolower(substituted_letter)

    printf("ciphertext: ");

    // TODO: loop and print each encrypted character
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------
// TODO: Implement is_valid_key
// ---------------------------------------------------------------------------
<<<<<<< HEAD
=======
// Return true if the key is valid, false otherwise.
//
// A valid key:
//   1. Is exactly 26 characters long
//   2. Contains only alphabetic characters (no digits, spaces, symbols)
//   3. Contains each letter exactly once (no duplicates — case-insensitive)
//
// Hints:
//   - strlen(key) == 26
//   - isalpha(key[i]) to check each character
//   - To check for duplicates, use a boolean array of size 26:
//       bool seen[26] = {false};
//     Then for each character, check if seen[tolower(c) - 'a'] is already true.
//     If yes → duplicate found → return false
//     If no  → mark it as seen and continue
// ---------------------------------------------------------------------------
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
bool is_valid_key(string key)
{
    // TODO: Check length is 26
    if (strlen(key) != 26)
    {
        return false;
    }

<<<<<<< HEAD
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
=======
    // TODO: Check all characters are alphabetic
    // TODO: Check for duplicates using a seen[] array

    return true; // placeholder — replace this
}
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
