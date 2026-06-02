# Sorting algorithm syllabus draft

## Analysis dimensions:
- N => number of input size
- C => number of comparison
- S => number of swapping position

## Property
- Stability -- ability of not changing relative order
- Adaptability -- ability of performs much fast with nearly sorted/sorted (Best/Average case) data
- In-place -- require no extra/temporary spaces(e.g. arr, linked list) during sorting

Q2
## Selection analysis
Property
- Worst/Average/Best case: O(n^2) 
- Unstable
- Non-adaptive
- In-place

- It executes very slow which is not suit for large amount of data, and not an option
  when sorting data requires to keep the relative order
- It suits for small data or there has limited memory situation, or any cases that swap cost
  so much

## Bubble analysis
Property
- Worst/Average: O(n^2), Best: O(n)
- Stable
- Adaptive
- In-place

- Since the time complexity for worst case is O(n^2), it is not suit for sorting large amount 
  of data
- It is a stable algorithm which is an option when needs to keep the relative order after 
  sorting, it does not takes extra spaces for sorting, so it is also an option when limited
  memory situation encountered, but not recommoneded to choose insertion becuase of this 
  reason only, since it still has O(n^2) when encountered average or worst case. Also, 
  bubble sort can swiftly process any sorted/small/ sorted data and can STOP EARLY, 
  PRODUCE NO SWAP, which is an option when the, however, insertion has  better performance
  which is not the primary choice in such case. Bubble sort is an option for some 
  nearly-sorted cases, but insertion is usually better then bubble

## Insertion analysis
Property
- Worst/Average: O(n^2), Best: O(n)
- Stable
- Adaptive
- In-place

- Since the time complexity for worst case is O(n^2), it is not suit for sorting large amount  
  of data
- It is a very good choice to sort a small/ nearly-sorted/sorted data, insertion has good 
  performance in such cases within these algorithm It is also memory friendly, which will 
  be an option when there's limited memory provided, but still, not recommoneded to choose 
  insertion becuase of this reason only, since it still has O(n^2) when encountered average or
  worst case. Also it is an option when the data has to remain equal-keys relative order.

## Merge sort
Property
- Worst/Average/Best: O(nlogn)
- Stable
- Non-adaptive
- Non-in-place 

- It has gurantee performance in any scenario, which is good for any predictable worst-case 
  scenario and a good choice sorting LINKED LIST data structure or task that can be 
  parallelised, and a good option to remains equal-key relative order in data. Merge also has
  relatively fast pace (O(nlogn)), which is better for big data
- It does not suit for limited memory condition since merge sort required temprorary spaces 
  for sorting.

## Bottom-up merge
Property
- Worst/Average/Best: O(nlogn)
- Stable
- Non-adaptive
- Non-in-place 

- Bottom-up remains the same benefits and disadvantages that merge sort does, but using 
  iterative solution that avoids recursive splitting process and stack overhead, which
  makes it an option when there's limited stack memory for stack frame, and encounter
  predictable worst scenario. Can be used for external sorting

## Naive quick sort
Property
- Worst: O(n^2), Average/Best: O(nlogn)
- Unstable
- Non-adaptive
- In-place

- It is the basic version of any quick sort algorithm. It is a poor choice encounter 
  predictable worst secnario since it is readily leads to O(n^2) performance, such as facing
  sorted or reverse sorted data. It is not stable which is also not an option for
  keeping equal-key order requirement

## Median-of-three quick sort
Property
- Worst: O(n^2), Average/Best: O(nlogn)
- Unstable
- Non-adaptive
- In-place

- It largely prevents the presense of worst case by modify pivot selection, it does not 
  eliminate worst case, but make it happenned less likely. By select the median 
  between the first, middle and last element of the data to reduces the chance of extrememly
  unbalanced partition

## Randomised quick sort
Property
- Worst: O(n^2), Average/Best: O(nlogn)
- Unstable
- Non-adaptive
- In-place

- Randomised quicksort selects the pivot randomly, making it very difficult for a particular 
  input order to systematically force bad pivot choices. It still has a theoretical worst-case
  time complexity of O(n^2), but the worst case is much harder to trigger systematically.

## Insertion-quick-sort
Proprty
- Worst: O(n^2), Average/Best: O(nlogn)
- Unstable
- Non-adaptive
- In-place

- It it useful to avoid stack overhead or when recursion call is expensive, since it uses 
  insertion to solve any small sequences (e.g. thershold = 5), while insertion has good
  performance on dealing small data, but its property remains since it only modifies the
  situation where too many stack frames occurred or it is not worthy to solve small sequence
  recursively


## Radix sort
Property
- Worst/Average/Best: O(m(n+R)) m: number of element, n: number of key, R: radix (O(mn) when R is very small)
- Stable
- Non-adaptive
- Non-in-place

