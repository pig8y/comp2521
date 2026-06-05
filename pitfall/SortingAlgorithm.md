# Sorting Algorithm Pitfalls

## 1. Stable Sorting in Multi-Key Sorting

**Pitfall:**  
When sorting data with three keys, it is easy to think that only the final key needs to be sorted using a stable sorting algorithm.

**Answer / How to Avoid It:**  
Each sorting pass must be stable, and the keys should be sorted from lowest priority to highest priority. This preserves the ordering established by earlier passes when later keys are sorted.

**Source:**  
Week 2 Lecture 2.1

---

## 2. Understanding the Worst Cases of Bubble Sort and Insertion Sort

**Pitfall:**  
It is easy to memorise that Bubble Sort and Insertion Sort have worst-case time complexity of `O(n^2)` without understanding what input actually causes the worst case.

**Answer / How to Avoid It:**  
For ascending-order sorting, a reverse-sorted array typically causes the worst performance because the algorithms must perform the maximum number of comparisons and swaps or shifts. Trace the algorithms manually on reversed input rather than only memorising the complexity.

**Source:**  
Week 3 Quiz Q4, Q5

---

## 3. Finding the Pivot Position During Partitioning

**Pitfall:**  
When tracing a partitioning algorithm, it is easy to assume that once `l == r`, the pivot should always be swapped into that index. However, the value at that index may still be greater than the pivot.

**Answer / How to Avoid It:**  
Follow the comparison condition in the code, such as `if (pivot < items[l]) l--;`, before deciding the final pivot position. If the value at the meeting index is greater than the pivot, the pivot should be swapped with the element one position earlier instead.

**Source:**  
Week 3 Tutorial Q4 Part A

---

## 4. Why Bottom-Up Merge Sort Is Suitable for External Sorting

**Pitfall:**  
It is easy to remember that bottom-up merge sort is useful when the dataset is too large to fit in RAM, without understanding why it works well for external sorting.

**Answer / How to Avoid It:**  
When data cannot fit into RAM, it can be divided into smaller sorted runs that fit in memory, then repeatedly merged. Merge sort is suitable because merging mainly involves sequential reading and writing on disk, avoiding expensive random disk access.

**Source:**  
Week 3 Lecture 2.3
