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
<<<<<<< HEAD
#include <strings.h>
=======
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

// ── Limits ────────────────────────────────────────────────────────────────────
#define MAX 9

// ── Data ──────────────────────────────────────────────────────────────────────
<<<<<<< HEAD
int preferences[MAX][MAX];
bool locked[MAX][MAX];

=======

// preferences[i][j] = number of voters who prefer candidate i over candidate j
int preferences[MAX][MAX];

// locked[i][j] = true means there is a locked edge FROM i TO j in the graph
bool locked[MAX][MAX];

// A "pair" records which candidate won and which lost a head-to-head matchup
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
typedef struct
{
    int winner;
    int loser;
} pair;

<<<<<<< HEAD
string candidates[MAX];
pair   pairs[MAX * (MAX - 1) / 2];
=======
// Candidate names and the pairs array
string candidates[MAX];
pair   pairs[MAX * (MAX - 1) / 2]; // maximum possible pairs
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

int pair_count;
int candidate_count;

<<<<<<< HEAD
// ── Function prototypes ───────────────────────────────────────────────────────
=======
// ── Function prototypes — do NOT change these signatures ──────────────────────
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
<<<<<<< HEAD
bool creates_cycle(int start, int end);

=======

// ── main() — provided, do not modify ─────────────────────────────────────────
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
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

<<<<<<< HEAD
=======
    // Initialise arrays to zero / false
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
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

<<<<<<< HEAD
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];
=======
    // Collect rankings and build preference matrix
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count]; // ranks[j] = index of j-th preference

>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
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

