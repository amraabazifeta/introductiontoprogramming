// CS50x Week 5 — Speller: dictionary.c

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

// Global word counter
unsigned int word_count = 0;

// TODO 1: hash
unsigned int hash(const char *word)
{
    unsigned long hash_val = 5381;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_val = ((hash_val << 5) + hash_val) + tolower(word[i]);
    }
    return hash_val % N;
}

// TODO 2: load
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

// TODO 3: check
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

// TODO 4: size
unsigned int size(void)
{
    return word_count;
}

// TODO 5: unload
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