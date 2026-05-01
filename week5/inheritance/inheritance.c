#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
#define GENERATIONS 3
#define INDENT_LENGTH 4

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

// Function prototypes
person *create_family(int generations);
void free_family(person *p);
void print_family(person *p, int generation);
char random_allele(void);

// ---------------------------------------------------------------------------
// main
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
// create_family
// ---------------------------------------------------------------------------
person *create_family(int generations)
{
    // Allocate memory
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    // If more generations
    if (generations > 1)
    {
        // Create parents recursively
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // Inherit alleles from parents
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    else
    {
        // Oldest generation
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // Random alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

// ---------------------------------------------------------------------------
// free_family
// ---------------------------------------------------------------------------
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    // Free parents first
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Then free current person
    free(p);
}

// ---------------------------------------------------------------------------
// Print family
// ---------------------------------------------------------------------------
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);

    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

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

// ---------------------------------------------------------------------------
// Random allele
// ---------------------------------------------------------------------------
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
