#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Sınırlar
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// --- Veri Yapısı ---
// preferences[i][j], i. seçmenin j. sıradaki tercihinin (adayın) indeksidir.
int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    char *name;
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

// Global sayılar
int voter_count;
int candidate_count;

// Fonksiyon prototipleri
bool vote(int voter, int rank, char *name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1) return 1;

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Her seçmenin sıralamasını al
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            char name[50];
            printf("Voter %i, Rank %i: ", i + 1, j + 1);
            scanf("%s", name);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Kazanan veya beraberlik çıkana kadar turları döndür
    while (true)
    {
        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        // Bir sonraki tur için oyları sıfırla
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// 1. ADIM: Oyu kaydet (İsmi bulup indeksini tercihlere yaz)
bool vote(int voter, int rank, char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// 2. ADIM: Oyları say (Her seçmenin elenmemiş en üst tercihine bak)
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_idx = preferences[i][j];
            if (!candidates[candidate_idx].eliminated)
            {
                candidates[candidate_idx].votes++;
                break; // Sadece elenmemiş EN ÜST tercihi say ve sonraki seçmene geç
            }
        }
    }
}

// 3. ADIM: Kazananı kontrol et (Yarıdan fazla oy alan var mı?)
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// 4. ADIM: En düşük oyu bul
int find_min(void)
{
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// 5. ADIM: Herkes mi eşit (beraberlik mi)?
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// 6. ADIM: En düşük oyu alanları ele
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}