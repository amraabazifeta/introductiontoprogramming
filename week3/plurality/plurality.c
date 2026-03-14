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

// Maximum number of candidates allowed
#define MAX 9

// ── Data structure ────────────────────────────────────────────────────────────
// Each candidate has a name and a vote count.
typedef struct
{
    string name;
    int    votes;
} candidate;

// Global array of candidates and the count of candidates
candidate candidates[MAX];
int candidate_count;

// ── Function prototypes ───────────────────────────────────────────────────────
// Do NOT change these signatures — check50 depends on them.
bool vote(string name);
void print_winner(void);

// ── main() — provided, do not modify ─────────────────────────────────────────
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
//
// Given a candidate name as input, search candidates[] for a matching entry.
//   • If found  → increment that candidate's votes and return true.
//   • If not found → return false.
//
// ⚠️  Use strcasecmp(a, b) == 0  to compare strings (case-insensitive).
//     Do NOT use  a == b  — that compares memory addresses, not content!
//
// strcasecmp is declared in <string.h>, which is already included above.
//
// Example:
//   candidates[0].name = "Alice"  candidates[0].votes = 2
//   vote("alice")  → candidates[0].votes becomes 3, returns true
//   vote("Dave")   → returns false (Dave is not a candidate)
// ─────────────────────────────────────────────────────────────────────────────
bool vote(string name)
{
    // TODO: Loop through candidates[] (0 to candidate_count - 1)
    //       If strcasecmp(candidates[i].name, name) == 0:
    //           candidates[i].votes++;
    //           return true;

    // If we reach here, no candidate matched
    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO: Implement print_winner()
// ─────────────────────────────────────────────────────────────────────────────
//
// Print the name(s) of the winner(s) — one name per line.
// If two or more candidates share the highest vote count, print all of them.
//
// Steps:
//   1. Find the maximum vote count across all candidates.
//   2. Print each candidate whose vote count equals the maximum.
//
// Example (no tie):
//   Alice: 3 votes, Bob: 1 vote, Charlie: 1 vote
//   → prints "Alice\n"
//
// Example (tie):
//   Alice: 2 votes, Bob: 2 votes, Charlie: 1 vote
//   → prints "Alice\nBob\n"
// ─────────────────────────────────────────────────────────────────────────────
void print_winner(void)
{
    // Step 1 — find the maximum vote count
    int max = 0;
    // TODO: Loop through candidates[]; if candidates[i].votes > max, update max

    // Step 2 — print every candidate who achieved max votes
    // TODO: Loop through candidates[]; if candidates[i].votes == max, printf their name
}
