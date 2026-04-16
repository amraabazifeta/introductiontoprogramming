#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            printf("%c", toupper(argv[1][index]));
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            printf("%c", tolower(argv[1][index]));
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
            return false;
        }

        seen[index] = true;
    }

    return true;
}
