// CS50x Week 4 — Recover
// ✏️  YOUR CODE GOES HERE
//
// Recover JPEG images from a forensic memory card image.
//
// Usage: ./recover IMAGE
//   IMAGE — a raw memory card file (e.g. card.raw)
//
// How it works:
//   Memory cards store data in 512-byte blocks.
//   Deleted JPEGs leave their data intact — only the file table is cleared.
//   We can find each JPEG by looking for its 4-byte signature at the start of a block.
//
// JPEG signature (first 4 bytes of every JPEG):
//   bytes[0] == 0xff
//   bytes[1] == 0xd8
//   bytes[2] == 0xff
//   bytes[3] & 0xf0 == 0xe0   (i.e. bytes[3] is between 0xe0 and 0xef)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ---------------------------------------------------------------------------
    // TODO 1: Validate command-line arguments
    //   - argc must be exactly 2
    //   - Print usage and return 1 if wrong
    // ---------------------------------------------------------------------------
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // ---------------------------------------------------------------------------
    // TODO 2: Open the memory card file for reading (binary mode)
    //   - Use fopen(argv[1], "rb")
    //   - Check it opened successfully — print error and return 1 if not
    // ---------------------------------------------------------------------------
    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // ---------------------------------------------------------------------------
    // TODO 3: Declare your variables
    //   - A 512-byte buffer:   BYTE buffer[512];
    //   - A counter for JPEGs found: int count = 0;
    //   - A FILE* for output:  FILE *img = NULL;
    //   - A filename string:   char filename[8];
    //     (format: "###.jpg" needs 7 chars + null terminator = 8)
    // ---------------------------------------------------------------------------

    // TODO: declare buffer, count, img, filename here

    // ---------------------------------------------------------------------------
    // TODO 4: Main loop — read one 512-byte block at a time
    //
    //   while (fread(buffer, 1, 512, card) == 512)
    //   {
    //       // STEP A: Check if this block starts a new JPEG
    //       //   if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
    //       //       buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    //
    //       //   STEP B: If we already have an open file, close it
    //
    //       //   STEP C: Open a new output file
    //       //     sprintf(filename, "%03i.jpg", count);
    //       //     img = fopen(filename, "wb");
    //       //     count++;
    //
    //       //   STEP D: If we currently have an open output file, write the block
    //       //     fwrite(buffer, 1, 512, img);
    //   }
    // ---------------------------------------------------------------------------

    // TODO: implement the while loop using the steps above

    // ---------------------------------------------------------------------------
    // TODO 5: Close any remaining open file and close the card
    //   - If img != NULL, fclose(img)
    //   - fclose(card)
    // ---------------------------------------------------------------------------

    // TODO: close files here

    return 0;
}
