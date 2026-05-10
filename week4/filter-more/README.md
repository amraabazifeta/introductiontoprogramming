# Filter (More Comfortable) 🔬

Edge detection + grayscale, reflect, blur. Harder version of Filter-Less.

## Difference from Filter-Less
- **No sepia** function
- **Adds `edges()`** — Sobel operator (significantly harder)

## Usage
```bash
make filter
./filter -g images/yard.bmp out.bmp   # grayscale
./filter -r images/yard.bmp out.bmp   # reflect
./filter -b images/yard.bmp out.bmp   # blur
./filter -e images/yard.bmp out.bmp   # edges ← the hard one!
```

## The Sobel Operator — edges()
Uses two 3×3 kernels to detect brightness gradients:

```
Gx kernel:     Gy kernel:
-1  0 +1      -1 -2 -1
-2  0 +2       0  0  0
-1  0 +1      +1 +2 +1
```

For each pixel, per channel: `value = round(sqrt(Gx² + Gy²))`, capped at 255.
Out-of-bounds neighbours are treated as **black (0, 0, 0)**.

## Check with CS50
```bash
check50 cs50/problems/2024/x/filter/more
style50 helpers.c
submit50 cs50/problems/2024/x/filter/more
```