<<<<<<< HEAD
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
=======
// ─────────────────────────────────────────────────────────────────────────────
// TODO 1: vote(rank, name, ranks[])
// ─────────────────────────────────────────────────────────────────────────────
//
// This voter is ranking candidate `name` at position `rank`.
// Find the index of `name` in candidates[], store it in ranks[rank],
// and return true. If no candidate matches, return false.
//
// Example:
//   candidates = ["Alice", "Bob", "Charlie"]
//   vote(0, "Bob", ranks)    → ranks[0] = 1,  return true
//   vote(1, "Alice", ranks)  → ranks[1] = 0,  return true
//   vote(2, "Dave", ranks)   → return false
// ─────────────────────────────────────────────────────────────────────────────
bool vote(int rank, string name, int ranks[])
{
    // TODO: loop i from 0 to candidate_count
    //         if strcasecmp(candidates[i], name) == 0:
    //             ranks[rank] = i;
    //             return true;

    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO 2: record_preferences(ranks[])
// ─────────────────────────────────────────────────────────────────────────────
//
// Given one voter's complete ranking (ranks[0] = most preferred, etc.),
// update the global preferences[][] matrix.
//
// For every pair where one candidate is ranked higher than another,
// the voter prefers the higher-ranked one:
//   preferences[ranks[i]][ranks[j]]++   for all i < j
//
// Why? ranks[i] appears at position i (earlier = more preferred).
//      ranks[j] appears at position j.
//      If i < j, this voter prefers ranks[i] over ranks[j].
//
// Example (3 candidates, ranked Bob=1st, Charlie=2nd, Alice=3rd):
//   ranks = [1, 2, 0]   (Bob=index1, Charlie=index2, Alice=index0)
//
//   i=0, j=1: voter prefers ranks[0]=Bob   over ranks[1]=Charlie → preferences[1][2]++
//   i=0, j=2: voter prefers ranks[0]=Bob   over ranks[2]=Alice   → preferences[1][0]++
//   i=1, j=2: voter prefers ranks[1]=Charlie over ranks[2]=Alice → preferences[2][0]++
// ─────────────────────────────────────────────────────────────────────────────
void record_preferences(int ranks[])
{
    // TODO: nested loop
    //   for i from 0 to candidate_count - 1:
    //     for j from i + 1 to candidate_count - 1:
    //       preferences[ranks[i]][ranks[j]]++;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO 3: add_pairs()
// ─────────────────────────────────────────────────────────────────────────────
//
// For each pair of candidates (i, j) where i < j, determine if one beats
// the other. If preferences[i][j] > preferences[j][i], candidate i beats j.
// If preferences[j][i] > preferences[i][j], candidate j beats i.
// If tied (equal preferences), do NOT add this pair.
//
// For each non-tied pair, add a pair struct to pairs[] and increment pair_count.
//
// Example (3 candidates):
//   preferences[0][1] = 5, preferences[1][0] = 2  → Alice beats Bob  → pairs[0] = {winner:0, loser:1}
//   preferences[0][2] = 4, preferences[2][0] = 3  → Alice beats Charlie → pairs[1] = {winner:0, loser:2}
//   preferences[1][2] = 1, preferences[2][1] = 6  → Charlie beats Bob   → pairs[2] = {winner:2, loser:1}
// ─────────────────────────────────────────────────────────────────────────────
void add_pairs(void)
{
    // TODO: for i from 0 to candidate_count - 1:
    //         for j from i + 1 to candidate_count - 1:
    //           if preferences[i][j] > preferences[j][i]:
    //               pairs[pair_count].winner = i;
    //               pairs[pair_count].loser  = j;
    //               pair_count++;
    //           else if preferences[j][i] > preferences[i][j]:
    //               pairs[pair_count].winner = j;
    //               pairs[pair_count].loser  = i;
    //               pair_count++;
    //           // ties: skip (don't add)
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO 4: sort_pairs()
// ─────────────────────────────────────────────────────────────────────────────
//
// Sort pairs[] in DECREASING order of "strength of victory".
// Strength = preferences[pairs[k].winner][pairs[k].loser]
// (The number of voters who preferred the winner over the loser.)
//
// The strongest pair is processed first in lock_pairs().
//
// Hint: Any sort algorithm works. Bubble sort is fine for this problem size.
//
// Bubble sort pattern:
//   for i from 0 to pair_count - 2:
//     for j from 0 to pair_count - i - 2:
//       if strength(pairs[j]) < strength(pairs[j+1]):
//           swap pairs[j] and pairs[j+1]
// ─────────────────────────────────────────────────────────────────────────────
void sort_pairs(void)
{
    // TODO: sort pairs[] by preferences[winner][loser] descending
    //
    // To swap two pairs, use a temporary pair:
    //   pair tmp   = pairs[j];
    //   pairs[j]   = pairs[j + 1];
    //   pairs[j+1] = tmp;
}

// ── Cycle-detection helper ────────────────────────────────────────────────────
//
// creates_cycle(start, end):
//   Returns true if there is ALREADY a path from `end` back to `start`
//   through the currently locked edges. If there is, then locking an edge
//   from `start` to `end` would create a cycle.
//
// Algorithm (recursive DFS):
//   Base case: if start == end, we've found a path back — return true.
//   Recursive: for each candidate k, if locked[end][k] is true,
//              check whether creates_cycle(start, k) is true.
//              If so, return true.
//   Default:   return false (no cycle found from this path).
//
// Example:
//   Locked edges: A→B, B→C  (no cycle yet)
//   Try to lock C→A:
//     creates_cycle(C, A)?  Is there a path from A back to C?
//     locked[A][B] = true → creates_cycle(C, B)?
//       locked[B][C] = true → creates_cycle(C, C)?
//         start == end (C == C) → return TRUE  ← cycle detected!
//   So we do NOT lock C→A.
// ─────────────────────────────────────────────────────────────────────────────
bool creates_cycle(int start, int end)
{
    // Base case: path leads back to start — cycle!
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
    if (start == end)
    {
        return true;
    }

<<<<<<< HEAD
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
=======
    // TODO: for k from 0 to candidate_count - 1:
    //         if locked[end][k]:
    //             if creates_cycle(start, k):
    //                 return true;

    return false;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO 5: lock_pairs()
// ─────────────────────────────────────────────────────────────────────────────
//
// Iterate through pairs[] (already sorted strongest-first).
// For each pair, lock it (set locked[winner][loser] = true) ONLY IF
// doing so does NOT create a cycle in the graph.
//
// Use creates_cycle(pairs[i].winner, pairs[i].loser) to check.
// If creates_cycle returns false → safe to lock.
// If creates_cycle returns true  → skip this pair.
// ─────────────────────────────────────────────────────────────────────────────
void lock_pairs(void)
{
    // TODO: for i from 0 to pair_count - 1:
    //         if !creates_cycle(pairs[i].winner, pairs[i].loser):
    //             locked[pairs[i].winner][pairs[i].loser] = true;
}

// ─────────────────────────────────────────────────────────────────────────────
// TODO 6: print_winner()
// ─────────────────────────────────────────────────────────────────────────────
//
// The winner is the "source" of the locked graph:
// the candidate who has NO locked edge pointing TO them.
//
// In other words, for the winner i, there is no j such that locked[j][i] == true.
//
// How to find the source:
//   For each candidate i:
//     Set a flag `is_source = true`
//     For each candidate j:
//       If locked[j][i] == true:  ← someone locked an edge pointing TO i
//         is_source = false
//         break
//     If is_source is still true → print candidates[i] and return
// ─────────────────────────────────────────────────────────────────────────────
void print_winner(void)
{
    // TODO: for i from 0 to candidate_count - 1:
    //         bool is_source = true;
    //         for j from 0 to candidate_count - 1:
    //           if locked[j][i]:
    //             is_source = false;
    //             break;
    //         if is_source:
    //           printf("%s\n", candidates[i]);
    //           return;
}
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
