// CS50x Week 5 — Speller: dictionary.c
// ✏️  YOUR CODE GOES HERE
//
// Implement a dictionary spell-checker using a hash table.
// You must implement five functions:
//   load()   — read dictionary file into hash table
//   hash()   — map a word to a bucket index
//   check()  — return true if word is in dictionary
//   size()   — return total number of words loaded
//   unload() — free all memory used by the hash table

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>   // for strcasecmp

#include "dictionary.h"

// ---------------------------------------------------------------------------
// HASH TABLE CONFIGURATION
// ---------------------------------------------------------------------------
// N is the number of buckets in your hash table.
// A larger N means fewer collisions and faster lookups — but more memory.
// The CS50 large dictionary has ~143,000 words.
// Recommended: start with 26 (one per letter) or go big with 1000–10000.
//
// Try: N = 26, N = 1000, N = 10007 (prime numbers reduce collisions)
// ---------------------------------------------------------------------------
#define N 26

// ---------------------------------------------------------------------------
// NODE — one entry in the hash table's linked list
// ---------------------------------------------------------------------------
typedef struct node
{
    char word[LENGTH + 1];   // the dictionary word (+ null terminator)
    struct node *next;       // pointer to next node in bucket
} node;

// ---------------------------------------------------------------------------
// GLOBALS
// ---------------------------------------------------------------------------
// The hash table: an array of N bucket heads (all start as NULL)
node *table[N];

// TODO: declare a global word counter (initialize to 0)
// This will be incremented in load() and returned by size().
// Example: unsigned int word_count = 0;

// ---------------------------------------------------------------------------
// TODO 1: hash()
// ---------------------------------------------------------------------------
// Map a word to a bucket index in range [0, N-1].
//
// The simplest correct hash: use the first letter.
//   return tolower(word[0]) - 'a';   // gives 0–25 for N=26
//
// A better hash (djb2 — produces better distribution for large N):
//   unsigned long hash_val = 5381;
//   for (int i = 0; word[i] != '\0'; i++)
//       hash_val = ((hash_val << 5) + hash_val) + tolower(word[i]);
//   return hash_val % N;
//
// RULES:
//   - Must return a value in [0, N-1]
//   - Must be case-insensitive (same hash for "Apple" and "apple")
//   - Must never return a negative number
//
// HINT: If using djb2, hash_val is unsigned long — no negatives possible.
// HINT: If using a simple sum, use unsigned int to avoid sign issues.
// ---------------------------------------------------------------------------
unsigned int hash(const char *word)
{
    // TODO: implement your hash function
    // Simple starter (works for N=26):
    return tolower(word[0]) - 'a';
}

// ---------------------------------------------------------------------------
// TODO 2: load()
// ---------------------------------------------------------------------------
// Load the dictionary file into the hash table.
//
// Algorithm:
//   1. Open the dictionary file with fopen(dictionary, "r")
//   2. Check it opened successfully (not NULL)
//   3. Read one word at a time using fscanf(file, "%45s", word)
//      - fscanf returns EOF when done
//   4. For each word:
//      a. malloc a new node
//      b. Check malloc didn't return NULL
//      c. Copy the word into the node: strcpy(n->word, word)
//      d. Hash the word to get the bucket index
//      e. Prepend the node to that bucket's linked list:
//           n->next = table[index];
//           table[index] = n;
//      f. Increment your word counter
//   5. Close the file with fclose()
//   6. Return true
//
// HINT: Declare a char word[LENGTH + 1] buffer for reading.
// HINT: Prepending (not appending) to a linked list is O(1) and simpler.
// HINT: Don't forget to fclose() before returning!
// ---------------------------------------------------------------------------
bool load(const char *dictionary)
{
    // TODO 2a: open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // TODO 2b: read words one by one until EOF
    char word[LENGTH + 1];
    while (fscanf(file, "%45s", word) != EOF)
    {
        // TODO 2c: malloc a new node for this word

        // TODO 2d: copy word into node with strcpy

        // TODO 2e: hash the word to find its bucket

        // TODO 2f: prepend node to bucket's linked list

        // TODO 2g: increment your global word counter
    }

    // TODO 2h: close the file and return true
    fclose(file);
    return true;
}

// ---------------------------------------------------------------------------
// TODO 3: check()
// ---------------------------------------------------------------------------
// Return true if word is in the dictionary (case-insensitive), false otherwise.
//
// Algorithm:
//   1. Hash the word to find the bucket index
//   2. Walk that bucket's linked list:
//      for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
//   3. For each node, compare using strcasecmp(tmp->word, word)
//      - strcasecmp returns 0 if strings are equal (ignoring case)
//   4. If a match is found, return true
//   5. If the loop ends with no match, return false
//
// IMPORTANT: Use strcasecmp, NOT strcmp — checking is case-insensitive!
// HINT: "The" and "the" and "THE" should all match dictionary entry "the".
// ---------------------------------------------------------------------------
bool check(const char *word)
{
    // TODO 3a: hash the word to find its bucket

    // TODO 3b: walk the linked list in that bucket

    // TODO 3c: return true if match found, false otherwise
    return false;
}

// ---------------------------------------------------------------------------
// TODO 4: size()
// ---------------------------------------------------------------------------
// Return the number of words in the dictionary.
//
// This is simply: return your global word counter.
// The counter should have been incremented once per word in load().
// ---------------------------------------------------------------------------
unsigned int size(void)
{
    // TODO: return your global word count variable
    return 0;
}

// ---------------------------------------------------------------------------
// TODO 5: unload()
// ---------------------------------------------------------------------------
// Free ALL memory allocated by load().
//
// Algorithm:
//   For each bucket i in [0, N-1]:
//     Walk the linked list and free every node:
//       node *tmp = table[i];
//       while (tmp != NULL)
//       {
//           node *next = tmp->next;   // save next BEFORE freeing
//           free(tmp);
//           tmp = next;
//       }
//   Return true.
//
// WARNING: Never do `free(tmp); tmp = tmp->next;`
//   Once you free tmp, accessing tmp->next is undefined behaviour!
//   Always save next FIRST, then free.
//
// HINT: Use valgrind to check for leaks:
//   valgrind --leak-check=full ./speller dictionaries/small texts/cat.txt
// ---------------------------------------------------------------------------
bool unload(void)
{
    // TODO: loop over all N buckets
    for (int i = 0; i < N; i++)
    {
        // TODO: free every node in this bucket's linked list
        // node *tmp = table[i];
        // while (tmp != NULL)
        // {
        //     node *next = tmp->next;
        //     free(tmp);
        //     tmp = next;
        // }
    }

    return true;
}
