// CS50x Week 4 — Filter (More): helpers.h
// DO NOT MODIFY THIS FILE

#include "bmp.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width]);
void reflect(int height, int width, RGBTRIPLE image[height][width]);
void blur(int height, int width, RGBTRIPLE image[height][width]);
void edges(int height, int width, RGBTRIPLE image[height][width]);
