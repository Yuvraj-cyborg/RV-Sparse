# RV-Sparse

## Problem statement

Given a row-major dense matrix `A` of size `rows x cols` and a vector `x` of length `cols`, implement a single function `sparse_multiply` that does three things using only buffers the caller provides (no `malloc` inside the function):

1. Scan `A` and find every non-zero entry.
2. Store those entries in CSR (Compressed Sparse Row) form into the caller's `values`, `col_indices`, and `row_ptrs` arrays, and report the count through `out_nnz`.
3. Compute `y = A * x` using the CSR data just built and write the result into `y`.

Build and run with:

```bash
gcc -lm -o run challenge.c
./run
```

The test harness in `challenge.c` runs 100 random cases and compares against a dense reference.

## Approach

The function is two simple loops.

First loop builds CSR while walking `A` row by row. Before starting row `i`, the current non-zero count is written into `row_ptrs[i]`. Then for each column `j`, if `A[i*cols + j]` is non-zero, the value goes into `values`, the column into `col_indices`, and the count is incremented. After the last row, the final count is written into `row_ptrs[rows]` and into `*out_nnz`. That gives the standard CSR layout where row `i` lives in `values[row_ptrs[i] .. row_ptrs[i+1] - 1]`.

Second loop does the multiplication. For each row `i`, it walks `k` from `row_ptrs[i]` to `row_ptrs[i+1]` and accumulates `values[k] * x[col_indices[k]]` into a local sum, then stores it in `y[i]`.

Both passes only read from the inputs and write into the caller's buffers, so the zero-allocation constraint is satisfied.
