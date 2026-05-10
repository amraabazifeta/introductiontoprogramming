# Lab 5: Inheritance 🧬

Simulate blood type inheritance across three generations using a recursive family tree.

## Background

Blood types are determined by two alleles — each letter is either **A**, **B**, or **O**.
Every person inherits **one allele from each parent**, chosen at random.

| Allele 1 | Allele 2 | Blood Type |
|---|---|---|
| A | A | AA |
| A | B | AB |
| A | O | AO |
| B | B | BB |
| B | O | BO |
| O | O | OO |

## Usage
```bash
make inheritance
./inheritance
```

**Sample output:**
```
Grandparent (Generation 2): blood type OA
Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type OB
Grandparent (Generation 2): blood type AO
Grandparent (Generation 2): blood type OO
    Parent (Generation 1): blood type OO
        Child (Generation 0): blood type OB
```

## Your Tasks

### TODO 1: `create_family(int generations)`
Recursively allocate a `person` struct and fill in parents and alleles.

```
generations > 1:
  → create two parents recursively
  → inherit one random allele from each parent

generations == 1:
  → set parents[0] = NULL, parents[1] = NULL
  → assign two random alleles via random_allele()
```

### TODO 2: `free_family(person *p)`
Recursively free the entire tree — parents first, then the node itself.

```
if p is NULL → return
free_family(p->parents[0])
free_family(p->parents[1])
free(p)
```

## Memory Check
```bash
valgrind --leak-check=full ./inheritance
# Should report: "All heap blocks were freed -- no leaks are possible"
```

## Submit
```bash
check50 cs50/labs/2024/x/inheritance
submit50 cs50/labs/2024/x/inheritance
```
