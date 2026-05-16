#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);

    printf("%i\n", quarters + dimes + nickels + pennies);
}

// Get valid input
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

// Quarters
int calculate_quarters(int cents)
{
    return cents / 25;
}

// Dimes
int calculate_dimes(int cents)
{
    return cents / 10;
}

// Nickels
int calculate_nickels(int cents)
{
    return cents / 5;
}

// Pennies
int calculate_pennies(int cents)
{
    return cents;
}
