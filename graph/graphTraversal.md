# Graph Traversal
Graph traversal => find path => search graph => get path
Two main way to search graph, BFS and DFS, and we can also use it to find the path from one vertex to another and knowing what the path looks like

- BFS
        - Search
        - Find path
        - Get path
        - Pseudocode
- DFS
        - Recursive
                - Find path =========>Write the Process of each and its pseudocode
                - Get path
        - Iterative
                - Find path =========>Write the Process of each and its pseudocode
                - Get path


*BFS*
Find shortest path, search vertex, O(V+E) when searching each vertices and edges
Go wide, then deep
Just iterative
Use queue to achieve the 'Go wide' features
queue -- FIFO data type

Two more data structure: 
visited array -- boolean type, if a vertex(denoted by array indedx) is visited, return true, otherwise false
predecessor -- integer type, initialise by -1, -1 means no predecessor for this vertex, element store the index that came from to this vertex
               if v goes to w, index w store index v since v is the predecessor of w

**Pseudocode**
## Find path => O(V+E)
- Not finding the node, is finding the existence path from src to the dest, also not getting the actual look of the path, just finding its existence
- For sure you can just search but not doing anything, but that's meaningless we usually use it to find and get path
- However, the first thing we did on finding path is still do the searching implementation, so we can know if there's a path
- Also, predecessor is actually can do the things that visited array do, so we can just use predecessor array for simplicity

bfs(Graph g, Vertex src)
Input: graph g and the starting vertex src
        Initialise Queue q
        Initialise predecessor array with -1

        pred[src] = src 
**If we use visited array, we'll set visited[src] = true instead and do nothing to pred arary**
        Enqueue src

        while q is not empty:
        Dequeue q and store in v
                for each neighbour w from v:
                        if pred[w] = -1:
                                pred[w] = v //This step also means w is visited
**If we use visiteed array, in this if pred[w] = -1, we needs to wrtie visited[w] = true, but this one only has pred array, so just write the pred of each vertex is fine**
                                Enqueue w
        freeQueue q
**At this point, the search implementation is finished, now you can use this function to search the whole graph, which means we can use it to search the whole graph to find some path between some vertcies hehehehe**

**It's should be some modification in this bfs function, so let's just copy it and change it to the modified version, any change will be marked**

bfs(Graph g, Vertex src, Vertex dest)
**Add parameter dest, since you need to find path, you should've know the destiniation right? Of course, we assume src != dest, if not, add: if(src == dest) return true**
Input: graph g and the starting vertex src
Output: return true if there's path and false otherwise
        Initialise Queue q
        Initialise predecessor array with -1

        pred[src] = src 
        Enqueue src

        while q is not empty:
        Dequeue q and store in v

                for each neighbour w from v:
                        if w = dest:
                                pred[w] = v
                                freeQueue q
                                return true
**We add another if statement while checking neighbour of v to see if this neighbour is the destination, if it is, record the predecessor if we need to print the path, if not just delete that line, then free the queue and return ture, otherwise, keep searching**
                        else if pred[w] = -1:
                                pred[w] = v //This step also means w is visited
                                Enqueue w
        freeQueue q
        return false
**At this point every vertex has been visited and none of them are dest, which means there's no path between src and dest, doesn't mean there's no such vertex(maybe, but not definite), just mean there's no path ONLY**

## Get path => O(V+E)
**This is getting the path, which is print out what the path actually looks like, of course we need still need to know if the path is exist first, then print it out, but no boolean function type is required, so we should remians everything except boolean related line**

bfs(Graph g, Vertex src, Vertex dest)
Input: graph g and the starting vertex src
        Initialise Queue q
        Initialise predecessor array with -1

        pred[src] = src 
        Enqueue src

        while q is not empty:
        Dequeue q and store in v

                for each neighbour w from v:
                        if pred[w] = -1:
                        pred[w] = v //This step also means w is visited
                        Enqueue w
        freeQueue q
**In the slide, it searched the whole graph then to see if there exists path to dest, but I don't think that is efficient enough, so instead I make some modification, but let's look at what slide write first**
        if pred[dest] != -1
                Vertex v = dest
                while v != src:
                        printf "v->"
                        v = pred[v]
                printf src
