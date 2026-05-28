//Arda portakal AIE İNT TO PROGRAMİNG HOMEWORK

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

        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }


        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }


        printf("\n");
    }

    return 0;
}
