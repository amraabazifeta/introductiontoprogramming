// mario_more.c
// CS50x - Week 1, Problem Set 1 (Bonus)
//
// Exercise: Mario (More Comfortable)
// ------------------------------------
// Print a DOUBLE half-pyramid separated by a two-space gap.
//
// Expected output (height = 4):
//    #  #
//   ##  ##
//  ###  ###
// ####  ####
//
// How to compile:  make mario_more
// How to run:      ./mario_more
// How to check:    check50 cs50/problems/2024/x/mario/more

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // TODO: Same do-while input validation as mario.c (height 1–8)
    do
    {
        // TODO: Prompt for height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // TODO: Print each row of the double pyramid
    for (int row = 1; row <= height; row++)
    {
        // TODO: Print (height - row) leading spaces
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // TODO: Print (row) hashes — LEFT side
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // The gap between the two pyramids is always exactly two spaces.
        printf("  ");

        // TODO: Print (row) hashes — RIGHT side (mirror of left, no leading spaces)
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}