**Even my one won't boost too much I think,  but still a way to improve search efficiency**
bfs(Graph g, Vertex src, Vertex dest)
Input: graph g and the starting vertex src
        Initialise Queue q
        Initialise predecessor array with -1

        pred[src] = src 
        Enqueue src

        while q is not empty:
        Dequeue q and store in v

                for each neighbour w from v:
                        if w = dest:
                        pred[w] = v
                        printPath(pred, src, dest)
                        freeQueue q
                        return
                        if pred[w] = -1:
                        pred[w] = v //This step also means w is visited
                        Enqueue w
        freeQueue q

printPath(pred[], Vertex src, Vertex dest)
Input: pred array, veretx src and dest
        v = dest
        while v != src:
                printf "v->"
                v = pred[v]
        printf src
**So basically what I did is make a early stop, instead of searching the whole graph, I stopped searching when the dest is found and start printing, which can avoid slow efficency when the graph is dense and large, but still cannot avoid some worst case that causes O(V+E) time**

*DFS*
- Go deep => not wide => use Stack and recursion
- Stack LIFO, use its features to make the "go deep" features come up 
- Recursion => keep recurse, keep go deeps, hits the end, call back

*Recursive*
**Find Path => O(V+E)**
- Recursion is still very confusing, especially it combine with graph, and we have to use it to traverse/search the whole graph
- But think, think, think
- OK still, pred array is still neccessary, since we're using recursion, we're not using Stack since they both used for the "go deep" features
- OK so recursion idea is ==> think what you shuold do in this level, any n-1 problem, let the recursion deal with it, he can do it for sure
- So first of all, to see if there exist a path, we still need to implement the search function first

dfsFindPath(Graph g, Vertex src, Vertex dest)
Input: the graph g, starting vertex src and the destination vertex dest
Output: true if there exist a path and false otherwise
        Initialise predecessor array with -1
        pred[src] = src
        return doDfsFindPath(g, src, dest, pred)
**Here we need another recursive helper function to do the job, because we need to pass one more argunment, which is pred array, unlike iterative implementation, such as BFS, we initialise the pred array and will keep update it after each iteration, each stack frame only store its local variable, which means you needs to pass pred[] that needs to update along the way to finish the searching**

doDfsFindPath(Graph g, Vertex v, Vertex dest, pred[])
Input: the graph g, current vertex v and the destination vertex dest, and predecessor array
Output: true if there exist a path and false otherwise
        if v = dest return true
**base case, think like this: in this layer/level, I need to check if this v is dest, if does, meaning the path exist and then return true**
        for each neighbour w from v:
                if pred[w] = -1:
                        pred[w] = v
                        if (doDfsFindPath(g, w, dest, pred)) return true
**If v is not the dest, that's fine, we now search the neighbour of v, first record their predecessor as v(but not neccessary if you only needs to know if there's path), now it's the crucial part, we now need to see if the neighbour is dest, it is a n-1 problem, we should throw it into recursion, let the recursion do its thing, and if the recursion unwind and return true, we return true back to the main function**
        return false
**Else, which is when the recursion does not return true, meaning there's no path to dest, or maybe, no such vertex**

**Get Path => still O(V+E)**
**To be honest, using what we wrote previously, can easily write the get path implementation**
dfsFindPath(Graph g, Vertex src, Vertex dest)
Input: the graph g, starting vertex src and the destination vertex dest
**First of all, since we are not finding the path, we are getting the path, so we don't need to return boolean in this function, but the helper one, yes**
        Initialise predecessor array with -1
        pred[src] = src
        if(doDfsFindPath(g, src, dest, pred)):
                v = dest
                while v != src:
                        printf(v->)
                        v = pred[v]
                printf src
**Then write the general printing path implementation and we are done**

doDfsFindPath(Graph g, Vertex v, Vertex dest, pred[])
Input: the graph g, current vertex v and the destination vertex dest, and predecessor array
Output: true if there exist a path and false otherwise
        if v = dest return true
        for each neighbour w from v:
                if pred[w] = -1:
                        pred[w] = v
                        if (doDfsFindPath(g, w, dest, pred)) return true
        return false

*Iterative*
**Find Path => O(V+E)**
- Now no more recursion, back to iterative solution, which means we need stack to do the job that recursion did
- Luckily, the implementation of iterative DFS is similar to BFS, so I should now write it a bit quicker

