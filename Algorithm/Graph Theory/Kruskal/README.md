# Basic Knowledge about Kruskal's Algorithm
Since *Quick Sort* takes *O(mlogm)* to operate, mainly due to the number of edges, Kruskal's Algorithm is
usually used in sparse graphs.

## Foundamental Principle of Kruskal's Algorithm

### Greedy Principle
At each step, we select the smallest available edge, which ensures the weight of the spanning tree is always the smallest,

### Cycle Property
In an undirected graph, if adding an edge results in a cycle, then this edge does not belong to the minimum spanning tree.
> Property 财产, 性质.

### Connectivity
Kruskal's algorithm uses *Disjoint-Set Union* to detect whether an edge will form a cycle. If two vertices are already in the same set, adding an edge will form a cycle, which contradicts *Cycle Property*. In the end, when *n-1* edges have been selected, all vertices are connected, forming a spanning tree.
> vertice 顶点.

## Steps of the Kruskal's Algorithm
1. Sort all edges in ascending order based on their weights in *O(mlogm)* time complexity.
> Ascending 上升的.
2. Enumerate each edge (a, b) with weight c, if a, b are not connected, then add this edge to the set in *O(m)* time complexity.
```
if (find(a) != find(b))
    p[find(a)] = find(b);
```
> Enumerate 枚举.

