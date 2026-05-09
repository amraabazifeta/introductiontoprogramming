// CS50x Week 4 — Filter (More): helpers.c

#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// TODO 1: GRAYSCALE
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed   = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue  = average;
        }
    }
}

// TODO 2: REFLECT
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp           = image[i][j];
            image[i][j]             = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// TODO 3: BLUR
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(image[0][0]) * height * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sum_r += copy[ni][nj].rgbtRed;
                        sum_g += copy[ni][nj].rgbtGreen;
                        sum_b += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed   = round(sum_r / count);
            image[i][j].rgbtGreen = round(sum_g / count);
            image[i][j].rgbtBlue  = round(sum_b / count);
        }
    }
}

// TODO 4: EDGES
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(image[0][0]) * height * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_r = 0, gy_r = 0;
            int gx_g = 0, gy_g = 0;
            int gx_b = 0, gy_b = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    int r = 0, g = 0, b = 0;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        r = copy[ni][nj].rgbtRed;
                        g = copy[ni][nj].rgbtGreen;
                        b = copy[ni][nj].rgbtBlue;
                    }

                    gx_r += Gx[di + 1][dj + 1] * r;
                    gy_r += Gy[di + 1][dj + 1] * r;
                    gx_g += Gx[di + 1][dj + 1] * g;
                    gy_g += Gy[di + 1][dj + 1] * g;
                    gx_b += Gx[di + 1][dj + 1] * b;
                    gy_b += Gy[di + 1][dj + 1] * b;
                }
            }

            int final_r = round(sqrt(gx_r * gx_r + gy_r * gy_r));
            int final_g = round(sqrt(gx_g * gx_g + gy_g * gy_g));
            int final_b = round(sqrt(gx_b * gx_b + gy_b * gy_b));

            image[i][j].rgbtRed   = final_r > 255 ? 255 : final_r;
            image[i][j].rgbtGreen = final_g > 255 ? 255 : final_g;
            image[i][j].rgbtBlue  = final_b > 255 ? 255 : final_b;
        }
    }
}