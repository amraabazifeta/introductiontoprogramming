// CS50x Week 5 — Speller: dictionary.h
// ⚠️  DO NOT MODIFY THIS FILE
// Declares the maximum word length and the five functions you must implement.

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word in the dictionary
// (e.g. longest English word is 45 chars — we use 45 + null terminator)
#define LENGTH 45

// Prototypes of functions you must implement in dictionary.c
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
