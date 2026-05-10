// CS50x Week 4 — Lab: Volume
// Modify the volume of an audio file.
//
// Usage: ./volume INPUT.wav OUTPUT.wav FACTOR
//   INPUT.wav  — the audio file to read
//   OUTPUT.wav — the audio file to write
//   FACTOR     — a float (e.g. 2.0 doubles volume, 0.5 halves it)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // TODO 1: Validate command-line arguments
    //   - Check that argc == 4
    //   - If not, print usage message and return 1
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // TODO 2: Open input and output files
    //   - Use fopen() with "rb" for input, "wb" for output
    //   - Check that both opened successfully (not NULL)
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open %s.\n", argv[2]);
        return 1;
    }

    // TODO 3: Read and write the WAV header (first 44 bytes) unchanged
    //   - Declare a uint8_t array of size HEADER_SIZE
    //   - fread() the header from input
    //   - fwrite() the header to output
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO 4: Read the volume factor from argv[3]
    //   - Use atof() to convert argv[3] to a float
    float factor = atof(argv[3]);

    // TODO 5: Read each audio sample, scale it, and write it out
    //   - WAV samples are int16_t (16-bit signed integers)
    //   - Use a while loop: keep reading one int16_t at a time until fread returns 0
    //   - Multiply each sample by factor (cast result back to int16_t)
    //   - fwrite() the modified sample to output
    int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        // TODO: scale sample by factor and write to output
        // HINT: sample = (int16_t)(sample * factor);
    }

    // TODO 6: Close both files
    fclose(input);
    fclose(output);

    return 0;
}
