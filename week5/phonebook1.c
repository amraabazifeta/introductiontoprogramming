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

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    FILE *file = fopen(/* ??? */, /* ??? */);


    if (/* ??? */)
    {
        return 1;
    }


    char *name = get_string("Name: ");
    char *number = get_string("Number: ");


    fprintf(file, /* ??? */, name, number);

   

    return 0;
}
