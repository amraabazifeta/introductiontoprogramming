#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build the pyramid row by row
    for (int row = 1; row <= height; row++)
    {
        // Print leading spaces for the right alignment
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes for the LEFT pyramid
        for (int left_hash = 0; left_hash < row; left_hash++)
        {
            printf("#");
        }

        // Print the gap between pyramids (always 2 spaces)
        printf("  ");

        // Print hashes for the RIGHT pyramid
        for (int right_hash = 0; right_hash < row; right_hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
