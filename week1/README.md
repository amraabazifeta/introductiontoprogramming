# Exercise 4 — Cash (Greedy Change)

## Goal
Find the minimum number of coins to make change for a given amount.

## Key Concepts
- Functions with parameters and return values
- Integer division (`/`) and modulo (`%`)
- Greedy algorithms — always pick the largest coin that fits

## The Greedy Idea

**Example: 41 cents**

| Step | Coin | Fits? | Remaining |
|------|------|-------|-----------|
| 1 | Quarter (25¢) | ✅ 1x | 16¢ |
| 2 | Dime (10¢) | ✅ 1x | 6¢ |
| 3 | Nickel (5¢) | ✅ 1x | 1¢ |
| 4 | Penny (1¢) | ✅ 1x | 0¢ |

**Total: 4 coins** ✓

## Function Signatures
Each `calculate_*` function receives the **remaining** cents and returns how many of that coin fit:

```c
int calculate_quarters(int cents); // returns cents / 25
int calculate_dimes(int cents);    // returns cents / 10
int calculate_nickels(int cents);  // returns cents / 5
int calculate_pennies(int cents);  // returns cents / 1
```

## Expected Behavior
```
$ ./cash
Change owed: -5
Change owed: 41
4

$ ./cash
Change owed: 100
4
```

## Check
```bash
check50 cs50/problems/2024/x/cash
style50 cash.c
```
