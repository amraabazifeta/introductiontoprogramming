#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for their name
    string name = get_string("What is your name? ");

    // Print greeting
    printf("hello, %s\n", name);
}
