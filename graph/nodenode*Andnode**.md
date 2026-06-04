# struct node, struct node * and struct node **
        struct node n;
        struct node *p = &n;
        struct node **pp = &p;
- n is a struct node, a data type
- p is a pointer points to n, store n's address
- pp also, a pointer, but points to the pointer p, store p's address

pp              p               n
+-------+       +-------+       +-------------+
|   •---|------>|   •---|------>| value       |
+-------+       +-------+       | next        |
                                +-------------+

- A linked list is bunch of struct node connected with the next pointer, but we need a head
  pointer points to the first node, store its address, make sure we don't lose this linked list

edges           n
+-------+       +-------------+         +-------------+         +-------------+
|   •---|------>| value       |         | value       |         | value       |
+-------+       | next--------|-------->| next--------|-------->| next--------|-------->  NULL
                +-------------+         +-------------+         +-------------+

- In adjacency list, each vertex has its own linked list, storing the info about which node 
  is connected with it, BUT, we have multiple nodes in one grap, which means we needs multiple linked list with multiple pointers point to them, to store their info

edges[0] -----> 1 -----> 3 -----> NULL
edges[1] -----> 0 -----> 2 -----> NULL
edges[2] -----> 1 -------------> NULL
edges[3] -----> 0 -------------> NULL

- But there're too many edges pointers, we should create allocate a memory block, just like
  an array to store these pointers so we don't lose them or get confused

malloc(numVertices * sizeof(struct node *));
+----------+       +---+     +---+
| edges[0] | ----> | 1 | --> | 3 | --> NULL
+----------+       +---+     +---+
| edges[1] | ----> | 0 | --> | 2 | --> NULL
+----------+       +---+     +---+
| edges[2] | ----> | 1 | ----------> NULL
+----------+       +---+
| edges[3] | ----> | 0 | ----------> NULL
+----------+       +---+

- But how do we find this array to get those pointer points to each linked list? We can
  create another pointer points to the array! (Of couse, doesn't has to be a pointer, but this is what the course did to store the address of the array)
- A POINTER POINTS TO A POINTER ===> struct node **

struct node **edges = malloc(numVertices * sizeof(struct node *));
edges
  |
  v
+----------+       +---+     +---+
| edges[0] | ----> | 1 | --> | 3 | --> NULL
+----------+       +---+     +---+
| edges[1] | ----> | 0 | --> | 2 | --> NULL
+----------+       +---+     +---+
| edges[2] | ----> | 1 | ----------> NULL
+----------+       +---+
| edges[3] | ----> | 0 | ----------> NULL
+----------+       +---+

struct node *edges is the things that the pointer pointing to, so to create a pointer to do such thing, we needs to add another `*` to create it

- Now back to graph adjacent list
struct node {
        Vertex v;
        struct node *next
}

sturct graph {
        int nV;
        int nE;
        struct node **adjNode;
}


- One struct contain the number of vertices and edges, also a pointer points to an array
  of pointers that store(points) its connected vertices.
- The other sturct is the linked list store connected vertices of each vertex

struct graph *g = malloc(sizeof(struct graph));
- Create a struct called g;

g->adjNode = malloc(nV * sizeof(struct node*));
- Create the array to store the pointers that points to each linked list

struct node *edges = malloc(sizeof(struct node));
- Create a new node and assign the address of it to the pointer edges

g->adjNode[0] = edges;
- Store that pointer (edges) into the array as the first element

**Initialisation is omitted intentionally**