- Radix sort is a non-comparison based sorting algorithm, it can outperform comparison 
  based sorting algorithm when key value can be splited and short, and has small amount of 
  radix, or keeping equal key in order
- However, when encounter key that is unsplitable, long or has large range of radix, largely
  effect the performace of radix sort, or limited memory spaces since it requires extra space
  for bucket

Q3
Selection Sort: [4, 1, 7, 3, 8, 6, 5, 2]

Bubble Sort: [4, 3, 6, 1, 2, 5]

Insertion Sort: [4, 1, 7, 3, 8, 6, 5, 2]

Merge Sort: [5, 2, 4, 7, 3, 1]

Bottom-Up Merge Sort: [5, 2, 4, 7, 3, 1]

Naive Quick Sort: [1, 2, 3, 4, 5, 6]

Median-of-Three Quick Sort: [1, 2, 3, 4, 5, 6], [2, 5, 3, 7, 8, 2, 1, 4, 6]

Randomised Quick Sort: [2, 5, 3, 7, 8, 6]

Radix Sort: [329, 457, 657, 839, 436, 720, 355]

Q4
## Selection sort: [4, 1, 7, 3, 8, 6, 5, 2]
Scan from arr[0] to arr[n - 1], find the smallest number, place it at the first index,
then from arr[1] to arr[n - 1], find the second smallest number, place it at the second index and repeat

#1 min = 1, swap with 4
[1, 4, 7, 3, 8, 6, 5, 2]
#2 min = 2, swap with 4
[1, 2, 7, 3, 8, 6, 5, 4]
#3 min = 3, swap with 7
[1, 2, 3, 7, 8, 6, 5, 4]
#4 min = 4, swap with 7
[1, 2, 3, 4, 8, 6, 5, 7]
#5 min = 5, swap with 8
[1, 2, 3, 4, 5, 6, 8, 7]
#6 min = 6, swap with 6
[1, 2, 3, 4, 5, 6, 8, 7]
#7 min = 7, swap with 8
[1, 2, 3, 4, 5, 6, 7, 8]
#8 min = 8, swap with 8
[1, 2, 3, 4, 5, 6, 7, 8]
sorted

## Bubble sort: [4, 3, 6, 1, 2, 5]
Pass from left to right, compare while traversing and swap any non-increasing order adjacent pair, stops when no swap in an iteration
#1 4 > 3, swap
[3, 4, 6, 1, 2, 5]
#2 4 < 6, no swap
[3, 4, 6, 1, 2, 5]
#3 6 > 1, swap
[3, 4, 1, 6, 2, 5]
#4 6 > 2, swap
[3, 4, 1, 2, 6, 5]
#5 6 > 5, swap
[3, 4, 1, 2, 5, 6]
Swap made during this iteration, continue, hi = hi - 1
#6 3 < 4, no swap
[3, 4, 1, 2, 5, 6]
#7 4 > 1, swap
[3, 1, 4, 2, 5, 6]
#8 4 > 2, swap
[3, 1, 2, 4, 5, 6]
#9 4 < 5, no swap
[3, 1, 2, 4, 5, 6]
Swap made during this iteration, continue, hi = hi - 1
#10 3 > 1, swap
[1, 3, 2, 4, 5, 6]
#11 3 > 2, swap
[1, 2, 3, 4, 5, 6]
#12 3 < 4, no swap
[1, 2, 3, 4, 5, 6]
Swap made during this iteration, continue, hi = hi - 1
#13 1 < 2, no swap
[1, 2, 3, 4, 5, 6]
#14 2 < 3, no swap
[1, 2, 3, 4, 5, 6]
No swap made during this iteration, sorted

## Insertion Sort: [4, 1, 7, 3, 8, 6, 5, 2]
Place the first element in sorted array, pass the next element in and swap until the sorted array is in order, and repeat
#1 sorted array: [4], insert 1
   4 > 1, swap
   sorted array: [1, 4], sorted
   [1, 4, 7, 3, 8, 6, 5, 2]
#2 sorted array: [1, 4], insert 7
   4 < 7, no swap
   sorted array: [1, 4, 7], sorted
   [1, 4, 7, 3, 8, 6, 5, 2]
#3 sorted array: [1, 4, 7], insert 3
   7 > 3, swap
   sorted array: [1, 4, 3, 7]
   4 > 3, swap
   sorted array: [1, 3, 4, 7]
   1 < 3, no swap
   sorted array: [1, 3, 4, 7], sorted
   [1, 3, 4, 7, 8, 6, 5, 2]
#4 sorted array: [1, 3, 4, 7], insert 8  
   7 < 8, no swap
   sorted array: [1, 3, 4, 7, 8], sorted
   [1, 3, 4, 7, 8, 6, 5, 2]
