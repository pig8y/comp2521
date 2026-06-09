# Graph Representation
- Two ways of traverse graoph => BFS and DFS
- But essentially of both is access each vertex and find its edges => each neighbour w from v
- Thus, different representation will have let BFS/DFS has different way to access each vertex's neighbour, then different way to traversal

**Adjacency List Traversal**
        A: B, C
        B: A, D
        C: A, D
        D: B, C
When BFS/DFS use adjacency list to traverse:
while exist not handled vertex:
        v = list[i]
        *for every neighbour w from inAdjList[v]:*
                if w is not visited:
                        visit(w)

- *List traversal only look at the edge that exist, won't waste time checking not existed edge*
- Which means if there's a sparse graph(less edge), let say each vertex has at most three edges incident to it, and only using it on traversal
- If there exist V vertices, E edges, the time complexity of traversal is O(V+E)
- Since each vertex has at most three edges, that is, the upper boundary for the amount of edges is 3V, thus O(V+E) => O(V+3V) => O(V)


**Adjacency Matrix Traversal**
            A  B  C  D
        A   0  1  1  0
        B   1  0  0  1
        C   1  0  0  0
        D   0  1  0  0
When BFS/DFS use adjacency matrix to traverse:
while exits not handled vertex:
        v = list[v.row][col]
        *for every vertices in row w in inAdjMatrix:*
                if matrix[v.row][i] == 1:
                        visit([v.row][i])
                else:
                        continue;
- *Matrix traversal have to check if the edge/neighbour is actually exist, then visit, which is one extra step than adjacency list*
- And this extra step is huge, since to traverse the whole graph, BFS/DFS needs to traverse each row(each vertex) and check their
  relation with other vertex first, then visit its actual neighbour. 
- That is, V vertices will need to scan v times => time complexity becomes O(V*V) => O(V^2)


**Adjacency Edge Traversal**
        [(A, B), (A, C), (B, D)]
When BFS/DFS use adjacency matrix to traverse:
while exits not handled vertex:
        v is the current vertex
        *for every edges (a, b) in inAdjEdges:*
                if a == v and b is not visited:
                        a = v
                        visit(b)
                if b == v and a is not visited:
                        b = v
                        visit(a)
- For each vertex, it needs to scan E edges
- If there exits V vertices, the time complexity will be O(VE)
- If the graph is sparse, each vertex only has K edges incident to it, meaning maximally, there will exist K * V edges => O(V*KV) => O(KV^2) => O(V^2)



*Summary*
Adjacency list is the best option for traversal with no doubt, especially in a sparse graph. Even in a dense graph, most likely adjacecncy is still better,
edge list is just useless in traversal