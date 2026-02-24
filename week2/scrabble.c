// scrabble.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Scrabble
// -------------------
// Two players each enter a word. Compute each word's Scrabble score
// and announce the winner (or a tie).
//
// How to compile:  make scrabble
// How to run:      ./scrabble
// How to check:    check50 cs50/problems/2024/x/scrabble

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Point values for each letter A-Z (index 0 = A, index 25 = Z)
// Do NOT modify this array.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//              A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P   Q  R  S  T  U  V  W  X  Y   Z

// Function prototype — do NOT change this signature
int compute_score(string word);

int main(void)
{
    // Prompt both players for their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores for each player
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner (or "Tie!" if scores are equal)
    //
    //   If score1 > score2 → printf("Player 1 wins!\n");
    //   If score2 > score1 → printf("Player 2 wins!\n");
    //   If equal           → printf("Tie!\n");

}

// ---------------------------------------------------------------------------
// TODO: Implement compute_score
// ---------------------------------------------------------------------------
// Given a word, return its Scrabble score.
//
// Rules:
//   - Use the POINTS array to look up each letter's value
//   - Uppercase and lowercase letters have the SAME point value
//   - Non-letter characters (spaces, punctuation) score 0 points
//
// Hints:
//   - Loop through each character: for (int i = 0; i < strlen(word); i++)
//   - Check if a char is uppercase: isupper(word[i])
//   - For uppercase 'A': POINTS['A' - 'A'] = POINTS[0] = 1
//   - For lowercase 'a': POINTS['a' - 'a'] = POINTS[0] = 1
//   - Use isalpha(word[i]) to skip non-letter characters
// ---------------------------------------------------------------------------
int compute_score(string word)
{
    int score = 0;

    // TODO: Loop through each character of word
    // TODO: Add the correct point value to score
    // TODO: Return the total score

    return score;
}
