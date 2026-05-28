//arda-portakal
#include <stdio.h>

int main(void)
{
    int n;


    do
    {
        printf("Input: ");
        scanf("%d", &n);
    }
    while (n < 1);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
