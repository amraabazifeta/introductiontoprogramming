#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Her harfin (A-Z) puan değeri (0. indeks = A, 25. indeks = Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Fonksiyon prototipi
int compute_score(char word[]);

int main(void)
{
    // Kelimeleri saklamak için karakter dizileri (max 50 karakter)
    char word1[50];
    char word2[50];

    // Oyunculardan kelimeleri al
    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    // Skorları hesapla
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Kazananı belirle ve yazdır
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// Kelimenin Scrabble puanını hesaplayan fonksiyon
int compute_score(char word[])
{
    int score = 0;

    // Kelimenin her bir karakterini dön
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Karakterin harf olup olmadığını kontrol et
        if (isalpha(word[i]))
        {
            // Harfi büyük harfe çevirerek indeks hesaplamayı kolaylaştır
            char upper_char = toupper(word[i]);
            
            // ASCII mantığı ile indeksi bul: 'A' - 'A' = 0, 'B' - 'A' = 1...
            int index = upper_char - 'A';
            
            // Puanı ekle
            score += POINTS[index];
        }
    }

    return score;
}