#5 sorted array: [1, 3, 4, 7, 8], insert 6
   8 > 6, swap
   sorted array: [1, 3, 4, 7, 6, 8]
   7 > 6, swap
   sorted array: [1, 3, 4, 6, 7, 8]
   3 < 6, no swap
   sorted array: [1, 3, 4, 6, 7, 8], sorted
   [1, 3, 4, 6, 7, 8, 5, 2]
#6 sorted array: [1, 3, 4, 6, 7, 8], insert 5
   8 > 5, swap
   sorted array: [1, 3, 4, 6, 7, 5, 8]
   7 > 5, swap
   sorted array: [1, 3, 4, 6, 5, 7, 8]
   6 > 5, swap
   sorted array: [1, 3, 4, 5, 6, 7, 8]
   4 < 5, no swap
   sorted array: [1, 3, 4, 5, 6, 7, 8], sorted
   [1, 3, 4, 5, 6, 7, 8, 2]
#7 sorted array: [1, 3, 4, 5, 6, 7, 8], insert 2
   8 > 2, swap
   sorted array: [1, 3, 4, 5, 6, 7, 2, 8]
   7 > 2, swap
   sorted array: [1, 3, 4, 5, 6, 2, 7, 8]
   6 > 2, swap
   sorted array: [1, 3, 4, 5, 2, 6, 7, 8]
   5 > 2, swap
   sorted array: [1, 3, 4, 2, 5, 6, 7, 8]
   4 > 2, swap
   sorted array: [1, 3, 2, 4, 5, 6, 7, 8]
   3 > 2, swap
   sorted array: [1, 2, 3, 4, 5, 6, 7, 8]
   1 < 2, no swap
   sorted array: [1, 2, 3, 4, 5, 6, 7, 8], sorted
   Sorted

## Merge Sort: [5, 2, 4, 7, 3, 1]
Calculate the midpoint of the array, then RECURSIVELY sort each half by passing appropriate indices
      - Sort between lo and mid
      - Sort between mid + 1o and hi
      if (hi <= lo) return
#1 mid = 0 + 5 / 2 = 2
  Sort between lo and mid, lo = 0, hi = 2
      #1.1 mid = 0 + 2 / 2 = 1
        Sort between lo and mid, lo = 0, hi = 1
            #1.1.1 mid = 0 + 1 / 2 = 0
              Sort between 0 and 0, lo = 0, hi = 0
                #1.1.1.1 lo = hi, return
              Sort between mid + 1 and hi, lo = 1, hi = 1
                #1.1.1.2 lo = hi, return
            #1.1.2 Merge, lo = 0, hi = 1, mid = 0
              tmp arr size = hi - lo + 1 = 2
              arr1 = [5], arr2 = [2], temp = []
              5 > 2, insert 2
              arr1 = [5], arr2 = [2], temp = [2]
              no element in arr2, insert 5
              arr1 = [5], arr2 = [2], temp = [2, 5]
              replace from arr[lo] to arr[hi] with temp
Current array: [2, 5, 4, 7, 3, 1]
        Sort between mid + 1 and hi, lo = 2, hi = 2
            #1.1.3 lo = hi, return
      #1.2 Merge, lo = 0, hi = 2, mid = 1
        temp arr size = hi - lo + 1 = 3
        arr1 = [2, 5], arr2 = [4], temp = []
        2 < 4, insert 2
        arr1 = [2, 5], arr2 = [4], temp = [2]
        5 > 4, insert 4
        arr1 = [2, 5], arr2 = [4], temp = [2, 4]
        no element in arr2, insert 5
        arr1 = [2, 5], arr2 = [4], temp = [2, 4, 5]
        replace from arr[lo] to arr[hi] with temp
Current array: [2, 4, 5, 7, 3, 1]
  Sort between mid + 1 and hi, lo = 3, hi = 5
      #1.3 mid = 3 + 5 / 2 = 4
        Sort between lo and mid, lo = 3, hi = 4
            #1.3.1 mid = 3 + 4 / 2 = 3
              Sort between lo and mid, lo = 3, hi = 3
                  #1.3.1.1 lo = hi, return
              Sort between mid + 1 and hi, lo = 4, hi = 4
                  #1.3.1.2 lo = hi, return
            #1.3.2 Merge, lo = 3, hi = 4, mid = 4
              temp arr size = 4 - 3 + 1 = 2
              arr1 = [7], arr2 [3], temp = []
              7 > 3, insert 3
              arr1 = [7], arr2 [3], temp = [3]
              no element in arr2, insert 7
              arr1 = [7], arr2 [3], temp = [3, 7]
              replace from arr[lo] to arr[hi] with temp
