#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();
    int coins = 0;

    coins += calculate_quarters(cents);
    cents = cents % 25;

    coins += calculate_dimes(cents);
    cents = cents % 10;

    coins += calculate_nickels(cents);
    cents = cents % 5;

    coins += calculate_pennies(cents);

    printf("%d\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents;
}
