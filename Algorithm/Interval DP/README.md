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
for (int len = 1; len <= n; len ++ )
    for (int L = 1; L + len - 1 <= n; L ++ )
    {
        int R = L + len - 1;
        if (len == 1) f[L][R] = w[L];
        else
            for (int k = L; k < R; K ++ )
                f[L][R] = max(f[L][R], f[L][k] + f[k + 1][R] + s[R] - s[L - 1]);
    }
```
2. Memoization-based approach:
> Memoization: 记忆化，是一种提高计算机程序执行速度的优化技术，注意别和 memorization 记混.
```
int f[N][N];

int dfs(int L, int R)
{
    int &v = f[L][R];
    if (v) return v;
    if(L == R) return w[L];

    v = INF;
    for (int i = L; i < R; i ++ )
        v = max(v, dfs(L, i) + dfs(i + 1, R) + s[R] - s[L - 1]);
    
    return v;
}
```

## Interval Dynamic Programming with Counting of Solutions

## High-Precision Interval Dynamic Programming
> For more details, please read Acwing 1069. Trigulation of a Convex Polygon.

## Multi-Dimensional Interval Dynamic Programming

