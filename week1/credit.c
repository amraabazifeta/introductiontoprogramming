// credit.c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Kart numarasını al
    long number = get_long("Number: ");
    long temp = number;

    // ---------------------------
    // STEP 1: Basamak sayısı
    // ---------------------------
    int length = 0;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // ---------------------------
    // STEP 2: Luhn Algorithm
    // ---------------------------
    int sum_doubled = 0;
    int sum_rest = 0;

    int i = 0;
    temp = number;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            if (doubled >= 10)
            {
                sum_doubled += (doubled / 10) + (doubled % 10);
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

        temp /= 10;
        i++;
    }

    int total = sum_doubled + sum_rest;

    // ---------------------------
    // STEP 3: Geçerli mi?
    // ---------------------------
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // ---------------------------
    // STEP 4: Kart türü
    // ---------------------------
    temp = number;
    while (temp >= 100)
    {
        temp /= 10;
    }

    int first2 = temp;
    int first1 = temp / 10;

    if (length == 15 && (first2 == 34 || first2 == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first2 >= 51 && first2 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first1 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
