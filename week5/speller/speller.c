#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

#define DICTIONARY "dictionaries/large"

double calculate(const struct rusage *b, const struct rusage *a);

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./speller [DICTIONARY] text\n");
        return 1;
    }

    struct rusage before, after;

    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;

    getrusage(RUSAGE_SELF, &before);
    bool loaded = load(dictionary);
    getrusage(RUSAGE_SELF, &after);

    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    time_load = calculate(&before, &after);

    char *text = (argc == 3) ? argv[2] : argv[1];
    FILE *file = fopen(text, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", text);
        unload();
        return 1;
    }

    printf("\nMISSPELLED WORDS\n\n");

    int index = 0, misspellings = 0, words = 0;
    char word[LENGTH + 1];
    char c;

    while (fread(&c, sizeof(char), 1, file))
    {
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            word[index++] = c;

            if (index > LENGTH)
            {
                while (fread(&c, sizeof(char), 1, file) && isalpha(c));
                index = 0;
            }
        }
        else if (index > 0)
        {
            word[index] = '\0';
            words++;

            getrusage(RUSAGE_SELF, &before);
            bool misspelled = !check(word);
            getrusage(RUSAGE_SELF, &after);

            time_check += calculate(&before, &after);

            if (misspelled)
            {
                printf("%s\n", word);
                misspellings++;
            }

            index = 0;
        }
    }

    fclose(file);

    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);
    time_size = calculate(&before, &after);

    getrusage(RUSAGE_SELF, &before);
    bool unloaded = unload();
    getrusage(RUSAGE_SELF, &after);
    time_unload = calculate(&before, &after);

    if (!unloaded)
    {
        printf("Could not unload dictionary.\n");
        return 1;
    }

    printf("\nWORDS MISSPELLED:     %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", n);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n",
           time_load + time_check + time_size + time_unload);

    return 0;
}

double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }

    return (((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
             (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec) +
             (a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
             (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec))
            / 1000000.0);
}
