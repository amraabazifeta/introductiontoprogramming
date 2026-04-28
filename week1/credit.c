#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    long number;
    
    // Kullanıcıdan kart numarasını al (get_long alternatifi)
    printf("Number: ");
    if (scanf("%ld", &number) != 1)
    {
        printf("INVALID\n");
        return 0;
    }

    // STEP 1: Basamak sayısını say ve ilk iki haneyi bulmak için kopyalar oluştur
    int length = 0;
    long temp = number;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Geçersiz uzunluk kontrolü (Hızlı eleme)
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // STEP 2: Luhn Algoritması
    int sum_doubled = 0;
    int sum_rest = 0;
    temp = number;

    for (int i = 0; i < length; i++)
    {
        int digit = temp % 10;
        
        if (i % 2 == 1) // Tekil pozisyonlar (sondan ikinci, dördüncü vb.)
        {
            int doubled = digit * 2;
            // Eğer çarpım 10 veya üzeriyse basamaklarını topla (örn: 14 -> 1+4 = 5)
            sum_doubled += (doubled / 10) + (doubled % 10);
        }
        else // Çift pozisyonlar (sonuncu, sondan üçüncü vb.)
        {
            sum_rest += digit;
        }
        temp /= 10;
    }

    // STEP 3: Luhn kontrolü
    if ((sum_doubled + sum_rest) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // STEP 4: Kart tipini belirle
    // İlk iki haneyi bul
    long first_two = number;
    while (first_two >= 100)
    {
        first_two /= 10;
    }
    int first_digit = first_two / 10;

    // AMEX: 15 haneli, 34 veya 37 ile başlar
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    // MASTERCARD: 16 haneli, 51-55 arası ile başlar
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    // VISA: 13 veya 16 haneli, 4 ile başlar
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}