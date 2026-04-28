#include <stdio.h>

// Fonksiyon prototipleri
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ödenecek kuruş miktarını al
    int cents = get_cents();

    // Her bir bozuk para türünden kaç tane gerektiğini hesapla
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);

    // Toplam bozuk para sayısını yazdır
    printf("%i\n", quarters + dimes + nickels + pennies);

    return 0;
}

// Kullanıcıdan negatif olmayan bir kuruş değeri iste
int get_cents(void)
{
    int n;
    do
    {
        printf("Change owed: ");
        // scanf kullanımı: kullanıcı sayı girmezse veya negatif girerse tekrar sorar
        if (scanf("%i", &n) != 1) 
        {
            // Hatalı girişi temizlemek için (örn: harf girilirse)
            while (getchar() != '\n'); 
            n = -1;
        }
    }
    while (n < 0);
    return n;
}

// 25 kuruşlukların sayısını döndür
int calculate_quarters(int cents)
{
    return cents / 25;
}

// 10 kuruşlukların sayısını döndür
int calculate_dimes(int cents)
{
    return cents / 10;
}

// 5 kuruşlukların sayısını döndür
int calculate_nickels(int cents)
{
    return cents / 5;
}

// 1 kuruşlukların sayısını döndür
int calculate_pennies(int cents)
{
    return cents;
}