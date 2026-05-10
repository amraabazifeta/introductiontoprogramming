# Speller 📖

Implement a lightning-fast dictionary spell-checker using a hash table in C.

## Background

`speller.c` (provided — do not edit) reads a text file word by word and calls your functions to check each one. Your job is to implement the hash table in `dictionary.c`.

## Usage
```bash
make speller

# Use the small dictionary (words you added above)
./speller dictionaries/small texts/cat.txt

# Full CS50 dictionary (download from CS50 or use in codespace)
./speller dictionaries/large texts/cat.txt

# Benchmark output looks like:
# WORDS MISSPELLED:     0
# WORDS IN DICTIONARY:  143091
# WORDS IN TEXT:        6
# TIME IN load:         0.04
# TIME IN check:        0.00
# TIME IN size:         0.00
# TIME IN unload:       0.02
# TIME IN TOTAL:        0.06
```

## Your Five Functions (all in `dictionary.c`)

### 1. `hash(word)` — map word → bucket index
```c
// Simple: first letter (works for N=26)
return tolower(word[0]) - 'a';

// Better: djb2 (faster for large N like 10007)
unsigned long h = 5381;
for (int i = 0; word[i]; i++)
    h = ((h << 5) + h) + tolower(word[i]);
return h % N;
```

### 2. `load(dictionary)` — read file → fill hash table
```
open file → for each word → malloc node → strcpy → hash → prepend → count
```

### 3. `check(word)` — is this word in the dictionary?
```
hash word → walk that bucket → strcasecmp each node → return true/false
```

### 4. `size()` — how many words loaded?
```
return global word counter (incremented in load)
```

### 5. `unload()` — free all memory
```
for each bucket → while node != NULL → save next → free → advance
```

## Tuning for Speed

Change `#define N` at the top of `dictionary.c`:

| N | Collisions | Speed |
|---|---|---|
| 26 | High | Slow |
| 1000 | Medium | OK |
| 10007 (prime) | Low | Fast |
| 65537 (prime) | Very low | Very fast |

## Memory Check
```bash
valgrind --leak-check=full ./speller dictionaries/small texts/cat.txt
# Goal: "All heap blocks were freed -- no leaks are possible"
```

## Common Mistakes
| Bug | Symptom | Fix |
|---|---|---|
| `strcmp` instead of `strcasecmp` | "The" flagged as misspelled | Use `strcasecmp` in `check()` |
| Not null-terminating words | Garbage output | `fscanf` with `%45s` handles this |
| Freeing node before saving next | Segfault in `unload()` | `node *next = tmp->next; free(tmp); tmp = next;` |
| Hash returning negative | Array out of bounds | Use `unsigned int` or `abs()` |
| Not closing file in `load()` | Resource leak | `fclose(file)` before `return true` |
| `size()` returning 0 | Wrong word count | Make sure counter is global and incremented in `load()` |

## Check with CS50
```bash
check50 cs50/problems/2024/x/speller
style50 dictionary.c
submit50 cs50/problems/2024/x/speller
```
