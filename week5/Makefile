# CS50 Week 5 — Master Makefile

CC = clang
CFLAGS = -Wall -Wextra -Wshadow -std=c11

.PHONY: all inheritance speller clean

all: inheritance speller

inheritance:
	$(MAKE) -C lab5/inheritance inheritance

speller:
	$(MAKE) -C pset5/speller speller

clean:
	$(MAKE) -C lab5/inheritance clean
	$(MAKE) -C pset5/speller clean
