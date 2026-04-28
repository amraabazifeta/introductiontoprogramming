#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fonksiyon prototipleri
bool only_digits(char *s);
char rotate(char c, int n);

int main(int argc, char *argv[])
{
    // ADIM 1: Komut satırı argümanlarını doğrula
    // Kullanım: ./caesar key (argc tam olarak 2 olmalı)
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // ADIM 2: Anahtarı (key) string'den int'e çevir
    int key = atoi(argv[1]);

    // ADIM 3: Kullanıcıdan düz metni (plaintext) al
    char plaintext[500];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // ADIM 4: Şifreli metni hesapla ve yazdır
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Her karakteri anahtar kadar döndür ve yazdır
        // Not: fgets satır sonundaki '\n' karakterini de alır, rotate bunu korur.
        printf("%c", rotate(plaintext[i], key));
    }

    // Eğer fgets ile gelen satır sonu karakteri yoksa yeni satır ekle
    if (plaintext[strlen(plaintext) - 1] != '\n')
    {
        printf("\n");
    }

    return 0;
}

// Argümanın sadece rakamlardan oluşup oluşmadığını kontrol eder
bool only_digits(char *s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Karakteri n pozisyon kadar ileri kaydırır
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Büyük harf: (Alfabetik sıra + anahtar) % 26 + 'A' başlangıcı
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // Küçük harf: (Alfabetik sıra + anahtar) % 26 + 'a' başlangıcı
        return (c - 'a' + n) % 26 + 'a';
    }
    
    // Harf değilse (boşluk, nokta vb.) olduğu gibi döndür
    return c;
}