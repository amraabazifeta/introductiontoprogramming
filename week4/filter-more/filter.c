// CS50x Week 4 — Filter (More): filter.c
// ⚠️  DO NOT MODIFY THIS FILE
// Distribution code provided by CS50.
// Same as filter-less but uses -e (edges) instead of -s (sepia).

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "helpers.h"

int main(int argc, char *argv[])
{
    // Define allowed filters: blur, edges, grayscale, reflect
    char *filters = "begr";

    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "Only one filter allowed.\n");
        return 2;
    }

    if (argc != optind + 2)
    {
        fprintf(stderr, "Usage: ./filter [flag] infile outfile\n");
        return 3;
    }

    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 6;
    }

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    for (int i = 0; i < height; i++)
    {
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);
        fseek(inptr, padding, SEEK_CUR);
    }

    switch (filter)
    {
        case 'b':
            blur(height, width, image);
            break;
        case 'e':
            edges(height, width, image);
            break;
        case 'g':
            grayscale(height, width, image);
            break;
        case 'r':
            reflect(height, width, image);
            break;
    }

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i = 0; i < height; i++)
    {
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    free(image);
    fclose(inptr);
    fclose(outptr);
    return 0;
}
