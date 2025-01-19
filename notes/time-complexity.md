# Big O notation

## Linear Time Complexity O(n)

### How to identify
* Operations that grow proportionally to the input size
* As n get's bigger, the function runs n more times

### Real-World Examples
* Traversing a list or array.
* Summing up all elements in a data structure.
* Linearly searching for an element in an unsorted array.

```c
int sum_array(int arr[], int n) {
    int sum = 0;
    int i = 0;
    while (i < n) {
        sum += arr[i++];
    }
    return sum;
}
```

### Space Complexity
- O(1): Constant space is used, as no additional data structures are required.

## Quadratic Time Complexity O(n^2)

### How to identify
* Operations where a loop runs inside another loop

### Real-World Examples
* Generating all pairs from a list of elements.
* Comparing every element with every other element (e.g., bubble sort).
* Matrix multiplication.

```c
void printPairs(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}
```

### Space Complexity
- O(1): Constant space is used, as no additional data structures are required.

## Logarithmic Time Complexity O(log n)

### How to identify
* Operations where the input size is halved each time
* Recursive divisions of the input into smaller sections.

### Real-World Examples
* Binary search in a sorted array.
* Finding the height of a balanced binary tree.
* Checking if a number is a power of two.

```c
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Space Complexity
- Iterative: O(1), constant space.
- Recursive: O(log n), as each recursive call adds a stack frame.

## Linearithmic Time Complexity

### How to identify
* Combines linear and logarithmic steps, typically seen in divide-and-conquer algorithms.

### Real-World Examples
* Merge sort and quicksort (in the average case).
* Heap sort.
* Constructing a balanced binary search tree from sorted data.

```c
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```

### Space Complexity
- Merge Sort: O(n) for the temporary arrays used in merging.
- Quick Sort: O(log n) for the recursive stack in the average case.

---

## Additional Notes
- **Understanding Big-O**:
  - Focuses on the worst-case scenario to provide an upper bound on the runtime.
  - Helps compare algorithms independently of hardware or programming language.
- **Other Common Complexities**:
  - O(1): Constant time, e.g., accessing an array element.
  - O(2^n): Exponential time, e.g., solving the Tower of Hanoi.
  - O(n!): Factorial time, e.g., solving the traveling salesman problem using brute force.
