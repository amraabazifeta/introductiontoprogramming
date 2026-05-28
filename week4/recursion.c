//arda_portakal_homework
#include <cs50.h>
#include <stdio.h>


void draw(int n);

int main(void)
{
    int height;


    do
    {
        height = get_int("Input: ");
    }
    while (height < 1);


    draw(height);

    return 0;
}

void draw(int n)
{

    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
