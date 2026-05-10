// tideman.c
// CS50x — Week 3, Problem Set 3
//
// Exercise: Tideman (Ranked Pairs) ★★★ Advanced
// ───────────────────────────────────────────────
// Implements the Condorcet-consistent "ranked pairs" method.
// If a Condorcet winner exists (a candidate who beats every other candidate
// head-to-head), Tideman is guaranteed to elect them.
//
// The algorithm runs in three phases:
//   1. TALLY  — count pairwise preferences from all voters' rankings
//   2. SORT   — order winning pairs by strength of victory (descending)
//   3. LOCK   — add directed edges to a graph; skip any that create a cycle
//
// The winner = the "source" of the locked graph (no incoming edges).
//
// Usage:   ./tideman Alice Bob Charlie
// Check:   check50 cs50/problems/2024/x/tideman
// Style:   style50 tideman.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// ── Limits ────────────────────────────────────────────────────────────────────
#define MAX 9

// ── Data ──────────────────────────────────────────────────────────────────────
int preferences[MAX][MAX];
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

string candidates[MAX];
pair   pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// ── Function prototypes ───────────────────────────────────────────────────────
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int start, int end);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j]      = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// TODO 1: vote(rank, name, ranks[])
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// TODO 2: record_preferences(ranks[])
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// TODO 3: add_pairs()
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// TODO 4: sort_pairs() (Bubble Sort)
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strength_j = preferences[pairs[j].winner][pairs[j].loser];
            int strength_j1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if (strength_j < strength_j1)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

// Cycle-detection helper (Recursive DFS)
bool creates_cycle(int start, int end)
{
    if (start == end)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (creates_cycle(start, i))
            {
                return true;
            }
        }
    }
    return false;
}

// TODO 5: lock_pairs()
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// TODO 6: print_winner()
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_source = false;
                break;
            }
        }
        if (is_source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}