// mario_more.c
// CS50x - Week 1, Problem Set 1 (Bonus)
// Student: Resul
// ------------------------------------
// This program prints a double half-pyramid with a 
// two-space gap in the middle, based on user input.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Step 1: Input validation (Height must be between 1 and 8)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Step 2: Loop through each row to build the double pyramid
    for (int row = 1; row <= height; row++)
    {
        // Step 2a: Print leading spaces for the left pyramid
        for (int spaces = 0; spaces < height - row; spaces++)
        {
            printf(" ");
        }

        // Step 2b: Print hashes for the LEFT side
        for (int i = 0; i < row; i++)
        {
            printf("#");
        }

        // Step 2c: Print the mandatory two-space gap
        printf("  ");

        // Step 2d: Print hashes for the RIGHT side
        // Note: No trailing spaces are needed after this
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        // Step 3: Move to the next row
        printf("\n");
    }

    return 0;
}
