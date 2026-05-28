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

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./cp source destination\n");
        return 1;
    }


    FILE *src = fopen(/* ??? */, /* ??? */);
    if (src == NULL)
    {
        printf("Could not open source file.\n");
        return 1;
    }


    FILE *dst = fopen(/* ??? */, /* ??? */);
    if (dst == NULL)
    {
        printf("Could not open destination file.\n");
        fclose(src);
        return 1;
    }

    BYTE b;


    while (fread(/* ??? */, sizeof(b), 1, src) != 0)
    {
        fwrite(/* ??? */, sizeof(b), 1, dst);
    }

    

    return 0;
}
