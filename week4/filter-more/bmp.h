// CS50x Week 4 — BMP type definitions (distribution code)
// DO NOT MODIFY THIS FILE

#include <stdint.h>

// Aliases for C types
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// BMP file header (first 14 bytes)
typedef struct
{
    WORD   bfType;       // "BM" magic bytes
    DWORD  bfSize;       // size of file in bytes
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;    // offset to pixel data
} __attribute__((__packed__))
BITMAPFILEHEADER;

// BMP info header (next 40 bytes)
typedef struct
{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// One RGB pixel (3 bytes: Blue, Green, Red)
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
