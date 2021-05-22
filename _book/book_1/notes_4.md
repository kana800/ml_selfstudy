#### Problem of the Day

[link](https://youtu.be/VTxEAMHtZsc?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=1154)

#### Sorting

##### Selection Sort

Selection sort scans through out the entire array, repeatedly finding the smallest remaining element

```pseudocode
for i = 1 to n
A: Find the smallest of the first n - i + 1 items
B: Pull it out of the array and put it first
```

Selection sort takes `O(n(T(A) + T(B)))` time.

When implementing  a sorting algorithm, the data structure matters. Using array or unsorted linked list as the data structure, for **Task A** it would cost `O(n)` time and **Task B** would cost `O(n^2)` time. Using balanced search tree, **Task A**  and **Task B ** would take `O(log n)` time. For an `O(n log n)` selection sort is called as **heap sort**

*Key point is **data structure** matters*

> **If you algorithm needs to repeatedly take in the minimum, maximum, etc.. we can use a priority queue.**
>
#### Heap

*Heap* is binary tree with a key in each node.

- All leaves are on, at most, two adjacent levels
- All leaves on the lowest level occur to the left, and all levels except the lowest one are completely filled.
- The key in the root is less than or equal to all its children, and the left and right subtrees are again binary heaps.

[Because of the way we enter the data into the binary tree, we can represent the data in the binary tree in an array without any pointers](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif).

**can we represent any binary tree in an array?** : unless the binary trees are perfectly balanced it will be wasteful to represent binary tree as an array.