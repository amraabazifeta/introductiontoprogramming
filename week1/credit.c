#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number
    long card = get_long("Number: ");

    long temp = card;

    // STEP 1: Count digits
    int length = 0;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // STEP 2: Luhn's Algorithm
    int sum_doubled = 0;
    int sum_rest = 0;

    temp = card;
    int position = 0;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 0)
        {
            sum_rest += digit;
        }
        else
        {
            int doubled = digit * 2;

            if (doubled > 9)
            {
                sum_doubled += (doubled / 10) + (doubled % 10);
            }
            else
            {
                sum_doubled += doubled;
            }
        }

        temp /= 10;
        position++;
    }

    // STEP 3: Validate
    if ((sum_doubled + sum_rest) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // STEP 4: Get first two digits
    long first_two = card;

    while (first_two >= 100)
    {
        first_two /= 10;
    }

    // STEP 5: Identify card type
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && first_two >= 51 && first_two <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
