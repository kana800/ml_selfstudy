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
   
   [c codes](codes/treeds.c)
   
9. > A *concatenate* operation takes two sets `S1` and `S2`, where every key in `S1` in smaller than any key in `S2`, and merges them together. Give an algorithm to concatenate two binary search trees into one binary search tree. The worst-case running should be `O(h)`, where *h* is the maximal height  of the two trees.

   Since all the elements in set `s1` is smaller than element in set `s2`. we attach the set `s2` to the minimum element of the set `s1`'s left sub-tree.

   [c codes](codes/question_9.c)

10. > In the *bin-packing problem*, we are given *n* metal objects, each weighing between zero and one kilogram.  Our goal is to find the smallest number of bins that will hold  *n* objects, with each bin holding one kilogram at most.

    - > Design an algorithm that implements the best-fit heuristic in `O(n log n)` time.

      find the fullest bin the current object metal will fit into, hence minimising the amount of wasted space. If the object fit any bin, create a new bin if there isnt any space. 

      [c codes](codes/binpackagingprob.c)

    - > Implement the worst-fit heuristic, where we put the next object in the partially filled bin with the largest amount of extra room after the object is inserted.

      We will be finding the right-most child if we are implementing the worst case scenario

11. > Suppose that we are given a sequence of `n` values `x1,x2, .. xn` and seek to quickly answer repeated queries of the form: given *i* and *j*, find the smallest value.w

    - > Design a data structure that uses  `O(n^2)` space and answers queries in `O(1)` time 

      Add the elements to a list

    - > Design a data structure that uses `O(n)` space and answers queries in `O(log n)` time.

      Add all the elements to the binary search tree, given the pair of integers, we can find the lowest common ancestor of `xi` and `xj`.

12. > Suppose you are given an input set *S* of *n* numbers, and a black box that if given any sequence of real numbers an integer *k* instantly and correctly answers whether there is a subset of input sequence whose sum is exactly *k*. Show how to use the black box *O(n)* times to find a subset of *S* that adds up to *k*. 

13. > Let A[1...n] be an array of real numbers. Design an algorithm to perform any sequence of the following operations.

    [c code](codes/question_13.c)

14. > Extend the data structure of the previous problem to support insertions and deletions, Each element now has both a key and a value. An element is accessed by its key. The addition operation is applied to the values, but the elements are accessed by its key. The `Partial_sum` operation is different.

    [c code](codes/question_15.c)
15. > Design a data structure that allows one to search, insert, and delete an integer `X` in `O(1)` time

    We will have two arrays `A` & `B`, `A` will store the location of the *counts* of the *data* while `B` will store the counts of the *data*. :exclamation:`B` will store a tuple `(data, count)`
    
    Search -> Assume we are searching for value 3, we will go the 3rd index of A (which stores the index to the counts) and we will to B array and check if the `data` in tuple gives us a *data we are searching for*, if yes, we will return True. If not we will return False. 
    
    Insert -> Assume we are inserting 3 and its already present in the array, we will search for the value that need to be inserted, if the value if True, this means the value is present so we will increment the `count` data in the tuple, if not present, we will create a tuple and assign the value that need to be inserted as data and count to be 1.
    
    Delete -> We check if the value is present using `Search` if present, we will assign `NULL`  to the location of A and remove the value from `B`

#### Implementation Projects 

16. > Implement versions of several different dictionary data structures, such as linked list, binary trees, balanced binary search trees, and hash tables. Conduct experiments to assess the relative performance of these data structures in a simple application that reads a large text file and reports exactly one instance of each word that appears within it. The application can be efficiently implemented by maintaining a dictionary of all the distinct words that have appeared thus far in the text and inserting/reporting each word that is not found. 

    codes for:

    - [Linked List](codes/single_linked_list.c)

      if a singly linked list is used, where in each node a word is stored. To Insert a node we need first check if the word is already present in the linked list to check this (`isPresent`) we need to iterate through the list and compare each word. Which makes the *Insertion* to have `O(n)` time complexity. For Deletion we again need to iterate through the array, we will get `O(n)` time complexity.
    
    - Binary tree
    
      Again in each node, we will be storing the word. Maybe we can try something like the **Trie** data structure. For insertion again we need to iterate through the tree to check if the word is present, if not we need to insert the word to the tree, we can decide whether to go the left or right using the first letter, get the ASCII value of the first letter and check it against the root node. 
    
