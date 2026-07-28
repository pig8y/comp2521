# BST Pitfalls

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

## 4. AVL Rotation

**Pitfall:**  
It is easy to think that because AVL insertion checks upward from the newly inserted node, so that when doing rotation to rebalance, also starts from the new inserted node

**Answer / How to Avoid It:**  
AVL insertion does check upward from the newly inserted node, but the rotation case is determined from the first unbalanced node, not from the newly inserted node.

LR case:
      z
     /
    y
     \
      x

Unbalanced point: z
1. Left rotate at y
2. Right rotate at z

rotation starts from the first unbalanced node z,
and in LR / RL, the first rotation is performed at y, the second step from z.

**Source:**  
Week 5 Quiz Q6

## 5. AVL index

**Pitfall:**
Remember to distinguish the difference between value and index when saying paritioned on something (e.g. partitioned on index 5 (NOT value 5))

**Source:**
Week 5 Quiz Q3

## 6. AVL Rotation2.0

**Pitfall:**
When asking what is the sequence of rotation will be performed after deletion in LR/RL case, it is not talking about always rotate at the root, but the two adjaceny node, which means if LR case, say rotate left, then right; if RL case, say rotate right, then left