Current array: [2, 4, 5, 3, 7, 1]
        Sort between mid + 1 and hi, lo = 5, hi = 5
            #1.3.3 lo = hi, return
      #1.4 Merge, lo = 3, hi = 5, mid = 4
        temp arr size = 5 - 3 + 1 = 3
        arr1 = [3, 7], arr2 = [1], temp = []
        3 > 1, insert 1
        arr1 = [3, 7], arr2 = [1], temp = [1]
        no element in arr2, insert 3 then 7
        arr1 = [3, 7], arr2 = [1], temp = [1, 3, 7]
        replace from arr[lo] to arr[hi] with temp
Current array: [2, 4, 5, 1, 3, 7]
  #2 Merge, lo = 0, hi = 5, mid = 2
    temp arr size = 5 - 0 + 1 = 6
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = []
    2 > 1, insert 1
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1]
    2 < 3, insert 2
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1, 2]
    4 > 3, insert 3
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1, 2, 3]
    4 < 7, insert 4
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1, 2, 3, 4]
    5 < 7, insert 5
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1, 2, 3, 4, 5]
    no element in arr1, insert 7
    arr1 = [2, 4, 5], arr2 = [1, 3, 7], temp = [1, 2, 3, 4, 5, 7]
    replace from arr[lo] to arr[hi] with temp
Current array: [1, 2, 3, 4, 5, 7]
Sorted

## Bottom-Up Merge Sort: [5, 2, 4, 7, 3, 1]
Non-recursive sorting, first merge adjacent elements with length of 2, then 4, 8...(no splitting in bottom-up)
#1 Sort slices of length 2:
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = []
5 > 2, insert 2
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2]
no element in other array, insert 5
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2, 5], first slices sorted
4 < 7, insert 4
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2, 5, 4]
no element in other array, insert 7
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2, 5, 4, 7], second slices sorted
3 > 1, insert 1
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2, 5, 4, 7, 1]
no element in other array, insert 3
Adjacent elements: [[5], [2]] [[4], [7]] [[3], [1]], temp = [2, 5, 4, 7, 1, 3], third slices sorted
replace from arr[lo] to arr[hi] with temp
Current array: [2, 5, 4, 7, 1, 3]
Slices length of 2 sorted
#2 Sort slices of length 4: 
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = []
2 < 4, insert 2
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = [2]
5 > 4, insert 4
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = [2, 4]
5 < 7, insert 5
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = [2, 4, 5]
no element in other array, insert 7
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = [2, 4, 5, 7]
no element on other array, insert 1 then 3
Adjacent elements: [[2, 5], [4, 7]] [[1, 3]], temp = [2, 4, 5, 7, 1, 3]
replace from arr[lo] to arr[hi] with temp
Current array: [2, 4, 5, 7, 1, 3]
Slices length of 4 sorted
#3 Sort slices of length 8:
Adjacent elements:[[2, 4, 5, 7], [1, 3]], temp = []
2 > 1, insert 1
Adjacent elements:[[2, 4, 5, 7], [1, 3]], temp = [1]
2 < 3, insert 2
Adjacent elements:[[2, 4, 5, 7], [1, 3]], temp = [1, 2]
4 > 3, insert 3
Adjacent elements:[[2, 4, 5, 7], [1, 3]], temp = [1, 2, 3]
no element on the other array, insert 4, 5 then 7
Adjacent elements:[[2, 4, 5, 7], [1, 3]], temp = [1, 2, 3, 4, 5, 7]
replace from arr[lo] to arr[hi] with temp
Current array: [1, 2, 3, 4, 5, 7]
Sorted

## Naive Quick Sort: [1, 2, 3, 4, 5, 6]
A recursive sorting algorithm, choose the first item as pivot and put it in the middle, the partition the array so that:
 - All elements to the left is smaller than (or equal to) the pivot value
 - All elements to the right is larger than (or equal to) the pivot value
#1 pivotIndex(item, lo, hi), lo = 0, hi = 5
  pivot = 1, l = lo + 1, r = hi
  [1, 2, 3, 4, 5, 6]
  2 > 1, l stops
  6 > 1, r--
  5 > 1, r--
  4 > 1, r--
  3 > 1, r--
  l = r = 1, break loop
  pivot < item[l], 1 < 2, l--, l = 0
  swap arr[l] and arr[pivot], l = pivot = 0, no swap
Current array: [1, 2, 3, 4, 5, 6]
  pivotIndex = l = 0
#2 Arrange the elements to the left, lo = 0, hi = pivot - 1 = -1,
    #2.1 lo > hi, return, lo = 0, hi = -1
