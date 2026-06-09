dfs(Graph g, src, dest)
        initialise pred array with -1
        initialise visited array with false or 0
        if (doDfs(g, src, dest, visited, pred)) printPath(src, dest, pred)

doDfs(Graph g, Vertex v, Vertex dest, visited, pred)
        visited[v] = true
        for each neighbour w from v:
                pred[w] = v
                if w == dest:
                        visited[w] = true
                        return true
                if visited[w] = false:
                        if (doDfs(g, w, dest, visited, pred)) return true
        return false

printPath(src, n, pred)
        while n != src:
                printf(n)
                n = pred[n]


hasCycle(Graph g)
        
        initialise visited array 
        for each vertex v in g:
                if visited[v] == false:
                        if (doHasCycle(g, v, pred, visited)) return true
        return false

doHasCycle(Graph g, Vertex v, pred, visited[])
        visited[v] = visited
        for each neighbour w form v:
                if w = pred: continue
                if (visited[w] == true) return true
                else if (doHasCycle(g, w, v, visited)) return true
        return false


        
hasCycleDi(Graph g)
        
        initialise visited array 
        initialise onStack array
        for each vertex v in g:
                if visited[v] == false:
                        if (doHasCycle(g, v, visited, onStack)) return true
        return false

doHasCycleDi(Graph g, Vertex v, visited[], onStack[])
        visited[v] = visited
        onStack[v] = true
        for each neighbour w form v:
                if (onStack[w] == true) return true
                else if visited[w] == false:
                        if (doHasCycle(g, w, v, visited)) return true
        onStack[v] = false
        return false