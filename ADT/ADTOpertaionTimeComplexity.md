# ADT Operation time complexity
## Stack -- LIFO
### Linked list
- Push
        O(1) => insert at the beginning of the list
- Pop
        O(1) => delete the first node of the list

### Array
- Push
        O(1) => insert at index (usually insert in order)
- Pop
        O(1) => delete the last element (arr[size - 1]) 
size != capacity, size is the size of the array currently, capacity is how much elements the array can store

## Queue -- FIFO
### Linked list
- Enqueue
        O(1) => insert at the end of the list
- Dequeue
        O(1) => delete the node at the beginning

### Array
- Enqueue
        O(1) => Involves calculate the index and insert the element into that index
- Dequeue
        O(1) => Accessing the item at index `front`
Time complexity same as linked list, but linked list is much more easier

## Set
### Unordered array
- Contain
        O(n) => scan every element (which is n times)
- Insert
        O(n) => scan every element to ensure it is a non-repetitive element
- Delete
        O(n) => scan every element to ensure the element exist
Both insertion and deletion is only O(1)

### Ordered array
- Contain
        O(logn) => scan every element, but using binary search
        bool SetContains(Set s, int elem) {
                int lo = 0;
                int hi = s->size - 1;
                while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (elem < s->elems[mid]) {
                        hi = mid - 1;
                        } else if (elem > s->elems[mid]) {
                                lo = mid + 1;
                        } else {
                                return true;
                        }
                }
                        return false;
        }
- Insert
        O(n) => binary search lets us scan to ensure it is a non-repetitive element is O(logn) time
                but if insert at the beginning of the element, which will requires to shift n elements
- Delete
        O(n) => still using binary search to scan to ensure the element exist, but if delete the first
                element, will requires to shift n - 1 elements after that

### Ordered linked list
- Contain
        O(n) => scan every element (which is n times)

- Insert and deletion
        Both O(n) => both needs to scan every element first, but insertion and deletion only needs O(1) times


[OPERATION TIME COMPLEXITY SUMMARY TABLE](../img/ADTSumTable.png)