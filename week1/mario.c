#include <stdio.h>

int main(void)
{
    int height;

    // Kullanıcıdan 1-8 arası bir yükseklik değeri al
    do
    {
        printf("Height: ");
        // Sayı girilmezse veya geçersizse girdiyi temizle
        if (scanf("%i", &height) != 1)
        {
            while (getchar() != '\n'); 
            height = 0; // Döngünün tekrar etmesi için geçersiz bir değer ata
        }
    }
    while (height < 1 || height > 8);

    // Satırları dön (1'den başlayarak height'a kadar)
    for (int row = 1; row <= height; row++)
    {
        // 1. ADIM: Boşlukları yazdır (Yükseklik - mevcut satır sayısı kadar)
        for (int spaces = 0; spaces < height - row; spaces++)
        {
            printf(" ");
        }

        // 2. ADIM: Kareleri (#) yazdır (Mevcut satır sayısı kadar)
        for (int hashes = 0; hashes < row; hashes++)
        {
            printf("#");
        }

        // Her satır bittiğinde bir alt satıra geç
        printf("\n");
    }

    return 0;
}