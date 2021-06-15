#### Problem of the Day : Lecture 7

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

##### Heap / Priority Queue

When implementing  a sorting algorithm, the data structure matters. Using array or unsorted linked list as the data structure, for **Task A** it would cost `O(n)` time and **Task B** would cost `O(n^2)` time. Using balanced search tree, **Task A**  and **Task B** would take `O(log n)` time. For an `O(n log n)` selection sort is called as **heap sort**

*Key point is **data structure** matters*

> **If you algorithm needs to repeatedly take in the minimum, maximum, etc.. we can use a priority queue.**

*Heap* is binary tree with a key in each node and an example of **priority queue**.

- All leaves are on, at most, two adjacent levels
- All leaves on the lowest level occur to the left, and all levels except the lowest one are completely filled.
- The key in the root is less than or equal to all its children, and the left and right subtrees are again binary heaps.

[Because of the way we enter the data into the binary tree, we can represent the data in the binary tree in an array without any pointers](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif).

**can we represent any binary tree in an array?** : unless the binary trees are perfectly balanced it will be wasteful to represent binary tree as an array.

#### Problem of the Day : Lecture 8

> Given an efficient algorithm to determine whether two sets of (size *m* and *n*) are disjoint, Analyze the complexity of your algorithms in terms of *m* and *n*. Be sure to consider the case where *m* is substantially smaller than *n*.

Array A has *n* elements and Array B has *m* elements (n > m). We can sort the array A (smaller array) and loop through the larger array while doing a binary search for the elements inside the array B.

````pseudocode
sort A
for i = 1 to M
	binarysearch(B[i], A)
````

- `sort A` takes `m log n`
- `for i = 1 to M binarysearch(B[i], A)` takes `n log m`
- Expected time `(n+m)log m`, Big Oh `O(n lof m)`

##### Merge Sorting

Algorithm is based on **divide and conquer**, which means breaking down the larger project into a smaller project. 

###### [Merge-sort Analysis](https://youtu.be/jUf-UQ3a0kg?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=1571)

Whenever there is a recursion we need to look at the recursion tree, A linear amount of work is done merging alone all levels of the merge-sort tree.

The height of this tree is `O(log n)`. Thus the worst case time is `O(n log n)`. 

> Why is the height of this tree `O(log n)` ?

What happens in merge sort is we take a large number and break it down until we to two pairs, so the time take to reduce n elements to 1 is `O(log n)`.

> Number of nodes in this tree ? 

We will have `2n`, because the number of nodes doubles every layer, where we have `n` leaves.

##### Quick Sort

Quick sort break down the problem into two smaller problems just like merge sort but they way it does is different, the algorithm selections a randomized pivot point and then all the values less than the pivot is moved to the left and all the values greater than the pivot is moved to the right and [put the pivot element between the left and right elements.](https://youtu.be/jUf-UQ3a0kg?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=2512)

#### Problem of the Day: Lecture 9

> The nuts and bolts problem is defined as follows. You are given a collection of *n* bolts of different widths, and *n* corresponding nuts. You can test whether a given nut and bolt together, from which you learn whether the nut is too larger, too small, or an exact math for the bolt. The differences in size between pair of nuts or bolts can be small to see by eye, so you can rely on comparing the sizes of two nuts or two bolts directly. You are to match each bolt to each nut.
>
> 1. Give an `O(n^2)` algorithm to solve the nuts and bolts problem
> 2. Suppose that instead of matching all of the nuts and bolts, you wish to find the smallest bolt and its corresponding nut. Show that this can be done in only `2n -2 ` comparisons
> 3. Match the nuts and bolts in expected `O(n log n)` time.

1. Assuming for each nuts there is a specific bolt

   ```pseudocode
   for n in 1 to numberofnuts:
   	for b in 1 to bolts:
   		if nutfitwithbolt(n[i],b[i]):
   			match(n[i],b[i])
   		else
   			pass
   ```

   [answers to other questions](https://youtu.be/0ksyQKmre84?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=606)

##### Lower Bounds of Sorting

> Is there a faster algorithm than `O(n log n)` ?  

NO
> How do we know that there are no algorithms better than `O(n log n)` ?

Sorting Algorithms like (Insertion Sort, Quick Sort, Merge Sort) are comparing algorithms, each algorithm compare two elements and change the position of the elements if needed. If we use [tree data structure](https://youtu.be/0ksyQKmre84?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=1083), the worst case of sorting algorithm will be the height of the tree (`O(h)`).  [Math Behind This](https://youtu.be/0ksyQKmre84?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=1387)

##### Non-Comparison-Based Sorting : Bucket Sort

> suppose we are sorting [*n* numbers](https://youtu.be/0ksyQKmre84?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=2304) from 1 to *m*, where we know the numbers are approximately uniformly distributed. We can set up *n* buckets, each responsible for an interval of `m/n` numbers from 1 to *m*.

We *hash* elements in the list, and allocate them in buckets according to its numerical hashing value, for example `2` *hashed* by `m/n (3/2)` would give us `3` , which would go the bucket that hold the value `3`. Here we are assuming that the numbers are uniformly distributed, if there is skew in the list we are going to get all the numbers into one bucket ([worst case scenario](https://youtu.be/0ksyQKmre84?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=2669)). 

*we want algorithms that performs best at the worst case because we don't want any algorithm to slow down because of weird distributions.*
