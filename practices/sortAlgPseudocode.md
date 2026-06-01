# Sorting algorithm pseudocode

## Selection Sort
selectionSort(items[], lo, hi) 
input: array items, indices lo and hi
output: void
        for i = lo up to hi - 1:
                minIndex = i
                for j = i + 1 up to h:
                        if (items[minIndex] > items[j])
                        minIndex = j

                swap(items, i, minIndex)

## Bubble Sort
bubbleSort(items[], lo, hi) 
input: array item, indices lo and hi
output: void
        for r from hi to lo - 1:
                swap = 0
                        for i from lo + 1 to r:
                                if items[i] < items[i - 1]
                                swap(items, i, i - 1)
                                swap++
                if swap = 0, break

## Insertion Sort
insertionSort(items[], lo, hi)      
input: array item, indices lo and hi  
output: void
        for i from lo + 1 to hi: ==>> increase size of sorted array, i = array size
                for j from i to lo:
                        if (items[j] < items[j - 1]) swap
                        else break

## Top-down Merge Sort
merge(items[], lo, hi)
input: array item, indices lo and hi  
output: void
        temp = malloc(sizeof(int) * (hi - lo))
        mid = (lo + hi) / 2
        i = lo, j = mid + 1, k = 0

        while i <= mid and j <= hi:
                if items[i] <= items[j]
                temp[k++] = items[i++]
                else
                temp[k++] = items[j++]

        while i <= mid: temp[k++] = items[i++]
        while j <= hi: temp[k++] = items[j++]

        for i from lo to hi and k from 0 to hi:
                items[i] = temp[k]

        free(temp)



mergeSort(items[], lo, hi)
input: array item, indices lo and hi  
output: void
        if (lo >= hi) return
        mid = (lo + hi) / 2
        mergeSort(items, lo, mid)
        mergeSort(items, mid + 1, hi)
        merge(items, lo, hi)


## Bottom-up Merge Sort
bottomUpMergeSort(items[], lo, hi)
input: array item, indices lo and hi  
output: void
for m from 1 up to hi - lo, m *= 2:
        for i from lo up to hi - m, i += m * 2
                end = min(i + 2 * m - 1, hi)
                merge(items, i, i + m - 1, end)
                

## Naive Quick Sort
partition(items[], lo, hi)
input: array item, indices lo and hi  
output: integer l
        pivot = items[lo]
        l = lo + 1, r = hi;

        while l < r:
                while l < r and items[l] <= pivot, l++
                while l < r and items[r] >= pivot, r--

                if l = r, break
                swap(items, l, r)

        if pivot < items[l], l--
        swap(items, lo, l)
        return l

naiveQuickSort(items[], lo, hi)
input: array item, indices lo and hi  
output: void
if lo >= hi, return

pivotIndex = partition(items, lo, hi)
naiveQuickSort(items, lo, pivotIndex - 1)
naiveQuickSort(items, pivotIndex + 1, hi)


## Median-of-Three Quick Sort
medianOfThreeQuickSort(items, lo, hi):
input: array item, indices lo and hi  
output: void
        if lo >= hi, return
        medianOfThree(items, lo, hi)
        pivotIndex = partition(items, lo, hi)

        medianOfThreeQuickSort(items, lo, pivotIndex - 1)
        medianOfThreeQuickSort(items, pivotIndex + 1, hi)

medianOfThree(items, lo, hi)
input: array item, indices lo and hi  
output: void
mid = (lo + hi) / 2

if items[mid] > items[lo] swap(items, lo, mid)
if items[lo] > items[hi] swap(items, lo, hi)
if items[mid] > items[lo] swap(items, lo, mid)
// mid => min => max


## Randomised Quick Sort
randomisedQuickSort(items, lo, hi)
input: array item, indices lo and hi  
output: void
        if lo >= hi, return
        randomPivot(items, lo, hi)
        pivotIndex = partition(items, lo, hi)

        randomisedQuickSort(items, lo, pivotIndex - 1)
        randomisedQuickSort(items, pivotIndex + 1, hi)

randomPivot(items, lo, hi)
input: array item, indices lo and hi  
output: void

int rand = rand() % (hi - lo +1) + lo
swap(items, lo, rand)

## Insertion Quick Sort
insertionQuickSort(items, lo, hi)
input: array item, indices lo and hi  
output: void
        if (hi - lo) < thershold:
                insertionSort(items, lo, hi)
                return
        medianOfThree(items, lo, hi)
        pivotIndex = partition(items, lo, hi)

        insertionQuickSort(items, lo, pivotIndex - 1)
        insertionQuickSort(items, pivotIndex + 1, hi)


## Radix sort (numeric)
radixSort(items, lo, hi)
input: array item, indices lo and hi  
output: void

        initialise bucket with correspond radix
        for each key of the element:
        empty bucket
                for each key in items:
                        append key into corresponded bucket[i]
                clear items[]
                for each key in bucket:
                append bucket[i] into items[]

