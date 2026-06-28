# Warshall's algorithm pseudocode
reachabilityMatrix(A)
Input: adjacency matrix adjMatrix
Output: transitive closure matrix
        initialise transitive closure matrix 
        tcMatrix = adjMatrix

        for k from 0 to nV - 1:
                for i from 0 to nV - 1:
                        for j from 0 to nV - 1:
                        if (reach[i][k] && reach[k][j]):
                                tcMatrix[i][j] = true
        return tcMatrix

**Time complexity O(V^3) ==> Three nested loop**
**Space complexity O(V^2) ==> a V * V matrix**
**Now the operation checking reachability becomes O(1) (not O(V+E) by using BFS/DFS anymore)**