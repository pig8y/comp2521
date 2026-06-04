# BST Pitfalls and How to Avoid Them

## 1. Do Not Default to Recursion When a BST Operation Uses Two Pointers

**Pitfall:**  
When a BST operation requires two pointers, such as `curr` and `temp`, it is easy to assume that a recursive helper function is necessary.

**Answer / How to Avoid It:**  
First determine whether the task only follows one specific path in the BST rather than visiting every node. If only a path is needed, an iterative solution is often simpler and makes it easier to maintain multiple pointers.

**Source:**  
Git Repository: `bstOperationPractices`, `joinTree(t1, t2)`

---

## 2. Not Every Tree Task Requires Traversing the Whole Tree

**Pitfall:**  
For a tree-related task, it is easy to immediately write a full traversal even when the problem does not require visiting every node.

**Answer / How to Avoid It:**  
Before using a full traversal, determine whether the BST property can guide the search along a single path. For tasks such as finding the closest value, comparing the target with the current node can eliminate an entire subtree at each step.

**Source:**  
Week 4 Lab, `findClosest` Implementation

---

## 3. A BST Problem Is Not Automatically a Recursion Problem

**Pitfall:**  
It is easy to associate BSTs with recursion and assume that every BST operation should be implemented recursively.

**Answer / How to Avoid It:**  
Choose recursion or iteration according to the task, not simply because the data structure is a BST. Recursion is natural when processing complete subtrees, while iteration is often clearer for searching, inserting, or following a single path.

**Source:**  
Personal Reflection
