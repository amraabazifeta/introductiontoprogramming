#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // STEP 1: validate arguments
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // STEP 2: get plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // STEP 3: encrypt
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';
            char encrypted = toupper(key[index]);
            printf("%c", encrypted);
        }
        else if (islower(c))
        {
            int index = c - 'a';
            char encrypted = tolower(key[index]);
            printf("%c", encrypted);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}

// -----------------------------------------------------
// Validate key
// -----------------------------------------------------
bool is_valid_key(string key)
{
    // must be 26 chars
    if (strlen(key) != 26)
    {
        return false;
    }

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
            return false; // duplicate letter
        }

        seen[index] = true;
    }

    return true;
}
