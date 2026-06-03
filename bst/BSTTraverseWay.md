# BST Traverse way
## Pre-order => Root-Left-Right
- Traverse the root, then left-subtree, then right-subtree

## Post-order => Left-Root-Right
- Traverse the left-subtree, then root, then right-subtree

## Post-order => Left-Right-Root
- Traverse the left-subtree, then right-subtree, then the root

## Level-order 
- Visit root, then its children, then its children...then the leaves
### Implement it using queue would be easier, it is difficult to do it recursively