#3 Arrange the elements to the right, lo = pivodIndex + 1 = 1, hi = 5
    #3.1 pivotIndex(item, lo, hi), lo = 1, hi = 5
      pivot = 2, l = lo + 1 = 2, r = 5
      [1, 2, 3, 4, 5, 6]
      3 > 2, l stops
      6 > 2, r--
      5 > 2, r--
      4 > 2, r--
      3 > 2, r--
      l = r = 2, break loop
      pivot < item[l], 2 < 3, l--, l = 1
      swap arr[lo] and arr[l], lo = l = 1, no swap
Current array: [1, 2, 3, 4, 5, 6]
      pivotIndex = l = 1
    #3.2 Arrange the elements to the left, lo = 1, hi = pivot - 1 = 0
        #3.2.1 lo > hi, return,  lo = 1, hi = -1
    #3.3 Arrange the elements to the right, lo = pivot + 1 = 2, hi = 5
        #3.3.1 pivotIndex(item, lo, hi), lo = 2, hi = 5
          pivot = 3, l = lo + 1 = 3, r = 5
          [1, 2, 3, 4, 5, 6]
          4 > 3, l stops
          6 > 3, r--
          5 > 3, r--
          l = r = 3, break loop
          pivot < item[l], 3 < 4, l--, l = 2
          swap arr[lo] and arr[l], lo = l = 2, no swap
Current array: [1, 2, 3, 4, 5, 6]
          pivotIndex = l = 2
        #3.3.2 Arrange the elements to the left, lo = 2, hi = pivot - 1 = 1
          #3.3.2.1 lo > hi, return
        #3.3.3 Arrange the element to the right, lo = pivot + 1 = 3, hi = 5
            #3.3.3.1 pivotIndex(item, lo, hi), lo = 3, hi = 5
              pivot = item[lo] = 4, l = lo + 1= 4, r = hi = 5
              [1, 2, 3, 4, 5, 6]
              5 > 4, stop l
              6 > 4, r--
              l = r = 4, break loop
              pivot < item[l], 4 < 5, l--, l = 3
              swap arr[lo] and arr[l], l = lo = 3, no swap 
Current array: [1, 2, 3, 4, 5, 6]
              pivotIndex = l = 3
            #3.3.3.2 Arrange the element to the left, lo = 3, hi = pivotIndex - 1 = 2
                #3.3.3.2.1 lo > hi, return
            #3.3.3.3 Arrange the element to the right, lo = pivotIndex + 1 = 4, hi = 5
                #3.3.3.3.1 pivotIndex(item, lo, hi), lo = 4, hi = 5
                  pivot = item[lo] = 5, l = lo + 1 = 5, r = hi = 5
                  l = r = 5, break loop
                  pivot < item[l], 5 < 6, l--, l = 4
                  swap arr[lo] and arr[l], lo = l = 4, no swap 
Current array: [1, 2, 3, 4, 5, 6]
                  pivotIndex = l = 4
                #3.3.3.3.2 Arrange the element to the left, lo = 4, hi = pivotIndex - 1 = 3
                    #3.3.3.3.2.1 lo > hi, return
                #3.3.3.3.3 Arrange the element to the right, lo = pivotIndex + 1 = 5, hi = 5
                    #3.3.3.3.3.1 lo = hi, return
#3.3.3.3.3 finish, return
Current array: [1, 2, 3, 4, 5, 6]
#3.3.3.3 finish, return
Current array: [1, 2, 3, 4, 5, 6]
#3.3.3 finish, return
Current array: [1, 2, 3, 4, 5, 6]
#3.3 finish, return
Current array: [1, 2, 3, 4, 5, 6]
#3 finish, return
Current array: [1, 2, 3, 4, 5, 6]
Sorted

====================================================================================================================================================================================
==========This process apply worst case for Naive quick sort, where you can see the algorithm continue pick the smallest value as pivot with this sorted, increasing array==========
===========================================that is, when keep picking smallest value as pivot, become the worst case for Naive Quick Sort===========================================
====================================================================================================================================================================================

Median-of-Three Quick Sort: [1, 2, 3, 4, 5, 6]
It is also a recursive sorting algorithm, by picking the median of lo, mid and hi as pivot, then RECURSIVELY arrange the elements to the left that less or equal to the pivot, and
the elements to right that larger or equal to the pivot
[1, 2, 3, 4, 5, 6], where is the worst case for Naive Quick Sort
#1 medianOfThree(item, lo, hi) lo = 0, hi = 5
mid = 0 + 5 / 2 = 2
item[lo] = 0, item[hi] = 6, item[mid] = 3
median = 3, swap them into median->smallest->largest order
Current array: [3, 2, 1, 4, 5, 6]
#2 pivotIndex(item, lo, hi), lo = 0, hi = 5
  pivot = 3, l = lo + 1 = 1, r = hi = 5
  [3, 2, 1, 4, 5, 6]
  2 < 3, l++
  1 < 3, l++
  4 > 3, l = 3
  6 > 3, r--
  5 > 3, r--
  l = r = 3, break loop
  pivot < item[l], 3 < 4, l--
  swap item[lo] and item[l], lo = 0, l = 2
