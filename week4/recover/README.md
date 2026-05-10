# Recover 🔍

Recover deleted JPEG images from a raw memory card file.

## Background
Memory cards store data in 512-byte blocks. When files are "deleted," only
the file table is wiped — the raw pixel data remains. JPEGs can be found
by scanning for their 4-byte magic signature at the start of each block.

## JPEG Signature
Every JPEG begins with these 4 bytes:
```
0xff  0xd8  0xff  0xe_    (where _ is any hex digit 0-f)
```
In C:
```c
buffer[0] == 0xff &&
buffer[1] == 0xd8 &&
buffer[2] == 0xff &&
(buffer[3] & 0xf0) == 0xe0
```

## Usage
```bash
make recover
./recover card.raw
ls *.jpg        # should list 000.jpg through 049.jpg
ls *.jpg | wc   # should print 50
```

## Algorithm (high level)
```
open card.raw
while there are 512-byte blocks to read:
    if block starts with JPEG signature:
        if we have an open output file → close it
        open new file named "###.jpg" (zero-padded counter)
    if we currently have an open output file:
        write this block to it
close the last open file
close card.raw
```

## Filename Format
Use `sprintf` with `%03i`:
```c
char filename[8];
sprintf(filename, "%03i.jpg", count);   // → "000.jpg", "001.jpg", etc.
```

## Common Mistakes
| Mistake | Fix |
|---|---|
| Writing before any JPEG found | Only write if `img != NULL` |
| Not closing previous JPEG before opening new one | Close `img` before `fopen` |
| Not closing last JPEG after loop | Check `img != NULL` after while loop |
| Memory card not found | Pass the correct path as argv[1] |

## Check with CS50
```bash
check50 cs50/problems/2024/x/recover
style50 recover.c
submit50 cs50/problems/2024/x/recover
```
