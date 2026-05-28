// runoff.c
// CS50x — Week 3, Problem Set 3

#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

// ── Limits ────────────────────────────────────────────────────────────────────
#define MAX_VOTERS     100
#define MAX_CANDIDATES   9

// preferences[i][j] = index of voter i's j-th ranked candidate
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidate structure
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// ── main() — provided ─────────────────────────────────────────────────────────
int main(int argc, string argv[])
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

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Collect voter rankings
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Run runoff rounds
    while (true)
    {
        tabulate();

        if (print_winner())
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

        // Reset votes for next round
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
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

// ─────────────────────────────────────────────────────────────────────────────
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int c = preferences[i][j];
            if (!candidates[c].eliminated)
            {
                candidates[c].votes++;
                break;
            }
        }
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// Print winner if majority is found
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// Return minimum number of votes among remaining candidates
int find_min(void)
{
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// ─────────────────────────────────────────────────────────────────────────────
// Return true if all remaining candidates are tied
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// ─────────────────────────────────────────────────────────────────────────────
// Eliminate candidates with the minimum vote count
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
