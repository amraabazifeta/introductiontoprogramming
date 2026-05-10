CC = clang
CFLAGS = -Wall -Wextra -std=c11

filter: filter.c helpers.c helpers.h bmp.h
	$(CC) $(CFLAGS) -o filter filter.c helpers.c -lm

clean:
	rm -f filter *.bmp
