// CS50x Week 4 — Recover

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // TODO 1: Validate arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // TODO 2: Open memory card
    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // TODO 3: Declare variables
    BYTE buffer[512];
    int count = 0;
    FILE *img = NULL;
    char filename[8];

    // TODO 4: Main loop
    while (fread(buffer, 1, 512, card) == 512)
    {
        // STEP A: Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // STEP B: Close previous file if open
            if (img != NULL)
            {
                fclose(img);
            }

            // STEP C: Open new output file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "wb");
            count++;
        }

        // STEP D: Write block if we have an open file
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // TODO 5: Close files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}