# Djikstra's Algorithm
- Djikstra's algorithm is to find the SHORTEST PATH in WEIGHTED GRAPH

Three data structures used in Djikstra's algorithm:
- Predecessor Array
- Distance Array => store the shortest path between the src vertex to any other vertices
- Vertex Set => a set contains all the unvisited array (e.g. visited array can be used as vertex set as well)

**Dijkstra's algorithm pseudocode**
dijkstraAlgSP(Graph g, src)
initialise dist array with infinity (In C => INT_MAX)
initialise pred array with -1
initialise set with all vertiecs in g

        dist[src] = 0
while set is not empty:
        minVertex = the vertex that has the smallest dist 
        remove it from the set
                for each neighbour w from minVertex:
                        edgeRelaxation(minVertex, w, weight, dist, pred)

edgeRelaxation(v, w, weight, dist[], pred[])
        if dist[v] + weight < dist[w]:
                dist[w] = dist[v] + weight
                pred[w] = v

**Types of Set of Vertex**
- Visited array => in each iteration, find the vertex that is false AND dist[v] is minimal
        Space complexity: O(V)
        Time complexity IN EACH ITERATION: O(V)
- List of vertices => can be array or linked list, store every vertices and remove it if it has minimal dist[v] 
        Space complexity: O(V)
        Time complexity IN EACH ITERATION: O(V)
- Priority queue => an ADT where store item and tag each one to create priority. Each item is removed/inserted based on the highest priority (in this case, it can be remove the
                    smallest dist[v])
        Space complexity: O(V)
        Time complexity IN EACH ITERATION: O(logn)

**Time complexity analysis**
Djikstra's algorithm spend time on:
- finding vertex with shortest distance
- checking each edges from the vertex with shortest distance

Each edge is considered once when checking each edges from the vertex with shortest distance => O(E)
Time complexity of finding vertex with shortest distance depends on which data structure used as set of vertices, which is shown above


*OVERALL TIME COMPLEXITY*
Since there exist V round of iteration in each program execution:
- Visited array => O(E + V * V) = O(V^2)
- Array/list of vertices => O(E + V * V) = O(V^2)
- Priority queue => O(E + V * logV) => O(VlogV)
