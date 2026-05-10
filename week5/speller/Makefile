CC = clang
CFLAGS = -Wall -Wextra -std=c11

speller: speller.c dictionary.c dictionary.h
	$(CC) $(CFLAGS) -o speller speller.c dictionary.c

clean:
	rm -f speller
