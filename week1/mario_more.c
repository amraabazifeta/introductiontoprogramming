#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for a height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 8 || height > 1);

    // Print the pyramid
    for (int row = 1; row <= height; row++)
    {
        // Print spaces
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#  #");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
