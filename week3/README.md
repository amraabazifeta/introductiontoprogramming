# CS50x — Week 3: Algorithms 🗳️

> **Template repository.** Click **"Use this template"** → **"Create a new repository"** to get your own copy.

---

## 👋 Welcome to Week 3

This week covers **searching**, **sorting**, and **voting algorithms**. You'll implement election systems that range from the simple (one vote per person) to the complex (ranked-choice with cycle detection).

| # | Exercise | Difficulty | Status |
|---|----------|-----------|--------|
| 1 | [Plurality](#1-plurality) | ⭐ Beginner | **Required** |
| 2 | [Runoff](#2-runoff) | ⭐⭐ Intermediate | Pick one |
| 3 | [Tideman](#3-tideman) | ⭐⭐⭐ Hard | Pick one ↑ |

> **Note:** Submit both Runoff and Tideman if you want — CS50 records the higher score. Tideman is genuinely hard, so don't be discouraged!

---

## ⚙️ Setup

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME
cd YOUR_REPO_NAME
```

### Compile & Run

```bash
# Plurality
make pset3/plurality/plurality
./pset3/plurality/plurality Alice Bob Charlie

# Runoff
make pset3/runoff/runoff
./pset3/runoff/runoff Alice Bob Charlie

# Tideman
make pset3/tideman/tideman
./pset3/tideman/tideman Alice Bob Charlie
```

Or build everything at once:
```bash
make all
```

### Check Your Work
```bash
check50 cs50/problems/2024/x/plurality
check50 cs50/problems/2024/x/runoff
check50 cs50/problems/2024/x/tideman
```

### Style Check
```bash
style50 pset3/plurality/plurality.c
style50 pset3/runoff/runoff.c
style50 pset3/tideman/tideman.c
```

---

## 🧠 New C Concepts This Week

| Concept | Description | Example |
|---------|------------|---------|
| `struct` | Bundle related fields into one type | `candidate.name`, `candidate.votes` |
| `typedef struct` | Give a struct a clean name | `typedef struct { ... } candidate;` |
| `strcasecmp(a, b)` | Compare strings, ignoring case | Returns `0` if equal |
| 2D arrays | Grid of values | `int preferences[MAX_VOTERS][MAX_CANDIDATES]` |
| `bool` | True/false type | `#include <stdbool.h>` |
| Recursion | Function calls itself | Needed for cycle detection in Tideman |

---

## 📝 Exercises

---

### 1. Plurality

**File:** `pset3/plurality/plurality.c`

First-past-the-post voting. Each voter casts one vote for one candidate. The candidate with the most votes wins. Ties are possible — print all tied winners.

**Sample run:**
```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Alice
Vote: Alice
Alice
```

**Tie example:**
```
$ ./plurality Alice Bob
Number of voters: 2
Vote: Alice
Vote: Bob
Alice
Bob
```

**You must implement:**
- `bool vote(string name)` — find the candidate by name, increment their votes, return `true`; return `false` if not found
- `void print_winner(void)` — print name(s) of candidate(s) with the highest vote count

**Requirements:**
- Use `strcasecmp()` for case-insensitive name matching (not `==`)
- If the vote is invalid, the `main()` code prints `"Invalid vote."` — your `vote()` just needs to return `false`
- In a tie, print every tied candidate on separate lines

---

### 2. Runoff (Instant Runoff Voting)

**File:** `pset3/runoff/runoff.c`

Voters rank all candidates in order. If no candidate gets >50% of first-choice votes, the lowest vote-getter is eliminated and their votes are redistributed. Repeat until someone wins or it's a tie.

**Sample run:**
```
$ ./runoff Alice Bob Charlie
Number of voters: 3

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

**You must implement these 6 functions:**

| Function | What it does |
|----------|-------------|
| `vote(voter, rank, name)` | Record `candidate_index` in `preferences[voter][rank]` |
| `tabulate()` | Count each voter's top non-eliminated preference |
| `print_winner()` | Print winner if >50% votes; return `true`, else `false` |
| `find_min()` | Return lowest vote count among non-eliminated candidates |
| `is_tie(min)` | Return `true` if ALL remaining candidates have `min` votes |
| `eliminate(min)` | Mark candidates with `min` votes as `eliminated = true` |

**Key data structures:**
```c
// preferences[i][j] = index of voter i's j-th ranked candidate
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Each candidate has a name, vote count, and eliminated status
typedef struct {
    string name;
    int    votes;
    bool   eliminated;
} candidate;
```

---

### 3. Tideman (Ranked Pairs)

**File:** `pset3/tideman/tideman.c`

The most rigorous system — guarantees the **Condorcet winner** (beats every other candidate in a head-to-head matchup) is elected, if one exists.

**Three phases:**

```
TALLY → SORT → LOCK → PRINT WINNER
```

1. **Tally** — for every voter's ranking, count how many prefer candidate A over B for all pairs
2. **Sort** — order all winning pairs from strongest victory to weakest
3. **Lock** — add edges to a graph (strongest first), skipping any that would create a cycle

The winner is the **source** of the locked graph — the one with no incoming edges.

**You must implement these 6 functions:**

| Function | Phase | What it does |
|----------|-------|-------------|
| `vote(rank, name, ranks[])` | Input | Store candidate index in `ranks[rank]` |
| `record_preferences(ranks[])` | Tally | Update `preferences[i][j]` from one voter |
| `add_pairs()` | Tally | Populate `pairs[]` with winning pairs |
| `sort_pairs()` | Sort | Sort `pairs[]` by strength descending |
| `lock_pairs()` | Lock | Lock pairs, skipping cycle-creating ones |
| `print_winner()` | Output | Print candidate with no incoming locked edges |

**Cycle detection:**
```c
// Returns true if locking winner→loser would create a cycle
bool creates_cycle(int start, int end) {
    if (start == end) return true;     // found a path back to start!
    for each k where locked[end][k]:
        if creates_cycle(start, k) → return true
    return false;
}
```

---

## 📁 Repository Structure

```
cs50-week3/
├── README.md
├── Makefile
├── pset3/
│   ├── plurality/
│   │   ├── plurality.c     ← implement vote() and print_winner()
│   │   └── README.md
│   ├── runoff/
│   │   ├── runoff.c        ← implement 6 functions
│   │   └── README.md
│   └── tideman/
│       ├── tideman.c       ← implement 6 functions + cycle detection
│       └── README.md
└── .github/
    ├── workflows/check.yml
    └── ISSUE_TEMPLATE/bug_report.md
```

---

## 📬 Submitting

```bash
git add pset3/plurality/plurality.c
git commit -m "complete plurality"
git push

submit50 cs50/problems/2024/x/plurality
submit50 cs50/problems/2024/x/runoff
# or
submit50 cs50/problems/2024/x/tideman
```

---

## 💡 Tips

- **String comparison:** Always use `strcasecmp(a, b) == 0`, never `a == b` for strings in C
- **Runoff tabulate():** Skip any candidate whose `eliminated == true`; take the voter's next preference instead
- **Runoff find_min():** Initialize to a large number like `voter_count`, then loop down
- **Tideman sort_pairs():** Any sort works — even bubble sort. The key is comparing `preferences[pairs[i].winner][pairs[i].loser]`
- **Tideman lock_pairs():** The hardest part is `creates_cycle()`. Think: "Is there already a path from `loser` to `winner`?"
- **Tideman print_winner():** The source has `locked[j][i] == false` for ALL `j`

---

## 📜 Academic Honesty

> *"Be reasonable. The essence of all work that you submit to this course must be your own."*
> — CS50 Academic Honesty Policy

Do not share your completed code publicly while the course is active.

---

<p align="center">Made with ❤️ for CS50x students · Week 3: Algorithms</p>
