//arda_portkal int to programing homework

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *s = get_string("s: ");


    char *t = malloc(/* ??? */);


    for (int i = 0; i <= strlen(s); i++)
    {
        t[i] = /* ??? */;
    }


    t[0] = toupper(/* ??? */);


    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
