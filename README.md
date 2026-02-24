# Exercise 1 — Hello, It's Me

## Goal
Prompt the user for their name and greet them by name.

## Key Concepts
- `#include` directives
- `string` type (CS50 library)
- `get_string()` — reads a line of text from the user
- `printf()` — prints formatted output
- `%s` format specifier for strings

## Steps
1. Include `<cs50.h>` and `<stdio.h>`
2. Declare a `string` variable
3. Assign it the result of `get_string("What is your name? ")`
4. Use `printf("hello, %s\n", name)` to print the greeting

## Expected Behavior
```
$ ./hello
What is your name? Alice
hello, Alice

$ ./hello
What is your name? Bob
hello, Bob
```

## Check
```bash
check50 cs50/problems/2024/x/hello
style50 hello.c
```
