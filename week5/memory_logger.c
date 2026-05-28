#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *words[5];

    for (int i = 0; i < 5; i++)
    {
        string input = get_string("Enter word %i: ", i + 1);

        words[i] = malloc(strlen(input) + 1);

        if (words[i] == NULL)
        {
            return 1;
        }

        strcpy(words[i], input);

        words[i][0] = toupper(words[i][0]);
    }

    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(file, "%s\n", words[i]);
    }

    fclose(file);
    printf("\nWords saved to log.txt!\n");

    for (int i = 0; i < 5; i++)
    {
        free(words[i]);
    }

    return 0;
}