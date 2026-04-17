#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define N 26

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *table[N];
unsigned int word_count = 0;

unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%45s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(n->word, word);

        unsigned int index = hash(word);
        n->next = table[index];
        table[index] = n;

        word_count++;
    }

    fclose(file);
    return true;
}

bool check(const char *word)
{
    unsigned int index = hash(word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }

    return true;
}
