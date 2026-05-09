// credit.c
// CS50x - Week 1, Problem Set 1

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for credit card number
    long card = get_long("Number: ");

    // STEP 1: Count digits
    int length = 0;
    long temp = card;
    while (temp > 0)
    {
        length++;
        temp /= 10;
    }

    // STEP 2: Luhn's Algorithm
    int sum_doubled = 0;
    int sum_rest = 0;
    temp = card;

    for (int i = 0; temp > 0; i++)
    {
        int digit = temp % 10;
        temp /= 10;

        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            if (doubled >= 10)
            {
                sum_doubled += doubled / 10 + doubled % 10;
            }
            else
            {
                sum_doubled += doubled;
            }
        }
        else
        {
            sum_rest += digit;
        }
    }

    // STEP 3: Check validity
    if ((sum_doubled + sum_rest) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // STEP 4: Identify card type
    long first2 = card;
    while (first2 >= 100)
    {
        first2 /= 10;
    }

    if (length == 15 && (first2 == 34 || first2 == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && first2 >= 51 && first2 <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first2 / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}