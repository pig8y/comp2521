# Hashing collision type
- Separate chaining
        - Each element is a linked list
        - Allows multiple key in one slot
- Linear probing
        - Check rest of the array slots consecutively until empty slot is found
- Double hasgin
        - Use secondary hash as increment

# Load facotor -- α
- How full the table is => α = M/N 
- M = number of items
- N = number of slots
- Useful for analyses collision resolution methods

# Analysis
- Separate chaining
        IN WORST HASHING WHERE EVERY ITEMS IS IN ONE SLOT
        Cost of insert/delete/lookup => O(M)

        IN GOOD HASING WHERE ITEMS ARE EVENLY DISTRIBUTED (including average and average case)
        When α <= 1, meaning the amount of slots is greater than the amount of items, cost of insert/delete/lookup is O(1)
        When α > 1, cost is O(M/N)

- Linear probing
# DELETION IN LINEAR PROBING SHOULD BE CONCERNED
        In separate chaining, any insertion/deletion/lookup is just simply "do the thing" 
        But we cannot simply delete an item in linear probing as it breaks the probe path [check why here](./linearProbingDeletionElaboration.md)
        TWO PRIMARY METHODS FOR DEDLETION:
        - Backshift => remove the corresponded item and re-insert all items 
                       between the deleted item and the next empty slot
        - Tombstone => Replace the deleted item with 'deleted' marker, treated 
                       empty when inserting, treated as occupied when looking-up
        Backshift: 
                - Deletion becomes more expensive
                - But move items closer to their has index, thereby reduce the 
                  length of their probe path, sometime break the clustering
                - Also avoid empty slot break the probing path
        Tombstone:
                - Fast
                - But does not reduce probe path length
                - Large number of deletion causes multiple tombstones to build 
                  up and could get many long probe path

# Clustering
- Long regions that don't contain empty slots or
- A single probing sequence getting used multiple time
        - Let say if the first hash always return the same index, and the second hash always returns the same jump size, every item cluster into a same probing sequence, we also called this clustering
        e.g. h_1(8) = h_1(15) = h_1(22) = h_1(29) = h_1(36) = 1
                if the second hash function always return 3, while the table size is 7
                | Key | checked slots       | 最终位置 |
                | --: | -----------------   | ---:--- |
                |   8 | 1                   |    1    |     
                |  15 | 1 → 4               |    4    |
                |  22 | 1 → 4 → 0           |    0    |
                |  29 | 1 → 4 → 0 → 3       |    3    |
                |  36 | 1 → 4 → 0 → 3 → 6   |    6    |
                They ALL CLUSTER IN THE SAME PROBING SEQUENCE although they eventually find themselves a slot, but getting slower after each insertion
        - We can solve this by =====> h_2 = 1 + (n % 6)
                | Key | checked slots       | 最终位置 |
                | --: | -----------------   | ---:--- |
                |   8 | 1                   |    1    | 
                |  15 | 1 → 5               |    5    | 
                |  22 | 1 → 6               |    6    | 
                |  29 | 1 → 0               |    0    | 
                |  36 | 1 → 2               |    2    | 
                They jump with different size this time, n % 6 obtain different jump size, +1 to avoid jump with size of 0
        
- Double hashing
        When hash table is heavily loaded, double hashing is significantly better than linear probing

        Could generate error when after both hashing function, the probing sequence is always making collision (always has item in the calculated position), create infinite loop or insertion failure

        KEY POINT ABOUT THE SECOND HASH FUNCTION
        The second hash function decided each "jump", it should let the key able to access every slot in the table, that is, the jump step size must be coprime to the table size

        Coprime: two numbers has no common factors beside 1