Current array: [1, 2, 3, 4, 5, 6]
  pivotIndex = l = 2
#3 Arrange elements to the left, lo = 0, hi = pivotIndex - 1 = 1
    #3.1 medianOfThree(item, lo, hi), lo = 0, hi = 1
    item[lo] = 1, item[hi] = 2, item[mid] = item[0 + 1 / 2] = 1 
    median is 1, swap them in to median->smallest->largest order
Current array: [1, 2, 3, 4, 5, 6]
    #3.2 pivotIndex(item, lo, hi), lo = 0, hi = 1
      pivot = item[lo] = 1, l = lo + 1 = 1, r = hi = 1
      l = r = 1,  break loop
      pivot < item[l], 1 < 2, l--, l = 0
      swap arr[lo] and arr[l], lo = l = 0, no swap
Current array: [1, 2, 3, 4, 5, 6]
      pivotIndex = l = 0
    #3.3 Arrange elements to the left, lo = 0, hi = pivotIndex - 1 = -1
        #3.3.1 lo > hi, return
    #3.4 Arrange element to the right, lo = pivotIndex + 1 = 1, hi = 1
        #3.4.1 lo > hi, return
#3.4 finish, return
Current array: [1, 2, 3, 4, 5, 6]
#4 Arrange elements to the right, lo = pivotIndex + 1 = 3, hi = 5
    #4.1 medianOfThree(item, lo, hi), lo = 3, hi = 5
    item[lo] = 4, item[lo + hi / 2] = item[4] = 5, item[hi] = 6, 
    median is 5, swap them into median->smallest->largest order
Current array: [1, 2, 3, 5, 4, 6]  
    #4.2 pivodIndex(item, lo, hi), lo = 3, hi = 5
    pivot = 5, l = lo + 1 = 4, r = hi = 5
    [1, 2, 3, 5, 4, 6]
    4 < 5, l++
    l = r = 5, break loop
    pivot < item[l], 5 < 6, l--, l = 4
    swap pivot and item[l]
Current array: [1, 2, 3, 5, 4, 6]
    pivodIndex = l = 4
    #4.3 Arrange element to the left, lo = 3, hi = pivotIndex - 1 = 3
        #4.3.1 lo = hi, return
    #4.4 Arrange element to the right, lo = pivotIndex + 1 = 5, hi = 5
        #4.4.1 lo = hi, return
#4.4 finish return
Current array: [1, 2, 3, 4, 5, 6]
#4 finish, return
Current array: [1, 2, 3, 4, 5, 6]
Sorted

====================================================================================================================================================================================
====The way the median-of-three quick sort select pivot avoids picking smallest value as pivot every time in this case, which is faster solve sorted array than Navie quick sort====
====================================================================================================================================================================================

