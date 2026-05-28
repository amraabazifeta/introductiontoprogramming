//arda_portkal int to programing homework


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string s = get_string("s: ");


    string t = s;


    t[0] = toupper(t[0]);

    
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
