# Exercise 2 — Runoff (Instant Runoff Voting)

## Goal
Simulate ranked-choice voting where the last-place candidate is eliminated each round until someone wins a majority.

## Key Concepts
- 2D arrays: `preferences[voter][rank]`
- `struct` with a `bool eliminated` field
- Multi-round loops
- Finding minimum values in an array

---

## How Runoff Works — Step by Step

**Setup:** 3 voters, 3 candidates (Alice, Bob, Charlie)

| Voter | Rank 1 | Rank 2 | Rank 3 |
|-------|--------|--------|--------|
| 0     | Alice  | Bob    | Charlie |
| 1     | Bob    | Alice  | Charlie |
| 2     | Charlie| Alice  | Bob    |

**Round 1:** Count first choices
- Alice: 1, Bob: 1, Charlie: 1 → no majority (need > 1.5)
- Minimum = 1 → everyone tied → **TIE declared** → print all three

In a less extreme example where someone gets ≥ 51%:

| Voter | Rank 1 | Rank 2 |
|-------|--------|--------|
| 0     | Alice  | Bob    |
| 1     | Alice  | Bob    |
| 2     | Bob    | Alice  |

Round 1: Alice=2, Bob=1. Alice has 2 > 1.5 → **Alice wins!**

---

## The `preferences` 2D Array

```c
preferences[voter][rank] = index of that candidate in candidates[]
```

**Example:** Alice=0, Bob=1, Charlie=2

```
Voter 0 ranks: Alice(1st), Bob(2nd), Charlie(3rd)
→ preferences[0][0] = 0   (Alice)
→ preferences[0][1] = 1   (Bob)
→ preferences[0][2] = 2   (Charlie)
```

---

## Function Guide

### `vote(voter, rank, name)`
Find the candidate matching `name` and store their index:
```c
preferences[voter][rank] = i;  // i = index of matching candidate
```

### `tabulate()`
For each voter, find their **top non-eliminated** choice:
```c
for each voter:
    for each rank j:
        c = preferences[voter][j]
        if NOT candidates[c].eliminated:
            candidates[c].votes++
            break   // ← only count ONCE per voter
```

### `print_winner()`
Does anyone have more than half the votes?
```c
if candidates[i].votes > voter_count / 2 → winner!
```

### `find_min()`
What's the fewest votes any remaining candidate has?
```c
min = large_number
for each non-eliminated candidate:
    if votes < min → min = votes
return min
```

### `is_tie(min)`
Is everyone tied (all have exactly `min` votes)?
```c
for each non-eliminated candidate:
    if votes != min → return false
return true
```

### `eliminate(min)`
Mark losers:
```c
for each non-eliminated candidate:
    if votes == min → eliminated = true
```

---

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| Checking eliminated candidates in `tabulate()` | Add `if (!candidates[c].eliminated)` check |
| Not breaking after counting a vote in `tabulate()` | Add `break` after incrementing votes |
| `is_tie()` always returns `true` | Only return `true` after the loop confirms ALL non-eliminated have `min` votes |
| Not resetting votes between rounds | `main()` already does this — you don't need to in your functions |

---

## Expected Terminal Output

```
$ ./runoff Alice Bob Charlie
Number of voters: 5

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

---

## How to Test

```bash
make runoff
./runoff Alice Bob Charlie
check50 cs50/problems/2024/x/runoff
style50 runoff.c
```
