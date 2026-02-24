// readability.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Readability
// ----------------------
// Compute the Coleman-Liau readability index of a text sample
// and print the corresponding U.S. grade level.
//
// Formula:
//   index = 0.0588 * L - 0.296 * S - 15.8
//   L = average letters per 100 words
//   S = average sentences per 100 words
//
// Output:
//   index >= 16  → "Grade 16+"
//   index < 1   → "Before Grade 1"
//   otherwise   → "Grade X"
//
// How to compile:  make readability   (links -lm automatically via cs50.h)
// How to run:      ./readability
// How to check:    check50 cs50/problems/2024/x/readability

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

    // TODO: Compute L and S (averages per 100 words)
    //   Hint: cast to float before dividing to avoid integer division!
    //   float L = 100.0 * letters / words;
    //   float S = 100.0 * sentences / words;


    // TODO: Apply the Coleman-Liau formula
    //   index = round(0.0588 * L - 0.296 * S - 15.8)
    //   Use round() from <math.h> and store as int


    // TODO: Print the grade level
    //   if index >= 16  → printf("Grade 16+\n");
    //   if index < 1    → printf("Before Grade 1\n");
    //   otherwise       → printf("Grade %i\n", index);

}

// ---------------------------------------------------------------------------
// TODO: Implement count_letters
// ---------------------------------------------------------------------------
// Return the number of letters (a-z, A-Z) in text.
// Hint: use isalpha() to check if a character is a letter.
// ---------------------------------------------------------------------------
int count_letters(string text)
{
    int count = 0;

    // TODO: Loop through each character of text
    // TODO: Increment count if the character is alphabetic


    return count;
}

// ---------------------------------------------------------------------------
// TODO: Implement count_words
// ---------------------------------------------------------------------------
// Return the number of words in text.
// Assume: words are separated by single spaces, no leading/trailing spaces.
// Hint: number of words = number of spaces + 1
// ---------------------------------------------------------------------------
int count_words(string text)
{
    int count = 1; // Start at 1: at least one word if text is non-empty

    // TODO: Loop through text and count spaces


    return count;
}

// ---------------------------------------------------------------------------
// TODO: Implement count_sentences
// ---------------------------------------------------------------------------
// Return the number of sentences in text.
// A sentence ends with '.', '!', or '?'
// ---------------------------------------------------------------------------
int count_sentences(string text)
{
    int count = 0;

    // TODO: Loop through text
    // TODO: Increment count whenever you see '.', '!', or '?'


    return count;
}
