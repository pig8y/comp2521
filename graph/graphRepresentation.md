# Graph Representation

## Adjacency matrix
- V x V matrix, with 1 indicate an edge between two vertices and zero for no edge between them
- [AdjacencyMatrix image](../img/GraphMatrix.png)
**Implementation**
        struct matrix {
                int nV;
                int nE;
                bool **edges;
        }
**Pros and Cons**
- Edge insertion/deletion/search is efficient O(1), good for dense graph
- Huge memory to store a matrix O(V^2), a sprase graph that does not contain too much edges is a waste of space, 
  also an undirected graph, matrix will store the same edge twice, which means half of the info is repetitive  







## Adjacency list
-  A list, V size, that each element represents the vertex it connects to
- [List image](../img/GraphList.png)
**Implementation**
        struct graph {
                int nV;
                int nE;
                struct node **adjList;
        }

        struct node {
                Vertex v;
                struct node *next;
        }
- If you confused about `struct node **adjList` like I did: 
  [check this](./nodenode*Andnode**.md)

**Pros and cons**
- Space-efficient, O(V+E) memory usage
- But cost much on insertion and deletion, O(V)(matters less for sparse graph)







## Array of edges 
-  Just an array of edges
- [Array image](../img/GraphArray.png)

**Implementation**
        struct graph {
                int nV;
                int nE;
                struct edge *edges;
        }

        struct edge {
                Vertex v;
                Vertex w;
        }
**Pros and cons**
- Very space-efficient when E < V
- Inefficient on insertion and deletion O(E)



**Graph Representation summary table [Check this](../img/GraphRepresentationTable.png)**