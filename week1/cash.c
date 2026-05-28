//Arda portakal AIE İNT TO PROGRAMİNG HOMEWORK

#include <cs50.h>
#include <stdio.h>


int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Get the number of cents owed
    int cents = get_cents();

    // Calculate the number of each coin
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);

    // Print the total number of coins
    printf("%i\n", quarters + dimes + nickels + pennies);
}

// Prompt the user for a non-negative number of cents
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

// Return how many quarters fit in `cents`
int calculate_quarters(int cents)
{
    return cents / 25;
}

// Return how many dimes fit in `cents`
int calculate_dimes(int cents)
{
    return cents / 10;
}

// Return how many nickels fit in `cents`
int calculate_nickels(int cents)
{
    return cents / 5;
}

// Return how many pennies fit in `cents`
int calculate_pennies(int cents)
{
    return cents;
}
