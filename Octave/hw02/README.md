# Math Project #2

The execution result can be found in `result.txt`.

## Explanation

### Question 2

1. The rank of a matrix should be equal to that of its transpose.

   $\because rank(A) = dim(Col(A)) = dim(Row(A)) = dim(Col(A^T)) = rank(A^T)$

2. The nullity of a matrix wouldn't always be equal to that of its transpose.
   
   Let $M$ be a $m \times n$ matrix,

   $
   \because dim(Col(M)) = dim(Row(M)) = dim(Col(M^T)) \\
   \begin{aligned}
   n &= dim(Col(M)) + dim(Nul(M))       \\
   m &= dim(Row(M)) + dim(Nul(M^T))     \\
     &= dim(Col(M^T)) + dim(Nul(M^T))
   \end{aligned}
   $

   If $n \neq m$, $dim(Nul(M)) \neq dim(Nul(M^T))$

### Question 4

Please refer to the execution result and the documentation below.

### Question 5

Please refer to the execution result and the documentation below.

## Documentation

This documentation only lists those functions that are not self-explanatory.
The rest of the code are mostly consisted of builtin matlab functions.

## `colspace()`

This function first uses `rref()` to find the pivot columns in the matrix.
If the said column has a pivot, append it to the result matrix.

## `rowspace()`

This function first finds all non-zero rows using `rref()` and appends them to the result matrix.

## Determine whether two bases span the same space

If two bases $A$ and $B$ span the same space,
every basis vector in $B$ should be a linear combination of the basis vectors of $A$, and vice versa.
Let $C$ be the vector set of $\{ A | B \}$, the number of pivot columns of $C$ should be half of the total columns amount, i.e., the dimensions of $Col(C)$ should be equal to the dimensions of $Nul(C)$.
