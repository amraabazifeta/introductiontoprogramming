//arda_portakal_homework
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 50, 25, 8, 14, 33};
    int target = get_int("Number: ");

    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == target)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