## Randomised Quick Sort: [2, 5, 3, 7, 8, 6]
# Randomised Quick Sort: `[2, 5, 3, 7, 8, 6]`
It is a recursive sorting algorithm. It randomly chooses a pivot, swaps the chosen pivot into `items[lo]`, then partitions the array so that the elements to the left are less than or equal to the pivot, and the elements to the right are greater than or equal to the pivot. It then recursively sorts the left and right partitions.
Because the pivot is chosen randomly, the process is not unique. For this trace, assume that the random indices chosen are:
randint(0, 5) = 2
randint(2, 5) = 3
randint(2, 3) = 2
Initial array:
[2, 5, 3, 7, 8, 6]
## #1 `randomisedQuickSort(items, lo, hi)`, `lo = 0`, `hi = 5`
Randomly choose a pivot:
randint(0, 5) = 2
items[2] = 3
Swap `items[lo]` and `items[2]` so that the randomly chosen pivot is placed at `items[lo]`:
swap items[0] and items[2]
swap 2 and 3
Current array:
[3, 5, 2, 7, 8, 6]
### #1.1 `pivotIndex(items, lo, hi)`, `lo = 0`, `hi = 5`
pivot = items[lo] = 3
l = lo + 1 = 1
r = hi = 5
Current array:
[3, 5, 2, 7, 8, 6]
Scan from the left and right:
items[l] = 5
5 < 3 is false
l stays at 1
items[r] = 6
6 > 3, r--, r = 4
items[r] = 8
8 > 3, r--, r = 3
items[r] = 7
7 > 3, r--, r = 2
items[r] = 2
2 > 3 is false
r stays at 2
Now:
l = 1, r = 2
l != r
Swap `items[l]` and `items[r]`:
swap 5 and 2
Current array:
[3, 2, 5, 7, 8, 6]
Continue scanning:
items[l] = 2
2 < 3, l++, l = 2
l = r = 2, break loop
Place the pivot into its correct position:
pivot < items[l]
3 < 5, l--, l = 1
swap items[lo] and items[l]
swap 3 and 2
Current array:
[2, 3, 5, 7, 8, 6]
pivotIndex = l = 1
## #2 Arrange elements to the left of pivot `3`, `lo = 0`, `hi = pivotIndex - 1 = 0`
### #2.1 `randomisedQuickSort(items, lo, hi)`, `lo = 0`, `hi = 0`
lo = hi, return
Current array:
[2, 3, 5, 7, 8, 6]
## #3 Arrange elements to the right of pivot `3`, `lo = pivotIndex + 1 = 2`, `hi = 5`
### #3.1 `randomisedQuickSort(items, lo, hi)`, `lo = 2`, `hi = 5`
Randomly choose a pivot:
randint(2, 5) = 3
items[3] = 7
Swap `items[lo]` and `items[3]` so that the randomly chosen pivot is placed at `items[lo]`:
swap items[2] and items[3]
swap 5 and 7
Current array:
[2, 3, 7, 5, 8, 6]
### #3.2 `pivotIndex(items, lo, hi)`, `lo = 2`, `hi = 5`
pivot = items[lo] = 7
l = lo + 1 = 3
r = hi = 5
Current array:
[2, 3, 7, 5, 8, 6]
Scan from the left and right:
items[l] = 5
5 < 7, l++, l = 4
items[l] = 8
8 < 7 is false
l stays at 4
items[r] = 6
6 > 7 is false
r stays at 5
Now:
l = 4, r = 5
l != r
Swap `items[l]` and `items[r]`:
swap 8 and 6
Current array:
[2, 3, 7, 5, 6, 8]
Continue scanning:
items[l] = 6
6 < 7, l++, l = 5
l = r = 5, break loop
Place the pivot into its correct position:
pivot < items[l]
7 < 8, l--, l = 4
swap items[lo] and items[l]
swap 7 and 6
Current array:
[2, 3, 6, 5, 7, 8]
pivotIndex = l = 4
### #3.3 Arrange elements to the left of pivot `7`, `lo = 2`, `hi = pivotIndex - 1 = 3`
#### #3.3.1 `randomisedQuickSort(items, lo, hi)`, `lo = 2`, `hi = 3`
Randomly choose a pivot:
randint(2, 3) = 2
items[2] = 6
The chosen pivot is already at `items[lo]`, so the swap does not change the array:
swap items[2] and items[2]
Current array:
[2, 3, 6, 5, 7, 8]
#### #3.3.2 `pivotIndex(items, lo, hi)`, `lo = 2`, `hi = 3`
pivot = items[lo] = 6
l = lo + 1 = 3
r = hi = 3
l = r = 3, break loop
Place the pivot into its correct position:
pivot < items[l]
6 < 5 is false
l stays at 3
swap items[lo] and items[l]
swap 6 and 5
Current array:
[2, 3, 5, 6, 7, 8]
pivotIndex = l = 3
#### #3.3.3 Arrange elements to the left of pivot `6`, `lo = 2`, `hi = pivotIndex - 1 = 2`
lo = hi, return
Current array:
[2, 3, 5, 6, 7, 8]
#### #3.3.4 Arrange elements to the right of pivot `6`, `lo = pivotIndex + 1 = 4`, `hi = 3`
lo > hi, return
Current array:
[2, 3, 5, 6, 7, 8]
### #3.4 Arrange elements to the right of pivot `7`, `lo = pivotIndex + 1 = 5`, `hi = 5`
lo = hi, return
Current array:
[2, 3, 5, 6, 7, 8]
## Finish
Final sorted array:
[2, 3, 5, 6, 7, 8]
Sorted.

