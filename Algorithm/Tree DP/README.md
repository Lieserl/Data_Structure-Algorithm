# Basic Knowledge about Tree Dynamic Programming

## Diameter of a Tree
Diameter of a tree refers to the length of the longest path between any two nodes in the tree. Typically, this path is considered to be the longest simple path, which means it does not contain any repeated nodes.

### How to Find the diameter of a tree
First of all, we can start a DFS\BFS(usually BFS, since in algorithm competitions, DFS may result in SF)from any node to find the farthest node X, then start from X to find the farthest node Y, then the path length between X and Y is the diameter of the tree.