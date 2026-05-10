# Filter (Less Comfortable) 🎨

Apply image filters to BMP files. Implement four functions in `helpers.c`.

## Usage
```bash
make filter
./filter -g images/yard.bmp out.bmp   # grayscale
./filter -s images/yard.bmp out.bmp   # sepia
./filter -r images/yard.bmp out.bmp   # reflect
./filter -b images/yard.bmp out.bmp   # blur
```

## Files
| File | Touch? | Purpose |
|---|---|---|
| `filter.c` | ❌ No | main() — reads BMP, calls your functions |
| `bmp.h` | ❌ No | BMP struct definitions |
| `helpers.h` | ❌ No | Function prototypes |
| `helpers.c` | ✅ Yes | Your 4 filter implementations |

## Functions to Implement

### 1. `grayscale` ⭐⭐
Average R+G+B, assign to all three channels. Use `round()`.

### 2. `sepia` ⭐⭐
Apply the CS50 sepia matrix. Cap values at 255. Save originals first!

### 3. `reflect` ⭐⭐
Swap pixels left↔right. Loop only to `width/2`.

### 4. `blur` ⭐⭐⭐
Box blur: average the 3×3 neighbourhood. Use a copy — never read from what you're writing!

## Check with CS50
```bash
check50 cs50/problems/2024/x/filter/less
style50 helpers.c
submit50 cs50/problems/2024/x/filter/less
```
