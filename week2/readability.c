//arda_portakal in to programing

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string text = get_string("Text: ");


    int letters   = count_letters(text);
    int words     = count_words(text);
    int sentences = count_sentences(text);


    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;


    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}


int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // Checks if the character is an alphabet letter
        {
            count++;
        }
    }
    return count;
}


int count_words(string text)
{
    int count = 1; // Starts at 1 because 1 space means 2 words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ') // Checks for spaces
        {
            count++;
        }
    }
    return count;
}


int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Checks for standard sentence-ending punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
