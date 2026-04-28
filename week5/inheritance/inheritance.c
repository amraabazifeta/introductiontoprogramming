#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENERATIONS 3
#define INDENT_LENGTH 4

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

person *create_family(int generations);
void free_family(person *p);
void print_family(person *p, int generation);
char random_allele(void);

int main(void)
{
    srand(time(0));

    person *p = create_family(GENERATIONS);
    print_family(p, 0);
    free_family(p);

    return 0;
}

person *create_family(int generations)
{
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    if (generations > 1)
    {
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    else
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}

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
