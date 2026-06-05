# ADT Pitfalls

## 1. Queue ADT Abstraction Does Not Prevent Storing Your Own Data Type

**Pitfall:**  
Not being allowed to access the internal structure of `Queue.c` can be confused with not being allowed to store a custom data type, such as `struct node *`, inside a queue.

**Answer / How to Avoid It:**  
You cannot access or depend on the internal implementation of the Queue ADT, but you can enqueue and dequeue your own data through its public interface if `Item` is defined appropriately. For example, dequeuing into `struct node *node` and then accessing `node->value` is valid when the queue stores node pointers.

**Example:**

```c
struct node *n;
Queue q = QueueNew();

QueueEnqueue(q, n);
struct node *node = QueueDequeue(q);

printf("%d", node->value);
```

**Source:**  
Week 4 Lab, Level-Order Implementation
