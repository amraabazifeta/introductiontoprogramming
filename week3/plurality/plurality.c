// plurality.c
// CS50x — Week 3, Problem Set 3
//
// Exercise: Plurality Vote
// ─────────────────────────
// Simulate a first-past-the-post election. Each voter casts exactly one
// vote. The candidate(s) with the most votes win. Ties are printed on
// separate lines.
//
// Usage:   ./plurality Alice Bob Charlie
// Check:   check50 cs50/problems/2024/x/plurality
// Style:   style50 plurality.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h> // strcasecmp için bazı sistemlerde gerekebilir

// Maximum number of candidates allowed
#define MAX 9

// Each candidate has a name and a vote count.
typedef struct
{
    string name;
    int    votes;
} candidate;

// Global array of candidates and the count of candidates
candidate candidates[MAX];
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Require at least one candidate name as a command-line argument
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate the array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name  = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Collect votes
    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Announce result
    print_winner();
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO: Implement vote()
// ─────────────────────────────────────────────────────────────────────────────
bool vote(string name)
{
    // TODO: Loop through candidates[] (0 to candidate_count - 1)
    for (int i = 0; i < candidate_count; i++)
    {
        // If strcasecmp(candidates[i].name, name) == 0:
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            // Increment candidate's votes and return true
            candidates[i].votes++;
            return true;
        }
    }

    // If we reach here, no candidate matched
    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO: Implement print_winner()
// ─────────────────────────────────────────────────────────────────────────────
void print_winner(void)
{
    // Step 1 — find the maximum vote count
    int max = 0;
    // TODO: Loop through candidates[]; if candidates[i].votes > max, update max
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }

    // Step 2 — print every candidate who achieved max votes
    // TODO: Loop through candidates[]; if candidates[i].votes == max, printf their name
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}