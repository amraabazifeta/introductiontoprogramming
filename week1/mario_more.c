// mario_more.c
// CS50x - Week 1, Problem Set 1 (Bonus)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {
        // Print leading spaces
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print left hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Gap
        printf("  ");

        // Print right hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}