dfsFindPath(Graph g, Vertex src, Vertex dest)
Input: the graph g, current vertex v and the destination vertex dest
Output: return true if the path exist and false otherwise
        if src = dest: return true
        Initialise Stack s
        Initialise pred array with -1
        Push src into s
        pred[src] = src

        while stack s is not empty:
                pop stack into v
                for each neighbour w from v:
                        if pred[w] = -1:
                                pred[w] = v
                                Push w into stack
                        if w = dest:
                                freeStack(s)
                                return true
        freeStack(s)
        return false
                        
**Not that fast, but write most of it myself, get confused on how I should place my pushStack, but yeah basically is the same as bfs implementation, but using stack instead**

**Get Path => O(V+E)**
- Nothing change for this, look back the note if you get confused

dfsGetPath(Graph g, Vertex src, Vertex dest)
Input: the graph g, current vertex v and the destination vertex dest
        initialise pred arr with -1
        if (dfsFindPath(g, src, dest, pred)):
                v = dest
                while v != src:
                        printf "v->"
                        v = pred[v]
                printf src

dfsFindPath(Graph g, Vertex src, Vertex dest, pred[])
Input: the graph g, current vertex v and the destination vertex dest
Output: return true if the path exist and false otherwise
        if src = dest: return true
        Initialise Stack s
        Push src into s
        pred[src] = src

        while stack s is not empty:
                pop stack into v
                for each neighbour w from v:
                        if pred[w] = -1:
                                pred[w] = v
                                Push w into stack
                        if w = dest:
                                freeStack(s)
                                return true
        freeStack(s)
        return false






# Practice 
[graph image](../img/Undirected-unweightedGraph.png)
Trace the execution of the traversal algorithms, and show the state of the visited and pred arrays and the Queue (BFS) or Stack (DFS) at the end of each iteration, for each of the following function calls:

bfs(g, 0);
dfs(g, 0);


There're 8 vertices, so visited and pred arr will have the size of 8
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      0       0       0       0       0       0       0       0

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       -       -       -       -       -       -       -


**bfs(g, 0)**
# Frist iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       0       0       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       -       -       0       0       0

Queue: *0* 1 2 5 6 7 

# Second iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       0       0       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       -       -       0       0       0

Queue: *0* *1* 2 5 6 7

# Third iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       0       0       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       -       -       0       0       0

Queue: *0* *1* *2* 5 6 7

# Fourth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       5       5       0       0       0

Queue: *0* *1* *2* *5* 6 7 3 4

# Fifth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       5       5       0       0       0

Queue: *0* *1* *2* *5* *6* 7 3 4 

The rest of itertaion will not changed anything to any array, it will stopped when the queue is empty

**dfs(g, 0);**
# First iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       0       0       0       0       0

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       -       -       -       -       -

Stack: 0 1

# Second iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       0       0       0       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       -       -       -       -       1

Stack: 0 1 7

# Third iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       0       1       0       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       -       7       -       -       1

Stack: 0 1 7 4

# Fourth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       0       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       -       -       1

Stack: 0 1 7 4 3

# Fifth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       -       1

Stack: 0 1 7 4 3 5

# Sixth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       -       1

Stack: 0 1 7 4 3 5

# RETURN - Seventh iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       -       1

Stack: 0 1 7 4 3 *5*

# RETURN - Eighth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       0       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       -       1

Stack: 0 1 7 4 *3* *5*

# Nineth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       4       1

Stack: 0 1 7 4 *3* *5* 6

# Tenth iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       4       1

Stack: 0 1 7 4 *3* *5* *6*


# Return - Eleven iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       4       1

Stack: 0 1 7 *4* *3* *5* *6*

# Return - Twelve iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       4       1

Stack: 0 1 *7* *4* *3* *5* *6*

# Return - Thirteen iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       0       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       -       4       7       3       4       1

Stack: 0 *1* *7* *4* *3* *5* *6*

# Fourteen iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       4       7       3       4       1

Stack: 0 *1* *7* *4* *3* *5* *6* 2

# Return - Fifteen iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       4       7       3       4       1

Stack: 0 *1* *7* *4* *3* *5* *6* *2*

# Return - Sixteen iteration
               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
visited[]:      1       1       1       1       1       1       1       1

               [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]
predArr[]:      -       0       0       4       7       3       4       1

Stack: *0* *1* *7* *4* *3* *5* *6* *2*

