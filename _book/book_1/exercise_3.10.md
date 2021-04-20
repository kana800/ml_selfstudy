### 3.10 Exercise
#### Stacks, Queues, and Lists

1. Find if the parentheses are properly balanced.
   - [c solution](codes/balanced_paranthesis.c)
   - [python solution](codes/balanced_paranthesis.py)
2. Reverse Singly Linked List 
   
   - [c solution](codes/single_linked_list.c)
   
3. > We have seen how dynamic arrays enable arrays to grow while still achieving constant-time amortized performance. This problem concerns extending dynamic arrays to let them both grow and shrink on demand.
   >
   > (a) Consider an underflow strategy that cuts the array size in half whenever the array falls below half full. Give an example sequence of insertions and deletions where this strategy gives a bad amortized cost.
   >
   > (b) Then, give a better underflow strategy than that suggested above, one that achieves constant amortized cost per deletion.

   - Array of Size 6, with 3 elements, insertions and deletions, will expand and shrink the array.
   - When array is `1/4`th full, half its size (shrink).

#### Trees and Other Dictionary Structures

4. > Design a dictionary data structure in which search, insertion, and deletion can all be processed in `O(1)` time in worst case. You may assume the set elements are integers drawn from finite set `1,2,...,n` and initialization can take `O(n)` time.

   we can use a bit array because `1,2,..n` is a finite amount. [more info](https://www.youtube.com/watch?v=Ub1fE-bAroA)

5. > Find the overhead fraction (the ratio of data space over total space) for each of the following binary tree implementation on *n* nodes:

   - > All nodes store data, two child pointer, and a parent pointer. The data field requires four bytes and each pointer requires four bytes.

     ```
     DataSpace = 4 bytes
     TotalSpace = 4 + 4(2 + 1) = 18 bytes
     
     overhead fraction = 1/4
     ```

   - > Only lead nodes store data; internal nodes store two child pointers. The data field requires four bytes and each pointer requires two bytes.

     Assuming the number of leaf nodes in a tree is `N`, `(n - N)`  internal nodes. Therefore, `totalspace` is going to be `4*(n-N) + 4*N`. 

     ```
     overhead fraction = 4N/4(n-N)
     ```

6. > Describe how to modify an balanced tree data structure such that search, insert, delete, minimum and maximum still take `O(log n)` time each, but successor and predecessor now take `O(1)` time each. Which operations have to be modified to support this.

   Add successor and predecessor pointers to the tree nodes. This wont affect search, minimum and maximum. The insert operation will *increase* because we need to insert the successor and predecessor pointers to the nodes. 

7. > Suppose you have access to a balanced dictionary data structure, which supports each of the operations search, insert, delete, minimum, maximum, successor, and predecessor in `O(log n)` time. Explain how to modify the insert and delete operations so they still take `O(log n)` but now minimum and maximum take `O(1)` time. 

   store minimum and maximum as global variables, when inserting number comparing it with minimum and maximum and update accordingly, when deleting check if the minimum or maximum is deleted and update minimum or maximum.

8. > Design a data structure to support the following operations:
   >
   > - insert(x, T) - Insert item x into the set T
   > - delete(k,T) - Delete the kth smallest element from T
   > - member(x,T) - Return true iff x is element of T

   All the operations must take `O(log n)` time on an n-element set. If we want to insert *item x* to *set T*, we need to make sure the data structure is in the sorted order. 
   
   [c codes](codes/question_8.c)
   
9. > A *concatenate* operation takes two sets `S1` and `S2`, where every key in `S1` in smaller than any key in `S2`, and merges them together. Give an algorithm to concatenate two binary search trees into one binary search tree. The worst-case running should be `O(h)`, where *h* is the maximal height  of the two trees.

   Since all the elements in set `s1` is smaller than element in set `s2`. we attach the set `s2` to the minimum element of the set `s1`'s left sub-tree.

   [c codes](codes/question_9.c)

10. > In the *bin-packing problem*, we are given *n* metal objects, each weighing between zero and one kilogram.  Our goal is to find the smallest number of bins that will hold  *n* objects, with each bin holding one kilogram at most.