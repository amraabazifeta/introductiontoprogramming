# Exercise 1 — Plurality Vote

## Goal
Simulate a first-past-the-post election: the candidate(s) with the most votes win.

## Key Concepts
- `struct` — bundle a name and vote count together
- `strcasecmp()` from `<string.h>` — case-insensitive string comparison
- Command-line arguments (`argc`, `argv`)
- Finding the maximum value in an array

---

## The `candidate` Struct

```c
typedef struct
{
    string name;    // candidate's name (e.g., "Alice")
    int    votes;   // number of votes received
} candidate;
```

Access fields with dot notation:
```c
candidates[0].name   = "Alice";
candidates[0].votes += 1;
```

---

## String Comparison in C

Strings in C are **arrays of characters**, not primitive values.
You cannot compare them with `==`.

```c
// ❌ WRONG — compares memory addresses
if (candidates[i].name == name) ...

// ✅ CORRECT — compares character content, ignoring case
if (strcasecmp(candidates[i].name, name) == 0) ...
```

`strcasecmp` returns:
- `0`   → strings are equal (ignoring case)
- `< 0` → first string comes alphabetically before second
- `> 0` → first string comes alphabetically after second

---

## Worked Example — `vote()`

Candidates: Alice (0 votes), Bob (0 votes), Charlie (0 votes)

| Call | Match? | Effect |
|------|--------|--------|
| `vote("Alice")` | Alice found | `candidates[0].votes = 1`, return `true` |
| `vote("alice")` | Alice found (case-insensitive) | `candidates[0].votes = 2`, return `true` |
| `vote("Dave")`  | No match | return `false` |

---

## Worked Example — `print_winner()`

After voting: Alice = 3, Bob = 1, Charlie = 1

1. Find max: loop through all → `max = 3`
2. Print everyone with 3 votes → prints `Alice`

After voting (tie): Alice = 2, Bob = 2, Charlie = 1

1. Find max: `max = 2`
2. Print everyone with 2 votes → prints `Alice` then `Bob`

---

## Expected Terminal Output

```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Alice
Vote: Alice
Alice

$ ./plurality Alice Bob
Number of voters: 2
Vote: Alice
Vote: Bob
Alice
Bob

$ ./plurality Alice
Number of voters: 3
Vote: Alice
Vote: Eve
Invalid vote.
Vote: Alice
Alice
```

---

## How to Test

```bash
# Compile
make plurality

# Run manually
./plurality Alice Bob Charlie

# Automated check
check50 cs50/problems/2024/x/plurality

# Style check
style50 plurality.c
```
