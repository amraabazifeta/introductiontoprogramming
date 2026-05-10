// CS50x Week 5 — Lab: Inheritance
// Simulate the inheritance of blood types across three generations.
//
// Blood types are determined by two alleles: A, B, or O.
// Each person inherits one allele from each parent, chosen at random.
//
// Generation diagram:
//   Grandparent 1 ──┐
//                    ├── Parent 1 ──┐
//   Grandparent 2 ──┘              ├── Child
//   Grandparent 3 ──┐              │
//                    ├── Parent 2 ──┘
//   Grandparent 4 ──┘
//
// The family is represented as a tree of `person` structs linked by pointers.
// ✏️  YOUR CODE: implement create_family() and free_family() below.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
#define GENERATIONS 3
#define INDENT_LENGTH 4

typedef struct person
{
    struct person *parents[2];   // NULL if no parents
    char alleles[2];             // 'A', 'B', or 'O'
} person;

// Function prototypes
person *create_family(int generations);
void free_family(person *p);
void print_family(person *p, int generation);
void print_codes(void);
char random_allele(void);

// ---------------------------------------------------------------------------
// main — do not modify
// ---------------------------------------------------------------------------
int main(void)
{
    srand(time(0));

    person *p = create_family(GENERATIONS);
    print_family(p, 0);
    free_family(p);

    return 0;
}

// ---------------------------------------------------------------------------
// TODO 1: create_family
// ---------------------------------------------------------------------------
// Allocate (malloc) a new person and populate their alleles and parents.
//
// Parameters:
//   generations — how many generations remain to create
//                 (GENERATIONS for the child, 1 for grandparents)
//
// Rules:
//   If generations > 1:
//     ├── Recursively create TWO parents: create_family(generations - 1)
//     ├── Randomly inherit one allele from parent[0] (alleles[0] or alleles[1])
//     └── Randomly inherit one allele from parent[1]
//
//   If generations == 1 (oldest generation — no parents):
//     ├── Set parents[0] = NULL and parents[1] = NULL
//     └── Randomly assign BOTH alleles using random_allele()
//
// HINT: malloc a new person:
//   person *p = malloc(sizeof(person));
//   if (p == NULL) return NULL;
//
// HINT: pick a random allele from a parent:
//   p->alleles[0] = p->parents[0]->alleles[rand() % 2];
//
// Returns: pointer to the newly created person
// ---------------------------------------------------------------------------
person *create_family(int generations)
{
    // TODO: allocate memory for a new person
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    if (generations > 1)
    {
        // TODO: recursively create two parents
<<<<<<< HEAD
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // TODO: randomly inherit one allele from each parent
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
=======
        // p->parents[0] = create_family(generations - 1);
        // p->parents[1] = create_family(generations - 1);

        // TODO: randomly inherit one allele from each parent
        // p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        // p->alleles[1] = p->parents[1]->alleles[rand() % 2];
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
    }
    else
    {
        // TODO: oldest generation — no parents, random alleles
<<<<<<< HEAD
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
=======
        // p->parents[0] = NULL;
        // p->parents[1] = NULL;
        // p->alleles[0] = random_allele();
        // p->alleles[1] = random_allele();
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
    }

    return p;
}

// ---------------------------------------------------------------------------
// TODO 2: free_family
// ---------------------------------------------------------------------------
// Recursively free the entire family tree rooted at p.
//
// Rules (IMPORTANT — order matters!):
//   1. Base case: if p is NULL, return immediately.
//   2. Recursively free parents FIRST (before freeing p itself):
//        free_family(p->parents[0]);
//        free_family(p->parents[1]);
//   3. Then free p itself: free(p);
//
// WHY order matters:
//   If you free(p) first, p->parents becomes inaccessible → memory leak!
//   Always free children before parents (post-order traversal).
// ---------------------------------------------------------------------------
void free_family(person *p)
{
    // TODO: base case — if p is NULL, return
    if (p == NULL)
    {
        return;
    }

    // TODO: recursively free both parents first
<<<<<<< HEAD
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: then free this person
    free(p);
=======

    // TODO: then free this person
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
}

// ---------------------------------------------------------------------------
// Distribution code below — do not modify
// ---------------------------------------------------------------------------

// Print each family member and their blood type
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Print parents before child
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);

    // Indent based on generation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print the generation label and blood type
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n",
               generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n",
               generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        printf("Grandparent (Generation %i): blood type %c%c\n",
               generation, p->alleles[0], p->alleles[1]);
    }
}

// Randomly choose an allele: 'A', 'B', or 'O'
char random_allele(void)
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
