# Exercise 3 — Tideman (Ranked Pairs) ⚠️ Hard

## Goal
Implement the Condorcet-consistent "ranked pairs" voting system. It guarantees the candidate who would beat everyone else head-to-head wins — if such a candidate exists.

## Key Concepts
- 2D arrays for pairwise preference counting
- Directed graph represented as a boolean `locked[][]` matrix
- Sorting by a custom criterion
- Recursive depth-first search for cycle detection

---

## The Three Phases at a Glance

```
ALL VOTERS RANK CANDIDATES
         ↓
   Phase 1: TALLY
   Count who prefers A over B for every pair
         ↓
   Phase 2: SORT
   Order pairs by strength of victory (strongest first)
         ↓
   Phase 3: LOCK
   Add each pair as a directed edge — skip any that create a cycle
         ↓
   PRINT WINNER
   The candidate with no incoming edges = the winner
```

---

## Phase 1: Tally — `record_preferences()`

After all voters rank candidates, you need `preferences[i][j]` = how many voters preferred `i` over `j`.

For **one voter** with ranking `ranks = [Bob, Charlie, Alice]` (indices `[1, 2, 0]`):
- They prefer Bob over Charlie → `preferences[1][2]++`
- They prefer Bob over Alice → `preferences[1][0]++`
- They prefer Charlie over Alice → `preferences[2][0]++`

The rule: for positions `i < j` in `ranks[]`, the voter prefers `ranks[i]` over `ranks[j]`.

```c
for (int i = 0; i < candidate_count; i++)
    for (int j = i + 1; j < candidate_count; j++)
        preferences[ranks[i]][ranks[j]]++;
```

---

## Phase 1b: Collecting Pairs — `add_pairs()`

After tallying all voters, find each winning pair:

| Check | Meaning | Action |
|-------|---------|--------|
| `preferences[i][j] > preferences[j][i]` | i beats j | Add pair `{winner:i, loser:j}` |
| `preferences[j][i] > preferences[i][j]` | j beats i | Add pair `{winner:j, loser:i}` |
| Equal | Tie | Skip |

---

## Phase 2: Sort — `sort_pairs()`

Sort `pairs[]` from strongest to weakest victory.
**Strength** = `preferences[winner][loser]`.

Example before sorting:
```
pairs[0]: Alice→Bob   strength=5
pairs[1]: Charlie→Bob strength=7
pairs[2]: Alice→Charlie strength=6
```

After sorting (descending):
```
pairs[0]: Charlie→Bob   strength=7
pairs[1]: Alice→Charlie strength=6
pairs[2]: Alice→Bob     strength=5
```

---

## Phase 3: Lock — `lock_pairs()` + Cycle Detection

Go through pairs strongest-first. Lock each one as a directed edge **unless** it would create a cycle.

### What's a cycle?

A cycle means you can start at candidate A, follow locked edges, and get back to A.

```
Locked: Alice→Bob, Bob→Charlie
Try to lock: Charlie→Alice

Path check: Is there a path from Alice back to Charlie?
  Alice→Bob   ✓  (locked[Alice][Bob])
  Bob→Charlie ✓  (locked[Bob][Charlie])
  → Alice can reach Charlie → locking Charlie→Alice creates a cycle ❌ SKIP
```

### `creates_cycle(start, end)` — Recursive DFS

```
creates_cycle(start=Alice, end=Charlie):
  start != end → keep going
  Check all k where locked[Charlie][k]:
    locked[Charlie][Bob]? → creates_cycle(Alice, Bob)?
      locked[Bob][Alice]? → creates_cycle(Alice, Alice)?
        start == end → return TRUE ← cycle!
```

The key insight: we're asking "is there already a path from `end` back to `start`?"

---

## Finding the Winner — `print_winner()`

The winner is the **source** of the locked graph — the only candidate with NO arrows pointing at them.

```
Locked edges (example):
  Alice → Bob
  Alice → Charlie
  Bob   → Charlie

Incoming edges:
  Alice:   none    ← SOURCE = WINNER
  Bob:     Alice
  Charlie: Alice, Bob
```

Check: for each candidate `i`, is there any `j` where `locked[j][i]`?  
If no: `i` is the source → winner.

---

## Function Checklist

| # | Function | Phase | Done? |
|---|----------|-------|-------|
| 1 | `vote()` | Input | ☐ |
| 2 | `record_preferences()` | Tally | ☐ |
| 3 | `add_pairs()` | Tally | ☐ |
| 4 | `sort_pairs()` | Sort | ☐ |
| 5 | `lock_pairs()` | Lock | ☐ |
| 6 | `print_winner()` | Output | ☐ |
| + | `creates_cycle()` | Lock helper | ☐ |

---

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| `record_preferences`: `i` and `j` both start at 0 | Inner loop must start at `i + 1` to avoid double-counting |
| `add_pairs`: skipping ties but still adding a pair | Only add when one side is strictly greater |
| `sort_pairs`: sorting ascending instead of descending | Check: if `strength[j] < strength[j+1]`, swap |
| `creates_cycle`: not handling base case | Always check `if (start == end) return true` first |
| `print_winner`: checking `locked[i][j]` instead of `locked[j][i]` | You want edges pointing **TO** i, which means `locked[j][i]` |

---

## Expected Terminal Output

```
$ ./tideman Alice Bob Charlie
Number of voters: 3

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Alice
```

---

## How to Test

```bash
make tideman
./tideman Alice Bob Charlie
check50 cs50/problems/2024/x/tideman
style50 tideman.c
```
