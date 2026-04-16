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
        for (int i = 0; i < height - row; i++)
        {
            printf(" ");
        }

        for (int i = 0; i < row; i++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
