# Basic Knowledge about Interval Dynamic Programming

1. State Description：*f[i, j]*
* Set: All possible solutions for merging intervals (i, j) of stones.
* Property: *Min*.

2. State Calculation: *f[i, j] = min(f[i, k] + f[k + 1, j] + S[i, j])*

*Time Complexity: O(n^3)* 

## Circular Interval Problems in Interval Dynamic Programming

### Problem-Solving Approaches

1. For a cyclic path of length *n*, we can iterate through the gap and transform it into a chain, enabling us to use *One-Dimensional Interval Dynaimc Programming* for solving in *O(n^4)* time complexity.

> Why not *with*: *of* describes the characteristic of a cyclic path rather than indicating a relationship between two distinct entities.
> entity: 实体.

2. For a cyclic path of length *n*, we can extend it into a chain of length *2n*. This allows us to apply *One-Dimensional Interval Dynaimc Programming* to the extended chain and enumerate the minimun valie within the chains of length *n* in *O(8n^3)* time complexity.

### Specific Code Implementation Approaches.

1. Iterative-based approach:

```
for (int len = 1; len <= n; len ++)
    for (int L = 1; L + len - 1 <= n; L ++)
        R = L + len - 1;
```
1. Memoization-based approach:
> Memoization: 记忆化，是一种提高计算机程序执行速度的优化技术，注意别和 memorization 记混.

## Interval Dynamic Programming with Counting of Solutions

## High-Precision Interval Dynamic Programming

## Multi-Dimensional Interval Dynamic Programming

