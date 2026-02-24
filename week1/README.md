# Exercise 2 & 3 — Mario

## Goal
Print a text pyramid (or double pyramid) of `#` symbols.

## Key Concepts
- `do-while` loops for input validation
- Nested `for` loops
- Integer division and modulo

## Hint: Think in rows and columns

For a pyramid of height **4**, row-by-row:

| Row | Spaces | Hashes |
|-----|--------|--------|
| 1   | 3      | 1      |
| 2   | 2      | 2      |
| 3   | 1      | 3      |
| 4   | 0      | 4      |

Notice: `spaces = height - row`, `hashes = row`

## Expected Behavior
```
$ ./mario
Height: 0
Height: 9
Height: 4
   #
  ##
 ###
####
```

## Double pyramid (more comfortable)
```
$ ./mario_more
Height: 3
  #  #
 ##  ##
###  ###
```

## Check
```bash
check50 cs50/problems/2024/x/mario/less
check50 cs50/problems/2024/x/mario/more
```
