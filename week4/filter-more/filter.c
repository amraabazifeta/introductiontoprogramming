#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "helpers.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./filter [flag] infile outfile\n");
        return 1;
    }

    char *option = argv[1];

    FILE *infile = fopen(argv[2], "rb");
    if (!infile)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *outfile = fopen(argv[3], "wb");
    if (!outfile)
    {
        fclose(infile);
        printf("Could not create file.\n");
        return 1;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, infile);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, infile);

    if (bf.bfType != 0x4d42 || bi.biBitCount != 24)
    {
        fclose(infile);
        fclose(outfile);
        printf("Unsupported file format.\n");
        return 1;
    }

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    RGBTRIPLE image[height][width];

    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    for (int i = 0; i < height; i++)
    {
        fread(image[i], sizeof(RGBTRIPLE), width, infile);
        fseek(infile, padding, SEEK_CUR);
    }

    if (option[1] == 'g')
    {
        grayscale(height, width, image);
    }
    else if (option[1] == 'r')
    {
        reflect(height, width, image);
    }
    else if (option[1] == 'b')
    {
        blur(height, width, image);
    }
    else if (option[1] == 'e')
    {
        edges(height, width, image);
    }
    else
    {
        printf("Invalid filter.\n");
        return 1;
    }

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);

    for (int i = 0; i < height; i++)
    {
        fwrite(image[i], sizeof(RGBTRIPLE), width, outfile);

        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
