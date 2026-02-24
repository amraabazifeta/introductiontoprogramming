// mario.c
// CS50x - Week 1, Problem Set 1
//
// Exercise: Mario (Less Comfortable)
// ------------------------------------
// Print a right-aligned half-pyramid of # symbols.
// The user provides the height (1–8).
//
// Expected output (height = 4):
//    #
//   ##
//  ###
// ####
//
// How to compile:  make mario
// How to run:      ./mario
// How to check:    check50 cs50/problems/2024/x/mario/less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // TODO: Use a do-while loop to prompt for height.
    //       Keep re-prompting until height is between 1 and 8 (inclusive).
    do
    {
        // TODO: Get an integer from the user with prompt "Height: "

    }
    while (/* TODO: condition to keep looping */ false);

    // TODO: Use a for loop to iterate over each row (1 through height).
    for (int row = 1; row <= height; row++)
    {
        // TODO: Print (height - row) spaces using a for loop.


        // TODO: Print (row) hashes using a for loop.


        // Print a newline to end the row.
        printf("\n");
    }

    return 0;
}
