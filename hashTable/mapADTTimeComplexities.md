# Map ADT - STORE KEY-VALUE PAIRS, WHERE KEYS ARE UNIQUE


**Operations**
        - Insert => replace value with given key if it exists
        - Lookup => return value with given key if it exists
        - Delete => delete key-value pair with given key

**Time complexities with different data structure**

1. Unordered array
        - Insert: O(n)
        - Lookup: O(n)
        - Delete: O(n)
        All scan n elements to do correspond operation
2. Ordered array
        - Insert: O(n)
        - Lookup: O(logn)
        - Delete: O(n)
3. Balanced bst
        - Insert: O(logn)
        - Lookup: O(logn)
        - Delete: O(logn)
