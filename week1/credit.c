<<<<<<< HEAD
=======
// credit.c
// CS50x - Week 1, Problem Set 1
//
// Exercise: Credit Card Validator
// --------------------------------
// Validate a credit card number using Luhn's Algorithm,
// then identify whether it is AMEX, MASTERCARD, VISA, or INVALID.
//
// How to compile:  make credit
// How to run:      ./credit
// How to check:    check50 cs50/problems/2024/x/credit

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
#include <cs50.h>
#include <stdio.h>

// ---------------------------------------------------------------------------
// Luhn's Algorithm (overview)
// ---------------------------------------------------------------------------
// 1. Starting from the SECOND-TO-LAST digit, multiply every other digit by 2.
// 2. If any product >= 10, add its digits together (e.g. 14 → 1+4 = 5).
// 3. Sum all those results → call it sum_doubled.
// 4. Sum all the OTHER digits (the ones you didn't double) → call it sum_rest.
// 5. If (sum_doubled + sum_rest) % 10 == 0, the number is VALID.
// ---------------------------------------------------------------------------
// Card type detection:
//   AMEX:       15 digits, starts with 34 or 37
//   MASTERCARD: 16 digits, starts with 51–55
//   VISA:       13 or 16 digits, starts with 4
// ---------------------------------------------------------------------------

int main(void)
{
    // TODO: Prompt user for a credit card number using get_long()
    //       Hint: card numbers can exceed int range — use `long`
<<<<<<< HEAD
    long number = get_long("Number: ");
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // -----------------------------------------------------------------------
    // STEP 1: Count the number of digits
    // -----------------------------------------------------------------------
    int length = 0;

    // TODO: Use a loop to count digits.
    //       Hint: make a copy of the number, divide by 10 each iteration,
    //       stop when the copy reaches 0.
<<<<<<< HEAD
    long count_copy = number;
    while (count_copy > 0)
    {
        count_copy /= 10;
        length++;
    }
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // -----------------------------------------------------------------------
    // STEP 2: Apply Luhn's Algorithm
    // -----------------------------------------------------------------------
    int sum_doubled = 0;  // sum of doubled every-other digits
    int sum_rest    = 0;  // sum of the remaining digits

    // TODO: Loop through each digit of the card number.
    //       Use modulo 10 to extract the last digit, then divide by 10.
    //       Use a counter (i) to track position: i=0 is the LAST digit,
    //       i=1 is second-to-last (this is the FIRST one to double), etc.
    //
    //       If position i is ODD  → double the digit, handle >= 10 case,
    //                                add to sum_doubled
    //       If position i is EVEN → add directly to sum_rest
<<<<<<< HEAD
    long luhn_copy = number;
    for (int i = 0; i < length; i++)
    {
        int digit = luhn_copy % 10;
        if (i % 2 == 1)
        {
            int product = digit * 2;
            // Eğer çarpım 10 veya üzeriyse rakamlarını topla (örn: 12 -> 1+2=3)
            sum_doubled += (product / 10) + (product % 10);
        }
        else
        {
            sum_rest += digit;
        }
        luhn_copy /= 10;
    }
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // -----------------------------------------------------------------------
    // STEP 3: Check validity
    // -----------------------------------------------------------------------
    // TODO: If (sum_doubled + sum_rest) % 10 != 0, print INVALID and return.
<<<<<<< HEAD
    if ((sum_doubled + sum_rest) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // -----------------------------------------------------------------------
    // STEP 4: Identify card type
    // -----------------------------------------------------------------------
    // TODO: Extract the first two digits of the card number.
    //       Hint: keep dividing by 10 until only 2 digits remain.
<<<<<<< HEAD
    long first_two_copy = number;
    while (first_two_copy >= 100)
    {
        first_two_copy /= 10;
    }
    int first2 = (int) first_two_copy;
    int first1 = first2 / 10;
=======

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

    // TODO: Use if/else if to check length + starting digits:
    //
    //   AMEX:       length == 15 && (first2 == 34 || first2 == 37)
    //   MASTERCARD: length == 16 && first2 >= 51 && first2 <= 55
    //   VISA:       (length == 13 || length == 16) && first digit == 4
    //               Hint for VISA: first2 / 10 == 4
    //   Otherwise:  INVALID
<<<<<<< HEAD
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
=======


}
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
