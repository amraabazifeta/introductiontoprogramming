#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Maksimum aday sayısı
#define MAX 9

// --- Veri Yapısı ---
// Adayların ismini ve oy sayısını bir arada tutan bir "paket" (struct)
typedef struct
{
    char *name;
    int votes;
} candidate;

// Global değişkenler
candidate candidates[MAX];
int candidate_count;

// Fonksiyon prototipleri
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Komut satırı argüman kontrolü (En az 1 aday olmalı)
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Aday sayısını belirle
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Adaylar dizisini doldur
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    // get_int yerine standart scanf kullanıyoruz
    if (scanf("%d", &voter_count) != 1) return 1;

    // Oyları topla
    for (int i = 0; i < voter_count; i++)
    {
        char name[50];
        printf("Vote: ");
        scanf("%s", name);

        // Geçersiz bir isim girilirse uyarı ver
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Kazananı duyur
    print_winner();
    
    return 0;
}

// Oy verme işlemi: İsmi adaylar listesinde ara ve oyunu 1 artır
bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // strcasecmp: Büyük/küçük harf duyarsız kıyaslama yapar (Alice == alice)
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Kazananı veya kazananları yazdır
void print_winner(void)
{
    // 1. Adım: En yüksek oy sayısını bul
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // 2. Adım: Bu oy sayısına sahip olan herkesi yazdır (Beraberlik durumu dahil)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}