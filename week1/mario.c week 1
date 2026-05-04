// mario.c
// CS50x - Week 1, Problem Set 1
// Student: Resul
// ------------------------------------
// This program prints a right-aligned pyramid of hashes (#)
// based on a user-provided height between 1 and 8.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Step 1: Prompt the user for a valid height
    // The height must be between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Step 2: Build the pyramid row by row
    for (int row = 1; row <= height; row++)
    {
        // Step 2a: Print the necessary spaces for right-alignment
        // For each row, we need (height - row) spaces
        for (int spaces = 0; spaces < height - row; spaces++)
        {
            printf(" ");
        }

        // Step 2b: Print the hashes (#)
        // For each row, we need (row) number of hashes
        for (int hashes = 0; hashes < row; hashes++)
        {
            printf("#");
        }

        // Step 3: Move to the next line after finishing the row
        printf("\n");
    }

    return 0;
}
