#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ITEMS 1000

typedef int Item;

/* =========================================================
   Sorting algorithm declarations
   ========================================================= */

void selectionSort(Item items[], int lo, int hi);
void bubbleSort(Item items[], int lo, int hi);
void insertionSort(Item items[], int lo, int hi);

void mergeSort(Item items[], int lo, int hi);
void bottomUpMergeSort(Item items[], int lo, int hi);

void naiveQuickSort(Item items[], int lo, int hi);
void medianOfThreeQuickSort(Item items[], int lo, int hi);
void randomisedQuickSort(Item items[], int lo, int hi);

void insertionQuickSortV1(Item items[], int lo, int hi);
void insertionQuickSortV2(Item items[], int lo, int hi);

void radixSort(Item items[], int lo, int hi);

/* =========================================================
   Program input / output
   Not part of sorting algorithm practice
   ========================================================= */

void readArray(Item items[], int n) {
    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &items[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printArray(Item items[], int n) {
    printf("[");

    for (int i = 0; i < n; i++) {
        printf("%d", items[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

void printMenu(void) {
    printf("\nChoose a sorting algorithm:\n");
    printf(" 1. Selection Sort\n");
    printf(" 2. Bubble Sort\n");
    printf(" 3. Insertion Sort\n");
    printf(" 4. Top-down Merge Sort\n");
    printf(" 5. Bottom-up Merge Sort\n");
    printf(" 6. Naive Quick Sort\n");
    printf(" 7. Median-of-three Quick Sort\n");
    printf(" 8. Randomised Quick Sort\n");
    printf(" 9. Insertion-Quick-Sort Version 1\n");
    printf("10. Insertion-Quick-Sort Version 2\n");
    printf("11. Radix Sort\n");
    printf("Choice: ");
}

void runSort(int choice, Item items[], int n) {
    int lo = 0;
    int hi = n - 1;

    switch (choice) {
        case 1:
            selectionSort(items, lo, hi);
            break;
        case 2:
            bubbleSort(items, lo, hi);
            break;
        case 3:
            insertionSort(items, lo, hi);
            break;
        case 4:
            mergeSort(items, lo, hi);
            break;
        case 5:
            bottomUpMergeSort(items, lo, hi);
            break;
        case 6:
            naiveQuickSort(items, lo, hi);
            break;
        case 7:
            medianOfThreeQuickSort(items, lo, hi);
            break;
        case 8:
            randomisedQuickSort(items, lo, hi);
            break;
        case 9:
            insertionQuickSortV1(items, lo, hi);
            break;
        case 10:
            insertionQuickSortV2(items, lo, hi);
            break;
        case 11:
            radixSort(items, lo, hi);
            break;
        default:
            fprintf(stderr, "Invalid algorithm choice.\n");
            exit(EXIT_FAILURE);
    }
}

int main(void) {
    Item items[MAX_ITEMS];
    int n;
    int choice;

    srand((unsigned int) time(NULL));

    printf("Number of items: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_ITEMS) {
        fprintf(stderr, "Number of items must be between 1 and %d.\n",
                MAX_ITEMS);
        return EXIT_FAILURE;
    }

    readArray(items, n);

    printf("\nOriginal array: ");
    printArray(items, n);

    printMenu();

    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid choice.\n");
        return EXIT_FAILURE;
    }

    runSort(choice, items, n);

    printf("\nSorted array:   ");
    printArray(items, n);

    return EXIT_SUCCESS;
}

/* =========================================================
   Add your own sorting helper declarations / implementations
   wherever you decide they are needed.
   ========================================================= */
void swap(Item items[], int i, int j) {
    int temp = items[j];

    items[j] = items[i];
    items[i] = temp;
}

void merge(Item items[], int lo, int mid, int hi) {
    Item *temp = malloc(sizeof(Item) * (hi - lo + 1)); // Create temporary array for merging
    int i = lo, j = mid + 1, k = 0;                    // i is the index for iterate left subarray
                                                       // j is the index for iterate right subarray
                                                       // k is the index for iterate temp array

    while (i <= mid && j <= hi) {                      // Merging them together
        if (items[i] <= items[j]) {
            temp[k++] = items[i++];
        } else {
            temp[k++] = items[j++];
        }
    }

    while (i <= mid) temp[k++] = items[i++];           // Two while loops to continue insert the remaining element
    while (j <= hi) temp[k++] = items[j++];

    for (int i = lo, k = 0; i <= hi; i++, k++) {       // Replacing the array with temprorary array
        items[i] = temp[k];
    }

    free(temp);                                        // Free the temp array
}

int min (int i, int j) {
    if (i <= j) return i;
    else return j;
}

int partition(Item items[], int lo, int hi) {   
    int pivot = items[lo];                      // Set the first element as pivot
    int l = lo + 1, r = hi;                     // Set up boundary for finding pivot index

    while(l < r) {
        while (l < r && items[l] <= pivot) l++; // Increase l until items[l] is larger than pivot
        while (l < r && items[r] >= pivot) r--; // Decrease r until items[r] is smaller than pivot
        
        if (l == r) break;                      // If l and r equals after shifting, means they're around pivot position,
        swap(items, l, r);                      // If not, swap items[l] and items[r] where items[l] is larger should
                                                // go to the right, items[r] is smaller should go the the left
    }

    if (pivot < items[l]) l--;                  // If item[l] is greater than pivot, pivot should set before this element, so l--
    swap(items, lo, l);                         // Place the pivot into correct position by swapping 
    return l;                                   // Return l, which is pivotIndex
}

void medianOfThree(Item items[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if (items[mid] > items[lo]) swap(items, mid, lo);
    if (items[lo] > items[hi]) swap(items, lo, hi);
    if (items[mid] > items[lo]) swap(items, mid, lo);
    // mid => sml => lar
}

/* =========================================================
   Your sorting algorithm implementations
   ========================================================= */

void selectionSort(Item items[], int lo, int hi) {
    for (int i = lo; i < hi; i++) {                       // i is the position that placed the 1st/2nd/3rd...n smallest into
                                                          // 1st/2nd/3rd....n places
        int minIndex = i;                                 // select the current i as minIndex
        for (int j = i + 1; j <= hi; j++) {               // if j < hi only, it misses the last element
            if (items[minIndex] > items[j]) minIndex = j; // comparing from i to hi to find 
                                                          // the smallest value
        }

        swap(items, i, minIndex);                         // swap the value between items[minIndex] and items[i]
    }
}

void bubbleSort(Item items[], int lo, int hi) {
    for (int r = hi; r > lo; r--) {          // Decrease the upper boundary since each iteration gurantee the 
                                             // last number is in the right place
        bool swapped = false;                // For implement early stop
        for (int i = lo + 1; i <= r; i++) {  // Iterate the array for comparison, from lo to each 
                                             // upper boundary
            if (items[i] < items[i - 1]) {   // Compare adjacent element
                swap(items, i, i - 1);
                swapped = true;
            }
        }
        if (!swapped) break;                 // If no swapping happened, means the array is sorted, stops early
    }
}

void insertionSort(Item items[], int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {    // Increase the size of sorted arr, i = arr size
        for (int j = i; j > lo; j--) {      // For insert new element and place at correct position
            if (items[j] < items[j - 1]) {
                swap(items, j, j - 1);
            } else break;
        }
    }
}

void mergeSort(Item items[], int lo, int hi) {
    if (lo >= hi) return;           // base case, return when there's only one or no element

    int mid = (lo + hi) / 2;        // The position for splitting array

    mergeSort(items, lo, mid);      // Sort the left subarray recursively
    mergeSort(items, mid + 1, hi);  // Sort the right subarray recursively
    merge(items, lo, mid, hi);           // Merge left and right subarray
}

void bottomUpMergeSort(Item items[], int lo, int hi) {
    for (int m = 1; m <= hi - lo;  m *= 2) {
        for (int i = lo; i <= hi - m; i += m * 2) {
            int end = min(i + m * 2 - 1, hi);
            merge(items, i, i + m - 1, end);
        }
    }
}

void naiveQuickSort(Item items[], int lo, int hi) {
    if (lo >= hi) return;                       // Base case where hi accross lo

    int pivotIndex = partition(items, lo, hi);  // Access the value of pivot index
    naiveQuickSort(items, lo, pivotIndex - 1);  // Recursively arrange the element to the left so they're smaller or equal to pivot
    naiveQuickSort(items, pivotIndex + 1, hi);  // Recursively arrange the element to the right so they're larger or equal to pivot
}

void medianOfThreeQuickSort(Item items[], int lo, int hi) {
    if (lo >= hi) return;
    medianOfThree(items, lo, hi);

    int pivotIndex = partition(items, lo, hi);
    medianOfThreeQuickSort(items, lo, pivotIndex - 1);
    medianOfThreeQuickSort(items, pivotIndex + 1, hi);
}

void randomisedQuickSort(Item items[], int lo, int hi) {

}

void insertionQuickSortV1(Item items[], int lo, int hi) {

}

void insertionQuickSortV2(Item items[], int lo, int hi) {

}

void radixSort(Item items[], int lo, int hi) {

}

