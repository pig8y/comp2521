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