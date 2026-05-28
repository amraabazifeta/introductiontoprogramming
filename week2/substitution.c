//arda_portakal 

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototype
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // 1. Validate command-line arguments
    // Must be exactly 2 arguments (the program name and the key)
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Save the valid key into a variable for easier use
    string key = argv[1];

    // 2. Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // 3. Encrypt and print ciphertext
    printf("ciphertext: ");

    // Loop through each character of the plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        // If the character is a letter, encrypt it
        if (isalpha(c))
        {
            if (isupper(c))
            {
                // Find alphabet position (0-25), look it up in key, make uppercase
                int index = c - 'A';
                printf("%c", toupper(key[index]));
            }
            else if (islower(c))
            {
                // Find alphabet position (0-25), look it up in key, make lowercase
                int index = c - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // Non-letters (spaces, punctuation) are printed exactly as they are
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------
// Return true if the key is valid (26 chars, only letters, no duplicates)
// ---------------------------------------------------------------------------
bool is_valid_key(string key)
{
    // Check length is exactly 26
    if (strlen(key) != 26)
    {
        return false;
    }

    // Array to keep track of which letters we have seen so far
    // Initializes all 26 slots to false
    bool seen[26] = {false};

    // Loop through each character of the key
    for (int i = 0; i < 26; i++)
    {
        char c = key[i];

        // 1. Check if it's an alphabetic character
        if (!isalpha(c))
        {
            return false;
        }

        // 2. Check for duplicates
        // Convert letter to lowercase, then subtract 'a' to get its 0-25 index
        int index = tolower(c) - 'a';

        // If the slot is already true, we've seen this letter before!
        if (seen[index])
        {
            return false;
        }

        // Mark this letter as seen
        seen[index] = true;
    }

    return true;
}
