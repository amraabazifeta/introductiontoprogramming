// credit.c
// CS50x - Week 1, Problem Set 1
// Student: Resul
// --------------------------------
// This program validates credit card numbers using Luhn's Algorithm
// and identifies the card issuer (AMEX, MASTERCARD, or VISA).

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Step 0: Get user input
    long card_number = get_long("Number: ");

    // Step 1: Count length and find starting digits
    int length = 0;
    long temp_number = card_number;
    long start_digits = card_number;

    while (temp_number > 0)
    {
        temp_number = temp_number / 10;
        length++;
    }

    // Get the first two digits for card type identification
    while (start_digits >= 100)
    {
        start_digits = start_digits / 10;
    }

    // Step 2: Luhn's Algorithm
    int sum_doubled = 0;
    int sum_rest = 0;
    long check_number = card_number;

    for (int i = 0; i < length; i++)
    {
        int digit = check_number % 10;

        // If position is odd (starting from second-to-last)
        if (i % 2 != 0)
        {
            int product = digit * 2;
            // If product is 10 or more, add digits (e.g., 12 -> 1 + 2 = 3)
            sum_doubled += (product % 10) + (product / 10);
        }
        else
        {
            // If position is even, add digit normally
            sum_rest += digit;
        }
        check_number = check_number / 10;
    }

    // Step 3: Check validity and identify card type
    int total_sum = sum_doubled + sum_rest;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // AMEX: 15 digits, starts with 34 or 37
    else if (length == 15 && (start_digits == 34 || start_digits == 37))
    {
        printf("AMEX\n");
    }
    // MASTERCARD: 16 digits, starts with 51 to 55
    else if (length == 16 && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // VISA: 13 or 16 digits, starts with 4
    else if ((length == 13 || length == 16) && (start_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
