# BST Operation time complexity
h: the maximum steps from the root to the leaf
n: number of nodes

## Insertion
O(h) => traverse the maximum path length from the root to the leaf

## Searching
O(h) => traverse the maximum path length from the root to the leaf to find the value

## Traversal
O(n) => traverse every nodes in the bst

## Join
O(h_2) => traverse the maximum path length of t_2 from the root to the leaf to find the minimum node
After finding the minimum node, moving it to the root only requires a constant number of pointer updates, so it is O(1), which can be ignored

## Delete
O(h) => traverse the maximum path length from the root to the leaf to delete the value
