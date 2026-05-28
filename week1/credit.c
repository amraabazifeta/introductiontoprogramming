//Arda portakal AIE İNT TO PROGRAMİNG HOMEWORK

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long card_number = get_long("Number: ");


    int length = 0;
    long temp = card_number;
    long first_two = card_number;

    while (temp > 0)
    {
        temp = temp / 10;
        length++;
    }

    while (first_two >= 100)
    {
        first_two = first_two / 10;
    }


    long cc = card_number;
    int sum_doubled = 0;
    int sum_rest = 0;
    int i = 0;

    while (cc > 0)
    {
        int digit = cc % 10;


        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            sum_doubled += (doubled % 10) + (doubled / 10);
        }
        else
        {
            sum_rest += digit;
        }

        cc = cc / 10;
        i++;
    }


    int total_sum = sum_doubled + sum_rest;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
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

    return 0;
}
