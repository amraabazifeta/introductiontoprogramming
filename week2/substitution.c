#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fonksiyon prototipleri
bool is_valid_key(char *key);

int main(int argc, char *argv[])
{
    // ADIM 1: Komut satırı argümanlarını doğrula
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    char *key = argv[1];

    // ADIM 2: Kullanıcıdan düz metni (plaintext) al
    char plaintext[1000];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // ADIM 3: Şifrele ve yazdır
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Harfin alfabedeki sırasını bul (A=0, B=1...)
            int index = plaintext[i] - 'A';
            // Anahtardaki karşılığını büyük harf olarak yazdır
            printf("%c", toupper(key[index]));
        }
        else if (islower(plaintext[i]))
        {
            // Harfin alfabedeki sırasını bul (a=0, b=1...)
            int index = plaintext[i] - 'a';
            // Anahtardaki karşılığını küçük harf olarak yazdır
            printf("%c", tolower(key[index]));
        }
        else
        {
            // Harf değilse (boşluk, nokta vb.) olduğu gibi yazdır
            printf("%c", plaintext[i]);
        }
    }

    // fgets bazen satır sonuna \n eklemezse diye garantiye alalım
    if (plaintext[strlen(plaintext) - 1] != '\n')
    {
        printf("\n");
    }

    return 0;
}

// Anahtarın geçerli olup olmadığını kontrol eden fonksiyon
bool is_valid_key(char *key)
{
    // 1. Uzunluk 26 olmalı
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        // 2. Sadece harf olmalı
        if (!isalpha(key[i]))
        {
            return false;
        }

        // 3. Her harf sadece bir kez kullanılmalı (tekrar kontrolü)
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}