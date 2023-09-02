# Basic Knowledge about Disjoint-Set Union

## Fundamental Principles of Disjoint-Set Union

Each set is represented by a tree, where the root's label is the identifier for the entire set, and each node stores its parent node, and *p[x]* represent the parent node of *x*.

### Question
* How to determine if a node is the root:  
`if (p[x] == x)`
* How to find the set identifier for x:  
`while (p[x] != x) x = p[x]`
* How to merge two sets together: Assuming x, y are identifiers of two sets.  
`p[x] = y`

## Operations supported by Disjoint-Set Union

### Initialization
Initially, each element is a separate set.  
`for (int i = 1; i <= n; i++) p[i] = i`

### Find
```
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x])
    return p[x];
}
```

### Merge
`p[find(a)] = find(b);`

Find and Merge operations are in nearly *O(1)* time complexity due to *Path Compression*.

## Path Compression
After a find operation, for a path from *x* to root, directly point them to the root.  
`x = find(p[x]);`




