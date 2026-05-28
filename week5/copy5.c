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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *s = get_string("s: ");


    if (/* ??? */)
    {
        return 1;
    }


    char *t = malloc(strlen(s) + 1);


    if (/* ??? */)
    {
        return 1;
    }


    strcpy(/* ??? */, /* ??? */);


    if (strlen(t) > 0)
    {
        t[0] = toupper(/* ??? */);
    }


    printf("s: %s\n", s);
    printf("t: %s\n", t);

    

    return 0;
}
