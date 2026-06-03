# BST Traverse way
## Pre-order => Root-Left-Right
- Traverse the root, then left-subtree, then right-subtree

## In-order => Left-Root-Right
- Traverse the left-subtree, then root, then right-subtree
- In-order traversal always produce a increasing sequence

## Post-order => Left-Right-Root
- Traverse the left-subtree, then right-subtree, then the root

## Level-order 
- Visit root, then its children, then its children...then the leaves
### Implement it using queue would be easier, it is difficult to do it recursively

The sequence of each order, should be able to split in only 3 parts -- root, left and right
e.g. 	
There exists a BST whose in-order traversal is: 3  1  5  4  6
in-order => left-root-right
- assume root is 3, its right subtree would contain 1 5 4 6 which is not possible because 1 < 3
- assume root is 1, its left subtree would contain 3 which is also not possible because 3 > 1
- kepp doing the same thing, split the sequence into three parts in in-order order => left-root-right and will found out no such bst will have this sequence