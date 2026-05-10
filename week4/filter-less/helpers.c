// CS50x Week 4 — Filter (Less): helpers.c
// ✏️  YOUR CODE GOES HERE
//
// Implement four image filters:
//   grayscale  → -g flag
//   sepia      → -s flag
//   reflect    → -r flag
//   blur       → -b flag

#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------------------------------------
// TODO 1: GRAYSCALE
// ---------------------------------------------------------------------------
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// ---------------------------------------------------------------------------
// TODO 2: SEPIA
// ---------------------------------------------------------------------------
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// ---------------------------------------------------------------------------
// TODO 3: REFLECT
// ---------------------------------------------------------------------------
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// ---------------------------------------------------------------------------
// TODO 4: BLUR
// ---------------------------------------------------------------------------
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_r = 0, sum_g = 0, sum_b = 0;
            float count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width)
                    {
                        sum_r += copy[i + di][j + dj].rgbtRed;
                        sum_g += copy[i + di][j + dj].rgbtGreen;
                        sum_b += copy[i + di][j + dj].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(sum_r / count);
            image[i][j].rgbtGreen = round(sum_g / count);
            image[i][j].rgbtBlue = round(sum_b / count);
        }
    }
}