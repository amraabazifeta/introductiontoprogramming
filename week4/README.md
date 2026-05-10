# CS50x Week 4 — Memory 🧠

> **Topic:** Pointers · Segmentation Faults · Dynamic Memory Allocation · Stack & Heap · Buffer Overflow

---

## 📋 Exercises Overview

| Exercise | Type | Difficulty | Topic |
|---|---|---|---|
| [Volume](lab4/volume/) | Lab | ⭐⭐ | File I/O, audio samples |
| [Filter (Less)](pset4/filter-less/) | PSet — Required | ⭐⭐⭐ | BMP images, structs, grayscale/sepia/reflect/blur |
| [Filter (More)](pset4/filter-more/) | PSet — Harder | ⭐⭐⭐⭐ | Same as less + Sobel edge detection |
| [Recover](pset4/recover/) | PSet — Required | ⭐⭐⭐ | JPEG forensics, FILE I/O, 512-byte blocks |

> **Note:** Choose **Filter-Less OR Filter-More** (both is bonus credit). **Recover is required for everyone.**

---

## 🧠 Core Concepts This Week

### Pointers
```c
int n = 50;
int *p = &n;     // p holds the ADDRESS of n
printf("%i\n", *p);  // dereference: prints 50
```

### Dynamic Memory
```c
int *arr = malloc(10 * sizeof(int));  // allocate on heap
// ... use arr ...
free(arr);   // ALWAYS free what you malloc!
```

### File I/O
```c
FILE *f = fopen("file.bmp", "rb");   // open for reading binary
fread(&header, sizeof(header), 1, f); // read bytes into struct
fclose(f);                            // close the file
```

### BMP Structure (Filter)
```
BITMAPFILEHEADER  →  14 bytes of file metadata
BITMAPINFOHEADER  →  40 bytes of image metadata
Pixel data        →  rows of RGBTRIPLE structs, padded to multiples of 4
```

### JPEG Signatures (Recover)
Every JPEG starts with these 4 bytes:
```
0xff 0xd8 0xff 0xe_  (where _ is any hex digit 0–f)
```

---

## 🗂️ Repository Structure

```
cs50-week4-template/
├── README.md
├── Makefile
├── .gitignore
├── lab4/
│   └── volume/
│       └── volume.c          ← Modify audio volume
├── pset4/
│   ├── filter-less/
│   │   ├── filter.c          ← main() — DO NOT EDIT
│   │   ├── helpers.h         ← Function prototypes — DO NOT EDIT
│   │   └── helpers.c         ← ✏️ YOUR CODE GOES HERE
│   ├── filter-more/
│   │   ├── filter.c          ← main() — DO NOT EDIT
│   │   ├── helpers.h         ← Function prototypes — DO NOT EDIT
│   │   └── helpers.c         ← ✏️ YOUR CODE GOES HERE (includes edges)
│   └── recover/
│       └── recover.c         ← ✏️ YOUR CODE GOES HERE
└── .github/
    ├── workflows/check.yml
    └── ISSUE_TEMPLATE/bug_report.md
```

---

## 🚀 Quick Start

```bash
# Compile individual exercises
make -C pset4/filter-less filter
make -C pset4/filter-more filter
make -C pset4/recover recover
make -C lab4/volume volume

# Or use the top-level Makefile
make all
make filter-less
make filter-more
make recover
make volume
```

### Testing Filter
```bash
cd pset4/filter-less
./filter -g images/yard.bmp out.bmp   # grayscale
./filter -s images/yard.bmp out.bmp   # sepia
./filter -r images/yard.bmp out.bmp   # reflect
./filter -b images/yard.bmp out.bmp   # blur
```

### Testing Recover
```bash
cd pset4/recover
./recover card.raw     # should produce 000.jpg through 049.jpg
ls *.jpg | wc -l       # should print 50
```

---

## 💡 Key Hints

### Filter — Grayscale
> Average R, G, B and assign all three to that average. Watch for rounding!

### Filter — Sepia
> Use the official formula. Cap each value at 255. Cast to `int` carefully.

### Filter — Reflect
> Swap pixels from the left half with their mirror on the right. Use a temp variable!

### Filter — Blur
> For each pixel, average all valid neighbours (including itself). Don't modify in-place — use a copy!

### Filter — Edges (More only)
> Apply the Sobel operator: compute Gx and Gy for each channel, then `sqrt(Gx² + Gy²)`. Cap at 255.

### Recover
> Read 512 bytes at a time. When you see a JPEG header, open a new file. Keep writing until the next header.

---

## ⚠️ Common Mistakes

| Mistake | Fix |
|---|---|
| Modifying pixels in-place during blur | Copy the whole image first, read from copy, write to original |
| Integer overflow in sepia formula | Cast to `int` or `long` before math |
| Off-by-one in reflect | Loop only to `width / 2` |
| Not closing last JPEG in Recover | Close `outptr` after the while loop ends |
| Memory leak in Recover | `fclose(inptr)` and last `outptr` before `return 0` |
| Forgetting BMP row padding | Distribution code handles this — don't break it |

---

## 📚 Resources
- [CS50 Week 4 Notes](https://cs50.harvard.edu/x/weeks/4/)
- [BMP File Format](https://en.wikipedia.org/wiki/BMP_file_format)
- [Sobel Operator](https://en.wikipedia.org/wiki/Sobel_operator)
- [JPEG Magic Bytes](https://en.wikipedia.org/wiki/JPEG#Syntax_and_structure)
- [CS50 Duck Debugger](https://cs50.ai/)

---

## 📤 Submitting

```bash
cd pset4/filter-less && submit50 cs50/problems/2024/x/filter/less
cd pset4/recover     && submit50 cs50/problems/2024/x/recover
```
