// substitution.c
// CS50x - Week 2, Problem Set 2

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // STEP 1: Validate arguments
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // STEP 2: Get plaintext
    string plaintext = get_string("plaintext:  ");

    // STEP 3: Encrypt and print
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int position = plaintext[i] - 'A';
            printf("%c", toupper(argv[1][position]));
        }
        else if (islower(plaintext[i]))
        {
            int position = plaintext[i] - 'a';
            printf("%c", tolower(argv[1][position]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    // Check length
    if (strlen(key) != 26)
    {
        return false;
    }

    // Check all alphabetic and no duplicates
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}