# Pascal's Triangle
This repository contains the solution to three variants of Pascal's Triangle Problem implemented in C++.

## Problem Variants
Variant 1: Given the row and column number, print the value at that position in Pascal’s Triangle.
Variant 2: Given a row number, print that entire row of Pascal’s Triangle.
Variant 3: Given a number n, print the first n rows of Pascal’s Triangle.

## Variant 1: Find Value at Given Row and Column
### Brute Force Solution
- Uses the binomial coefficient formula: nCr = n! / (r! * (n - r)!)
- Given row and col, set n = row - 1 and r = col - 1
- Compute factorials separately and substitute in the formula
- Time Complexity: **O(n) + O(r) + O(n-r)**
- Space Complexity: **O(1)**
### Optimal Solution
- Avoids computing full factorials; uses an iterative formula:
  $$\binom{n}{r} = \binom{n}{r - 1} \times \frac{n - r + 1}{r}$$
- Given row and col, set n = row - 1 and r = col - 1
- Computes value in a single pass by updating result iteratively
- Time Complexity: **O(r)**
- Space Complexity: **O(1)**
## Variant 2: Print the Nth Row
### Brute Force Solution
- In this approach, for every column from `1` to `n`, we calculate the element at position `(n, c)` using the binomial coefficient method from Variant 1: $$\text{row}[c] = \binom{n - 1}{c - 1}$$
- Loop through all columns and apply the formula to build the row
- Time Complexity: **O(n*r)** (because factorial is computed `n` times)  
- Space Complexity: **O(1)**
### Optimal Solution
- Starts with 1 and builds each subsequent value using the relation: res = (res*(row-col))/col
- This avoids redundant factorials and runs in linear time
- Time Complexity: **O(n)**
- Space Complexity: **O(1)**
## Variant 3: Print First N Rows
### Brute Force Solution
- For each row `r` from `1` to `n`, call the brute force method from Variant 2 to compute that row
- Recomputes factorial for each element
- Time Complexity: **O(n^3)**
- Space Complexity: **O(1)**
### Optimal Solution
- For each row `r`, use the optimized row generation technique from Variant 2
- Reduces redundant computation
- Time Complexity: **O(n²)**
- Space Complexity: **O(1)**

## Thought Process

### Understanding the Problem
- Pascal’s Triangle is a triangular array of the binomial coefficients.
- Each entry at `(r, c)` represents the value of `nCr`.

### Insight
- Instead of calculating factorials for every entry, we can **derive the next value using the previous**:
  $$\[nCr = nC(r-1) \cdot \frac{n - r + 1}{r}\]$$
- This reduces both **time and space complexity**.

### Key Optimization
- Avoid using arrays or vectors unless absolutely needed.
- **Print values directly** to maintain **O(1) space**.
- For triangle generation, iterate row-wise and use only scalar operations.
