// CS50x Week 4 — Filter (More): helpers.c
// ✏️  YOUR CODE GOES HERE
//
// Same as Filter-Less PLUS one harder function: edges()
// grayscale, reflect, blur — identical to Filter-Less
// edges — Sobel operator for edge detection (replaces sepia)

#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------------------------------------
// TODO 1: GRAYSCALE  (same as Filter-Less)
// ---------------------------------------------------------------------------
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // TODO: average R+G+B, assign to all channels (use round())
        }
    }
}

// ---------------------------------------------------------------------------
// TODO 2: REFLECT  (same as Filter-Less)
// ---------------------------------------------------------------------------
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // TODO: swap image[i][j] and image[i][width-1-j] for j in 0..width/2
    }
}

// ---------------------------------------------------------------------------
// TODO 3: BLUR  (same as Filter-Less)
// ---------------------------------------------------------------------------
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // TODO: copy image, then for each pixel average its valid 3x3 neighbourhood
}

// ---------------------------------------------------------------------------
// TODO 4: EDGES  ⭐⭐⭐⭐  (Filter-More exclusive — harder!)
// ---------------------------------------------------------------------------
// Detect edges using the Sobel operator.
//
// Background:
//   The Sobel operator uses two 3×3 kernels (Gx and Gy) to compute the
//   gradient of brightness in the horizontal and vertical directions.
//   Pixels with large gradients are "edges".
//
// Kernels:
//   Gx:          Gy:
//   -1  0  +1    -1 -2 -1
//   -2  0  +2     0  0  0
//   -1  0  +1    +1 +2 +1
//
// Algorithm (per channel, per pixel):
//   1. Make a copy of the image first.
//   2. For each pixel (i, j):
//      a. Treat out-of-bounds neighbours as black (R=G=B=0).
//      b. For each channel (R, G, B) separately:
//         - Compute Gx = sum of (Gx_kernel[di+1][dj+1] * neighbour_channel)
//         - Compute Gy = sum of (Gy_kernel[di+1][dj+1] * neighbour_channel)
//         - Final value = round(sqrt(Gx^2 + Gy^2))
//         - Cap at 255
//      c. Assign final R, G, B to image[i][j].
//
// HINT: Define the Gx and Gy kernels as 2D int arrays.
// HINT: Use (int) cast when reading copy channels to allow negative arithmetic.
// HINT: round(sqrt(Gx*Gx + Gy*Gy)) — use sqrt() and round() from <math.h>.
//
// Example (pixel surrounded by white pixels on left, black on right):
//   Gx for red channel will be large → edge detected → bright pixel output.
// ---------------------------------------------------------------------------
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel kernels
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

    // TODO: declare a copy of the image (same as blur)

    // TODO: outer loops over each pixel (i, j)
    //   For each pixel:
    //     Initialize gx_r, gy_r, gx_g, gy_g, gx_b, gy_b = 0
    //     Inner loops di = -1..1, dj = -1..1:
    //       - If neighbour (i+di, j+dj) is out of bounds, treat as (0,0,0)
    //       - Otherwise use copy[i+di][j+dj]
    //       - Accumulate: gx_r += Gx[di+1][dj+1] * neighbour_red; etc.
    //     Final channel = min(255, round(sqrt(gx_r^2 + gy_r^2))); etc.
    //     Assign to image[i][j]
}