17. > A Caesar shit is a very simple class of ciphers for secret messages. Unfortunately, they can be broken using statistical properties of English. Develop a program capable of decrypting Caesar shifts of sufficiently long texts

    Thinking Process

    We can perform a decryption using a simple mathematical expression, ![](https://latex.codecogs.com/png.latex?%5Cinline%20D_%7Bn%7D%28x%29%20%3D%20%28x%20-%20n%29%20%5Ctextup%7Bmod%7D%2026), And we need to substitute each letter to get the decrypted letter back, we need to figure out a way to store the encrypted words, we cant simply plug them into the **binary tree**, we can but words will get jumbled (order of the words will be different because we are comparing the letters with the root node) , If the order of the words doesn't matter, we can use the simply balanced binary tree and  decrypt the words accordingly.

#### Interview Problems

18. > What method would you use to look up a word in a dictionary

    We can use a Binary Search, which would take `O(log n)`  time, assuming the words are in order, we can use **divide and conquer** algorithm and jump through the dictionary pretty easily. The best option would be store all the word in a Trie data structure, where leaf nodes of the tree lead to the correct word. This is would take a lot time but it would be pretty fast.

19. > Imagine you have a closet full of shirts. What can you do to organize your shirts for easy retrieval

    We can organize them by color or size and do a binary search.

20. > Write a function to find the middle node of a singly-linked list.

    Assuming the length of the list is given.

    ```c
    struct node * getmiddlenode( int length){
        struct node * tempnode = head;
        int counter = 0;
        // iterating till the middle node from the head.
        while ((tempnode != NULL) || counter < length){
            tempnode = tempnode->ptr;
            counter++;
        }
        return tempnode;
    }
    ```

21. > Write a function to compare whether two binary trees are identical. Identical trees have same key value at each position and the same structure.

    we can check if the:
    
    - **Heights** of the trees are same
    - Number of **Leaf Nodes** are same
    
    Next option would be iterate through both of binary trees and check if the values are same, we can have two pointers traversing through the binary tree.  
    
    [binary_tree_comparison](codes/binary_tree_comparison.c)
    
22. > Write a program to convert a binary search tree into a linked list.

    ```c
    int * iterateTree(struct node * root){
        if (root == NULL){
            return;
        }else {
            iterateTree(root->leftptr);
    		createlinkednode(root);
            iterateTree(root->rightptr);
        }
    }
    ```

23. > Implement an algorithm to a reverse a linked list. Now do it without recursion

    [reverse_linked_list](codes/single_linked_list.c)

24. > What is the best data structure for maintaining URLs that have been visited by a Web crawler? Give an algorithm to test whether a given URL has already been visited, optimizing both space and time.

    We can simply save the URLs in an **Array**,  Traversing the array would take a lot of time with the increase of URLs, we can create a dictionary and use linked list as a data structure or a hash table. 
    
25. > You are given a search string and a magazine. You seek to generate all the characters in search string by cutting them out from the magazine. Give an algorithm to efficiently determine whether the magazine contains all the letters in the search string.

    First we can add each word in a **Trie** data structure (*Maybe we can have, binary tree inside binary tree*) :smile:. 

26. > Reverse the words in a sentence `My name is chris` becomes `chris is name my`. Optimize for time and space.

    [reverse the single linked list](codes/single_linked_list.c)

27. > Determine whether a linked list contains a loop as quickly as possible without using any extra storage. Also, identify the location of the loop.

    Have two pointers (both at the head), move *pointer 1* to one link and move *pointer 2* to two links, if they are in the same position we have loop, if not iterate till you find the location of the loop.

28. > You have an unordered array *X* of *n* integers. Find the array *M* containing *n* elements where *Mi*, is the product of all integers in *X* except for *Xi*. You may not use division. You can use extra memory. 

    [question_28](codes/question_28.c)

29. > Give an algorithm for finding an ordered word pair (e.g., "New York") occurring with the greatest frequency in a given web page. Which data structures would you? Optimize both time and space.

    We can have **Trie** and `struct`  of the tree would contain the word, frequency and the pointers.

    ```c
    struct node {
    	char wordset[20];
    	int frequency;
    	struct node *leftptr;
    	struct node *rightptr;
    };
    ```

    while iterating through the document, if we encounter a word that is already in the **Trie** data structure, we can increment the frequency.