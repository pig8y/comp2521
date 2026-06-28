# Graph Pitfalls

## 1.  Maximum Possible of edges in undirected graph

**Pitfall:**  
Good practice to knowing the maximum possible of edges in undirected graph is (V * E) / 2

**Source:**  
Week 5 Quiz Q8

## 2.   Graph traversal pseudocode writing

**Pitfall:**
When writing any graph traversal algorithm, BFS or DFS, or any variation of each (i.e. dfsFindPath, bfsGetPath), thinking about structring predecessor array, ALWAYS KNOW THAT HANPPENED ONLY INSIDE OF "for each neighbour w from v" INSTEAD OF ANYWHERE ELSE, you'll stucked at the start of the pseudocode if you forget and start to brainstorming about how do I complete this predecessor

**Source:**  
Week 7 Lab Optional Challenge Task 1

## 3.   Visited array in BFS and DFS

**Pitfall:**
Just remember, BFS once findout the neighbour is not visited, it marks it visited when ENQUEUING, DFS do that at the start of each iteration/recursion, cuz in BFS, you'll visit those neighbour right now after you enqueue them, but in DFS, you went to one neighbour house and keep going deep and just ignore any other neighbour

**Source:**  
Week 7 Task 2 - DFS Maze Solver

## 4.   Hamiltonian and Euler

**Pitfall:**
If a graph has Hamiltonian path => connected since each vertex is connected
If a graph has Euler path => doesn't mean it is connected, maybe there's a vertex does not have edge

**Source:**  

## 5.   Djikstra alogirthm

因为djikstra是找从src到任意的的shortest path，所以只要是能符合*从src开始*，是在这条路上的条件，就可以说这条shortest path中间的任意两点之间的shortest path也是他们两个点之间shortest path

**Source:**
Week 8 Quiz 7 Q5

## 6.   Good pratice

**Source:**
Week 8 Quiz 7 Q8