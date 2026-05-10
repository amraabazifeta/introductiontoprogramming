#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes — do NOT change these signatures
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters   = count_letters(text);
    int words     = count_words(text);
    int sentences = count_sentences(text);

    // Compute L and S (averages per 100 words)
    float L = 100.0 * letters / words;
    float S = 100.0 * sentences / words;

    // Apply the Coleman-Liau formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
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
}

// ---------------------------------------------------------------------------
// Return the number of letters (a-z, A-Z) in text.
// ---------------------------------------------------------------------------
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// ---------------------------------------------------------------------------
// Return the number of words in text.
// ---------------------------------------------------------------------------
int count_words(string text)
{
    int count = 1; // At least one word

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

// ---------------------------------------------------------------------------
// Return the number of sentences in text.
// ---------------------------------------------------------------------------
int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}