# Quick Sort with Insertion Sort Improvement - Version 1: `[1, 2, 3, 4, 5, 6]`
It is an improved version of quick sort. If the current partition is small enough, it uses insertion sort instead of continuing to recursively partition the array. In this implementation, `THRESHOLD = 5`, and insertion sort is used when `hi - lo < THRESHOLD`. Otherwise, it first uses median-of-three to select the pivot, partitions the array, and recursively sorts the left and right partitions.
Initial array:
[1, 2, 3, 4, 5, 6]
## #1 `quickSort(items, lo, hi)`, `lo = 0`, `hi = 5`
Check whether this partition should be handled by insertion sort:
hi - lo = 5 - 0 = 5
THRESHOLD = 5
5 < 5 is false
Therefore, do not use insertion sort yet. Continue with median-of-three quick sort.
### #1.1 `medianOfThree(items, lo, hi)`, `lo = 0`, `hi = 5`
mid = (lo + hi) / 2 = (0 + 5) / 2 = 2
items[lo] = items[0] = 1
items[mid] = items[2] = 3
items[hi] = items[5] = 6
Arrange the three values so that:
items[mid] <= items[lo] <= items[hi]
Since the median of `1`, `3`, and `6` is `3`, move `3` to `items[lo]` so that it becomes the pivot.
Current array:
[3, 2, 1, 4, 5, 6]
### #1.2 `pivotIndex(items, lo, hi)`, `lo = 0`, `hi = 5`
pivot = items[lo] = 3
l = lo + 1 = 1
r = hi = 5
Current array:
[3, 2, 1, 4, 5, 6]
Scan from the left and right:
items[l] = 2
2 < 3, l++, l = 2
items[l] = 1
1 < 3, l++, l = 3
items[l] = 4
4 < 3 is false
l stays at 3
items[r] = 6
6 > 3, r--, r = 4
items[r] = 5
5 > 3, r--, r = 3
l = r = 3, break loop
Place the pivot into its correct position:
pivot < items[l]
3 < 4, l--, l = 2
swap items[lo] and items[l]
swap 3 and 1
Current array:
[1, 2, 3, 4, 5, 6]
pivotIndex = l = 2
## #2 Arrange elements to the left of pivot `3`, `lo = 0`, `hi = pivotIndex - 1 = 1`
### #2.1 `quickSort(items, lo, hi)`, `lo = 0`, `hi = 1`
Check whether this partition should be handled by insertion sort:
hi - lo = 1 - 0 = 1
THRESHOLD = 5
1 < 5 is true
Therefore, use insertion sort on the subarray from index `0` to index `1`:
[1, 2]
### #2.2 `insertionSort(items, lo, hi)`, `lo = 0`, `hi = 1`
The first element `1` is treated as the sorted part.
Insert the next element:
i = lo + 1 = 1
item = items[i] = 2
j = i = 1
Compare `item` with the previous element:
2 < 1 is false
Therefore, `2` is already in the correct position and no shifting is required.
Current array:
[1, 2, 3, 4, 5, 6]
Insertion sort on the left partition finishes, return.
## #3 Arrange elements to the right of pivot `3`, `lo = pivotIndex + 1 = 3`, `hi = 5`
### #3.1 `quickSort(items, lo, hi)`, `lo = 3`, `hi = 5`
Check whether this partition should be handled by insertion sort:
hi - lo = 5 - 3 = 2
THRESHOLD = 5
2 < 5 is true
Therefore, use insertion sort on the subarray from index `3` to index `5`:
[4, 5, 6]
### #3.2 `insertionSort(items, lo, hi)`, `lo = 3`, `hi = 5`
The first element `4` is treated as the sorted part.
Insert the next element:
i = lo + 1 = 4
item = items[i] = 5
j = i = 4
Compare `item` with the previous element:
5 < 4 is false
Therefore, `5` is already in the correct position and no shifting is required.
Current array:
[1, 2, 3, 4, 5, 6]
Insert the next element:
i = 5
item = items[i] = 6
j = i = 5
Compare `item` with the previous element:
6 < 5 is false
Therefore, `6` is already in the correct position and no shifting is required.
Current array:
[1, 2, 3, 4, 5, 6]
Insertion sort on the right partition finishes, return.
## Finish
Final sorted array:
[1, 2, 3, 4, 5, 6]
Sorted

## Radix Sort: [329, 457, 657, 839, 436, 720, 355]
radix, digits, key, bucket, padding
Radix sort is a non-comparison based algorithm, decompose each element into individual value, and apply stable sort 

Array: [329, 457, 657, 839, 436, 720, 355]
#1 For the last digit
bucket: 
        9     7     6     0     5
       329   457   436   720   355
       839   657   
Rearrange with numeric order
Array: [720, 355, 436, 457, 657, 329, 839]

#2 For the second last digit
bucket:
        2     5     3
       720   355   436
       329   457   839
             657
Rearrange with numeric order
Array: [720, 329, 436, 839, 355, 457, 657]

#3 For the first digit
bucket:
        7     3     4     8     6
       720   329   436   839   657
             355   457
Rearrange with numeric order
Array: [329, 355, 436, 457, 657, 720, 839]
Sorted

Q5
Done

Q6
Done

Q7
[Check pseudocode](./sortAlgPseudocode.md)

Q8
[Check src](./sortAlgImplementation.c)

Q9
Done

Q10
Done

Q11
Done

Q13
## Space complexity
- Selection, bubble, insertion => O(1)
- Merge (include bottom-up) => O(n)
- Quick (any) sort => O(logn) on best and average, worst on O(n)
- Radix sort => O(R + n) 
