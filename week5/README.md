# CS50x Week 5 — Data Structures 🔗

> **Topic:** Linked Lists · Hash Tables · Tries · Stacks & Queues · Dynamic Memory

---

## 📋 Exercises Overview

| Exercise | Type | Difficulty | Topic |
|---|---|---|---|
| [Inheritance](lab5/inheritance/) | Lab | ⭐⭐⭐ | Structs, recursion, malloc/free, linked family trees |
| [Speller](pset5/speller/) | PSet — Required | ⭐⭐⭐⭐ | Hash tables, linked lists, file I/O, spell-checking |

---

## 🧠 Core Concepts This Week

### Linked Lists
```c
typedef struct node
{
    int number;
    struct node *next;   // pointer to next node
}
node;

// Build a list: prepend a new node
node *n = malloc(sizeof(node));
n->number = 1;
n->next = list;   // point to old head
list = n;         // new head
```

### Hash Tables
```c
// Array of N linked-list "buckets"
node *table[N];

// Insert: hash word → index → prepend to that bucket's list
int index = hash(word);
node *n = malloc(sizeof(node));
strcpy(n->word, word);
n->next = table[index];
table[index] = n;

// Lookup: hash word → walk the bucket's linked list
for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    if (strcasecmp(tmp->word, word) == 0) return true;
```

### Memory — The Golden Rules
```c
// Every malloc needs a matching free
node *n = malloc(sizeof(node));
// ... use n ...
free(n);

// Check malloc didn't return NULL
if (n == NULL) return false;

// Free a linked list: save next BEFORE freeing current node
node *tmp = head;
while (tmp != NULL)
{
    node *next = tmp->next;   // save next
    free(tmp);                // free current
    tmp = next;               // advance
}
```

### Structs with Self-Reference (Inheritance Lab)
```c
typedef struct person
{
    struct person *parents[2];   // pointers to parents
    char alleles[2];             // blood type alleles: 'A', 'B', or 'O'
}
person;
```

---

## 🗂️ Repository Structure

```
cs50-week5-template/
├── README.md
├── Makefile
├── .gitignore
├── lab5/
│   └── inheritance/
│       └── inheritance.c        ← ✏️ YOUR CODE (create_family, free_family)
└── pset5/
    └── speller/
        ├── dictionary.h         ← DO NOT EDIT — prototypes
        ├── dictionary.c         ← ✏️ YOUR CODE (load, hash, check, size, unload)
        ├── speller.c            ← DO NOT EDIT — main()
        └── dictionaries/
            └── small            ← small test dictionary (provided)
```

---

## 🚀 Quick Start

```bash
# Compile
make -C lab5/inheritance inheritance
make -C pset5/speller speller

# Run Inheritance
cd lab5/inheritance
./inheritance

# Run Speller
cd pset5/speller
./speller dictionaries/small texts/cat.txt
./speller dictionaries/large texts/shakespeare.txt
```

---

## 💡 Key Hints

### Inheritance — create_family
> Use recursion! If `generations > 1`, create parents first by calling `create_family(generations - 1)`. Then randomly inherit one allele from each parent. If `generations == 1`, randomly assign alleles (no parents).

### Inheritance — free_family
> Recursively free parents before freeing the current person. Mirror the structure of `create_family`.

### Speller — hash()
> Your hash function determines speed. A simple approach: sum ASCII values of each character, modulo `N`. A better approach: use djb2 or polynomial rolling hash. The larger your `N`, the fewer collisions.

### Speller — load()
> Open the dictionary file, read one word per line with `fscanf`, malloc a new node, copy the word, hash it, prepend to the correct bucket.

### Speller — check()
> Hash the input word, walk that bucket's linked list, compare with `strcasecmp` (case-insensitive!).

### Speller — size()
> Return a global counter that you increment in `load()`.

### Speller — unload()
> Loop over every bucket. For each, walk the linked list freeing every node. Use the `tmp = next; free(current)` pattern.

---

## ⚠️ Common Mistakes

| Mistake | Fix |
|---|---|
| `check()` is case-sensitive | Use `strcasecmp()`, not `strcmp()` |
| Not checking `malloc` return | Always `if (n == NULL) return false;` |
| Freeing node before saving `next` | `node *next = tmp->next; free(tmp); tmp = next;` |
| Hash function returns negative | Use `abs()` or ensure unsigned result |
| Forgetting to `fclose(file)` in `load` | Close the dictionary file at end of `load()` |
| Global word count not initialized | Declare `int word_count = 0;` at file scope |
| Inheritance: not setting `parents[i] = NULL` | For generation 1, both parents must be NULL |

---

## 📚 Resources
- [CS50 Week 5 Notes](https://cs50.harvard.edu/x/weeks/5/)
- [CS50 Shorts: Linked Lists](https://cs50.harvard.edu/x/shorts/linked_lists/)
- [CS50 Shorts: Hash Tables](https://cs50.harvard.edu/x/shorts/hash_tables/)
- [Valgrind memory leak checker](https://valgrind.org/) — `valgrind ./speller dictionaries/large texts/cat.txt`
- [CS50 Duck Debugger](https://cs50.ai/)

---

## 📤 Submitting

```bash
cd lab5/inheritance  && submit50 cs50/labs/2024/x/inheritance
cd pset5/speller     && submit50 cs50/problems/2024/x/speller
```
