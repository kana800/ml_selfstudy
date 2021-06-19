#### Applications of Sorting

1. > The Grinch is given the job of partitioning `2n` players into two teams of `n` players each. Each play has a numerical rating that measures how good he/she is at the game. He seeks to divide the players as *unfairly* as possible, so as to create the biggest possible talent imbalance between team *A* and team *B*. Show  how the Grinch can do the job in `O(n log n)` time.

   We can use merge sort to arrange the main array (*array with `2n` players*) in ascending order, an split the main array into two equal sets.


2. > For each of the following problems, given an algorithm that finds the desired numbers within the given amount of time. To keep your answers brief, feel free to use algorithms from the book as subroutines. For the example, `S = {6,13,19,3,8}`, `19 - 3 ` is the maximum difference while `8-6` minimizes the difference.

   - > Let *S* be an *unsorted* array of *n* integers. Give an algorithm that finds the pair ![](https://latex.codecogs.com/png.latex?%5Cinline%20x%2Cy%20%5Cin%20S) that maximizes `|x - y|`. Your algorithm must run in `O(n)` worst-case time.
   
     The highest value subtracted from the lowest value will give us the maximum difference (`|x - y|`), we can iterate through the array and compare each element with the previous elements to determine the maximum and minimum
   
     ```c
     int s[] = {6,13,19,3,8}
     int max = s[0];
     int min = s[0];
     
     for (int i = 1; i < sizeof(s)/sizeof(s[0]); i++){
         // comparing max, with the val in the array
         if (s[i] > max){
     		max = s[i];
         } else if (s[i] < min){
             min = s[i];
         }
     }
     ```
   
     [demo in c](codes/exercise_4.11.2a.c)
   
   - > Let *S* be a *sorted* array of *n* integers. Give an algorithm that finds the pair ![](https://latex.codecogs.com/png.latex?%5Cinline%20x%2Cy%20%5Cin%20S)that maximizes `|x-y|`. Your algorithm must run in `O(1)` worst-case time.
   
     Since the array `S` is sorted, we will take the first element and the last element, and get the difference of between them.
   
     ```c
     int s[] = {3,6,8,13,19};
     
     int min = s[0];
     int max = s[5];
     
     int maximum = s[5] - s[0]; 
     ```
   
   - > Let *S* be a *unsorted* array of *n* integers. Give an algorithm that finds the pair ![](https://latex.codecogs.com/png.latex?%5Cinline%20x%2Cy%20%5Cin%20S)that minimizes `|x-y|`, for `x not equal y`. Your algorithm must run in `O(n log n)` worst-case time.
   
     we can merge sort  this array, Cut the array from the median `S`, `s1`  and `s2` would be two arrays. continuously divide the each array to find the smallest pair of each sub array (*divide by the median of the sub arrays*), after that we will get the minimum value of `s1` and `s2`, this is the minimum distance across the cut. After that get the minimum values within the `minimum distance across the cut` range. This would be our minimum difference.
   
   - > Let *S* be a *sorted* array of *n* integers. Give an algorithm that finds the pair ![](https://latex.codecogs.com/png.latex?%5Cinline%20x%2Cy%20%5Cin%20S)that minimizes `|x-y|`, for `x not equal y`. Your algorithm must run in `O(n)` worst-case time.
   
     Compare the difference between the previous element with the current element. For example sorted version of `S` would be `{3,6,8,13,19}`, we can iterate through this array, our first element is `3` lets store this `3` in `prev` variable and we move onto the next element which would be `6` this is our `curr` variable. `curr - prev` is `3` we store this value in `min` variable, we keep doing this until we exhaust the list. 
   
3. > Take a sequence of `2n` real numbers as input. Design an `O(n log n)` algorithm that partitions the numbers into `n` pairs, with the property that the partition minimizes the maximum sum of a pair. For example, say we are given the numbers `(1,3,5,9)`. The possible partitions are `((1,3),(5,9))`, `((1,5),(3,9))` and `((1,9),(3,5))`. The pair sums for these partitions are `(4,14)`, `(6,12)` and `(10,8)`. Thus the third partition has  10 as maximum sum, which is the minimum over the three partitions. 

   To obtain the maximum sum, we can pair up the smallest element with the largest element, if we need the second largest we can pair up the second smallest element with the second largest number. All we need is two pointers at the end.

   ```python
   # sort the array
   S = sort(S)
   pairs = {}
   for i in range(1, len(s)):
       head = i
       tail = len(s) - (i + 1)
       pair.add((S[head],S[tail]))
   ```

4. > Assume that we are given *n* pairs of items as input, where the first item is a number and the second item is one of three colors (red, blue, or yellow). Further assume that items are sorted by number. Give and `O(n)` algorithm to sort the items by color(all reds before all blues before all yellows) such that the numbers for identical colors stay sorted.
   >
   >
   > For example: `(1,blue),(3,red),(4,blue),(6,yellow),(9,red)` should become `(3,red),(9,red),(1,blue),(4,blue),(6,yellow)`

   we can create different buckets for different colors, walk the array and append each entry to corresponding color, while inserting to the color specific bucket we can compare the second element of the array with the values inside the color bucket and add the values to the correct position.

5. > The *mode* of a set of numbers is the number that occurs most frequently in the set. The set `(4,6,2,4,3,1)` has a mode of `4`. Give an efficient and correct algorithm to compute the mode of a set of `n` numbers.

   We can use hashing and count the values while iterating through the set. Use of hash table and tracking counts will take a lot of space.

   ```python
   # dictionary to hold the hash values and its count
   hashedcounter = {}
   def hashfunction(number):
       return hashednumber
   # iterating through the array
   for i in range(0,len(s)):
       hashednumber = hashfunction(s[i])
       if hashednumber in hashedcounter.keys():
           # increment the counter value
           hashedcounter[hashednumber] += 1
   	else:
           hashedcounter[hashednumber] = 1
   ```

   This would take `O(n)` time. *The above code isn't tested*

6. > Give two sets `S1` and `S2` (each of size *n*), and a number *x*, describe on `O(n log n)` algorithm for finding  whether there exists a pair of elements, one from `S1` and one from `S2`, that add up to `x`. (For partial credit, give `\theta(n^2)` algorithm for this problem.)

   ```c
   int function ispairexit(s1,s2){
   	for (int i = 0; i < n ; i++){
           if (s1[i] + s2[i] == x){
               return 0;
           }
       }
           return -1;
   }
   ```

   The above algorithm will take `O(n)` time. 

   We can sort both of the sets `s1` & `s2`. These two arrays can be sorted and then we can iterate until we reach the `X` value in both sets. Sorting is going take `O(n log n)` time, and we can do a binary search, `O(n log n)`.

7. > Outline a reasonable method of solving each of the following problems. Give the order of the worst-case complexity of your methods.

   - > You are given a pile of thousands of telephone bills and thousands of checks sent in to pay the bills. Find out who did not pay.

     We need to `check` the number mentioned in the check against the telephone bill database, we can have hashed table with all the telephone numbers this would take a lot of space, but it would be faster, we can simply iterate through the `check` to see whether person has payed their bill or not.  

     Space complexity of the hash table would be `O(n)`.  Worst Case Search time of hash table would be `O(n)`.  Iterating through the checks would take `O(n)` time, we can improve the time by using multiprocessing.

   - > You are given a list containing the title, author, call number and publisher of all the books in a school library and another list of 30 publishers. Find put how many of the books in the library were published by each company.

     We 4 different `trie` data structures for each of the properties in the book (title, author, call number, publisher) and to make sure we aren't repeating the same data we can store `pointer to book structure` stored in the node of each tree. We can return the count of a given publisher by iterating through the `trie` data structure.

   - > You are given all the book checkout cards used in the campus library during the past year, each of which contains the name of the person who took out the book. Determine how many distinct people checked out at least one book

     We can use a hash table with a counter, for each person, we will be hashing the campus id. We are going to read the checkout cards in the books and if a name is encountered we will iterate the counter, we can have a global variable that counts the number of people that checked out at least one  book. For example: If sam smith is encountered his campus id will be hashed and counter will be incremented by one and the global counter will also be incremented by one.

8. > Given a set of `S` containing *n* real numbers, and a real number *x*. We seek an algorithm to determine whether two elements of `S` exist whose sum is exactly *x*.

   - > Assume that `S` is unsorted. Given an `O(n log n)` algorithm for the problem.

     we can sort set `S` using merge sort and do a binary search for the element.

     ```python
     def main():
         # returns a sorted array
         s = mergesort(s) 
         for i in range(1, len(s)):
             # returns if the value is present
             if (binarysearch(x - s[i]))	    
                 return true
         return false
     ```

   - > Assume that `S` is sorted. Give an `O(n)` algorithm for the problem.

     We can use a hash table, the look up would be `O(1)`, since the set is already sorted, instead of doing a binary search we just simply look up in the hash table.

9. > Give an efficient algorithm to compute the union of sets `A` and `B`, where `n = max(|A|,|B|)`. The output should be an array of distinct elements that form the union of the sets, such that they appear more than once in the union.

   - > Assume that `A` and `B` are unsorted. Give an `O(n log n)` algorithm for the problem

     we can sort both the set `A` and set `B` using merge sort, which would take `O(n log n)` and then we can compare each element `O(n log n + m log m)` time. Next we are going to iterate through the sorted array, we need two pointers `i` & `j`. If `A[i] < B[i]`, then increment `i`. If `A[j] > B[j] ` then increment `j`. If `A[i] == B[i]` increment both `i` and `j` this process would take `O(n + m)` time.
     
   - > Assume that `A` and `B` are sorted. Give and `O(n)` algorithm for the problem.
   
     ```python
     # stores union set
     union = set()
     
     # append all the values of the smaller array to the set
     for i in range(0, len(A)):
         union.add(A[i])
         
     # append all the values of array B
     for i in range(0, len(B)):
         union.add(B[i])
     ```
   
     After adding all the values of the smaller array to the empty set, we can iterate over the other array (`B`), we will check if the array already exist in the set and if not we can add it, this would take `O(n + m)` time.
   
10. > Given a set *S* of *n* integers and an integer *T*, given an  ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28n%5E%7Bk%20-1%7D%20%5Clog%20n%29) algorithm to test whether *k* of the integers in *S* add up to *T*

    | k    | Big Oh                                                       |
    | ---- | ------------------------------------------------------------ |
    | 1    | ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28%20%5Clog%20n%29) |
    | 2    | ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28n%20%5Clog%20n%29) |
    | 3    | ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28n%5E2%20%5Clog%20n%29) |

    when `k = 2`, we can sort the set `S` and do a binary search while iterating through the set `S`

    when `k = 3`, we can sort the array like before and then we need loop over two times through the array and do a binary search (`T - S[i]- S[j]`)because we need to find 3 set of integers that add up to `T`.
    
11. > Design `O(n)` algorithm that, given a list of *n* elements, finds all the elements that appear mote then  `n/2` times in the list. *Then*, design an `O(n)` algorithm that, given a list of *n* elements, finds all the elements that appear more than `n/4` times.

    we can create a hash table that will store the counter value of each number.

    ```python
    # array with n elements
    A = [5,3,4,4]
    n = len(A)
    hashtable = {};
    for i in range(0, len(A)):
        element = hashfunction(i)
        if element in hashtable.keys():
            hashtable[element] += 1
        else:
            hashtable[element] = 1
    
    # for the first part
    for KEY,COUNT in hashtable.values():
        if COUNT >= n/2:
            print(COUNT)
    # for the second part
    for KEY,COUNT in hashtable.values():
        if COUNT >= n/4:
            print(COUNT)  
    ```

    #### Heaps

12. > Devise an algorithm for finding the *k* smallest elements of an unsorted set of *n* integers in `O(n + k log n)`.

    Build a heap (bubble down) by iterating through the set of *n* integers, this would take `O(n)` time and find `k` smallest elements consecutively till you get the `kth` smallest value `O(k log n)`
    
13. > You wish to store a set of *n* numbers in either a max-heap or a sorted array. For each application below, state which data structure is better, or if it does not matter. Explain your answers.

    - > Want to find the maximum element quickly

      Both cost `O(1)` time.

    - > Want to be able to delete and element quickly

      If we know the exact position for heap it would cost `O(log n)` and for sorted array it would cost `O(n)`. If we don't know the position, searching through the max-heap cost `O(n)` and then to delete it would cost `O(log n)` and to binary search through sorted array it would cost `O(log n)`.  

    - > Want be able to form the structure quickly

      max-heap cost `O(n)` and sorted array cost `O(n log n)`

    - > Want to find minimum element quickly

      max-heap cost `O(n)` and sorted array cost `O(1)`

14. > Give an `O(n log k)`- time algorithm that merges *k* sorted lists with a total of *n* elements into one sorted list. (Hint: Use  a heap to speed up the elementary `O(kn)`-time algorithm)

    Iterate through the *k* sorted list and form *min-heap* `O(n * k)`.  Obtain the minimum value from the *min-heap* and allocate it to a new array.

15. > Give an efficient algorithm to find the second-largest key among *n* keys. you can do better than `2n - 3` comparisons.

    ```c
    int main(){
        // stores the largest items
        int arr[] = {5,6,9,2,1}
        int largest_arr[2] = {0,0};
        
        // intializing the largest arr
        largest_arr[0] = arr[0];
        largest_arr[1] = arr[1];
        
        // iterate throught the arr array
        for (int i = 2; i < sizeof(arr)/sizeof(arr[0]); i++){
            // comparing the elements against the largest element
            if ((arr[i] > largest_arr[0]) || (arr[i] > largest_arr[1])){
                // find the smallest value in largest_arr and 
                // replace it with the current element
                replace_smallest(largest_arr, arr[i]);
            }
        }
    }
    ```

    [check this out in action](codes/exercise_4.16.a.c), worst case scenario is the first two elements are the smallest, `2n - 3` comparisons

    > Then, given an efficient algorithm to find the third-largest key among *n* keys. How many key comparisons does your algorithm do in the worst case? Must your algorithm determine which key is largest and second-largest in the process.

    `largest_arr` is now holding `3` values so the iteration starts `N - 3`, worst case would be first 3 numbers of the `arr` is the smallest, there would be `3(N - 3) + 2` comparisons. Yes we will find the second largest key during the process as well.

    #### Quick-sort

16. > Use the partitioning idea of quick sort to give an algorithm that finds the *median* element of an array of *n* integers in expected `O(n)` time. (Hint: must you look at both sides of the partition)

	Randomly select the pivot. [Implementation of Quick Sort](codes/quicksort.c)

17. > The *median* of a set of *n* values is the `n/2`th smallest value.
	
	 - > Suppose quicksort always pivoted on the median of the current sub-array. How many comparisons would Quicksort make then in the worst case?
	
	Subproblems are always half the size, the worst case would be the array is already sorted in the descending order. `2n - 1 ` comparisons

- > Suppose quicksort were always to pivot on the `n/3`th smallest value of the current sub-array. How many comparisons would be made then in the worst case

  worst case would be the array is already sorted in the descending order. `2n - 1 ` comparisons.

18. > Suppose an array *A* consists of *n* elements, each of which is *red, white,* or *blue*. We seek to sort the elements so that all the *reds* come before all the *whites*, which comes before all the *blues*. The only operation permitted on the keys are
	-  `Examine(A,i)` - report the color of the `i`th element of *A*. 	
	-  `Swap(A, i ,j)`  - swap the `i`th element of *A* with the `j`th element.
	 Find a correct and efficient algorithm for red-white-blue sorting. There is a linear-time solution.
	
	Consider red and white as same color and separate color blue using quick sort and then separate the red and white color.
		
	
19. > An [*inversion* of a permutation](https://www.ndsu.edu/pubweb/~dyheuer/Inversions%20of%20Permutations.pdf) is a pair of elements that are out of order.
	
	- > Show that a permutation of *n* items has at most `n(n - 1)/ 2` inversions. Which permutations(s) have exactly `n(n - 1)/ 2` inversions?
	
	  Example : `arr = {6,5,4,3,2,1}; n = 6 `. 

	  | Element | Inversion number |
	  | ------- | ---------------- |
	  | 6       | 5                |
	  | 5       | 4                |
	  | 4       | 3                |
	  | 3       | 2                |
	  | 2       | 1                |
	  | 1       | 0                |

	  `Total number of inversions = 15`
      
	  claim : permutation with `n` items have `n(n - 1)/2` inversions, substituting `n = 6`: `6(6 - 1) / 2 = 15`.  To get the maximum number of inversions the elements should be sorted in the descending order. 
      
        - >  Let *P* be a permutation and ![](https://latex.codecogs.com/png.latex?%5Cinline%20P%5E%7Br%7D)be the reversal of this permutation. Show that `P` and ![](https://latex.codecogs.com/png.latex?%5Cinline%20P%5E%7Br%7D) have a total of exactly `n(n - 1)/2` inversions.
        - > Use the previous result to argue that the expected number of inversions in a random permutation is `n(n - 4)/4`.

20. > Give an efficient algorithm  to rearrange an array of *n* keys so that all the negative keys precede all the non-negative keys. You algorithm must be in-place, meaning you can allocated another array to temporarily hold the items. How fast is your algorithm ? 

	[Implementation of Quick Sort](codes/quicksort.c)

#### Other Sorting Algorithms

21. > Stable sorting algorithms leave equal-key items in the same relative order as in the original permutation. Explain what must be done to ensure that mergesort is a stable sorting algorithm.

	Mergesort algorithms are already stable with top down and bottom up approaches, when algorithms will similar key values are compared we dont need to switch them just doing this will keep the elements with the same key values in the original order.

22. > Show that *n* positive integers in the range `1` to `k` can be sorted in `O(n log k)` time. The interesting case is when `k << n`.
    
	Example : ` k = 8`, `n = 4  `, `arr = {5,6,8,7}`. `O(log k)` where `k = 8` would mean `3 steps/divisions`. 
        
	```
		 {5,6,8,7}		(1)
		{5,6} {8,7}  	(2)
	   {5} {6}{8} {7} 	(3)
	```
    
	Normal merge sort algorithm would take `O (n log k)` times. When `k < n` (`k = 4`,`n = 6`,`arr = {1,3,1,4,3,2}`). `O( log k)` where `k = 4` means `2 steps/divisions`. We can divide the array at the median and use quick sort to sort all the elements.
	
23. > We seek to sort a sequence `S` of `n` integers with many duplications, such that the number of distinct integers in `S` is `O(log n)`. Give and `O(n log log n)` worst-case  time algorithm  to sort such sequence

    Example: `n = 8`, `number of distinct integers = O(log n) = log(8) = 3`, `s = {2,3,3,3,4,5,5,5}`.

    If we are using merge sort, this would take us `O(n log N)` times and here the `N` would be the number of distinct numbers, `log n`.  Therefore a simple `O(n log log n)` algorithm would be the merge sort algorithm.

24. > Let `A[1..n]` be an array such that the first ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%20-%20%5Csqrt%7Bn%7D)elements are already sorted (though we know nothing about the remain elements). Give an algorithm that sorts `A` in substantially better than `n log n` steps.

    Example: `n = 8`, first ![](https://latex.codecogs.com/png.latex?%5Cinline%208%20-%20%5Csqrt%7B8%7D) (`4`)items will be sorted. Since we know the first `4` items are sorted we can do a merge sort but instead of dividing the algorithm from the median we can divide it after the first  ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%20-%20%5Csqrt%7Bn%7D) elements. 

    ```
    	{1,2,3,4,7,6,5,8} (1)
    {1,2,3,4}	 {7,6,5,8} (2)
    			{7,6} {5,8} (3)
    ```

    The above algorithm will be ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28n%20%5Clog%20n%20-%20%5Csqrt%20n%29)
    
25. > Assume that the array `A[1..n]` only has numbers from `{1,...,n^2}` but that at most `log log n` of these numbers ever appear. Devise an algorithm that sorts `A` in substantially less than `O(n log n)`

    Balanced Binary Search Tree (Merge Sort) the height of the tree would be `O(log log n)`, the worst case would be `O(n log log log n)` 

26. > Consider the problem of sorting a sequence of *n* `0's` and `1's` using comparisons. For each comparison of two values *x* and *y*, the algorithm learns which of `x < y`, `x = y` or  `x > y` holds.
    >
    > ***I didn't get this question!*** :cry:

    - > Give an algorithm to sort in `n - 1` comparisons in the worst case. Show that your algorithm is optimal.

      Since the sequence on consist of `1` and `0` we can count the number of ones and zeros and create a new array and insert the `0` first and then `1`.

      ```python
      x = [1,1,0,0,0,1]
      count_one = 0 # stores the count of 1's
      count_zero = 0 # stores the count of 0's
      
      for i in x:
          if i == 1:
              count_one += 1
      	else:
              count_zero += 1
      ```
	
	- > Give an algorithm to sort in `2n/3` comparisons in the average case (assuming each of *n* inputs in `0` or `1` with equal probability). Show that your algorithm is optimal.

      we can implement a bucket sort algorithm, assuming that there is equal distribution of `1`'s and `0`'s .
    
27. > Let `P` be a simple, but not necessarily convex, polygon and `q` an arbitrary point not necessarily in `P`. Design an efficient algorithm to find a line segment originating from `q` that intersects the maximum number of edges of `P`. In other words, if standing at point `q`, in what direction should you aim a gun so the bullet will go through the largest number of walls. A bullet through a vertex of `P` gets credit for only one wall. An `O(n log n)` algorithm is possible.

    From the point `q` obtain the polar coordinates to the edges of  polygon `P` (start point & end point of each edge) `O(n)` and then we can sort these point in the ascending order `O(n log n)`.  After this loop through the array to find the possible lines (in polygon `P`) that nearly intersects, increment when we encounter a edge and decrement when we encounter head  `O(n)`.

#### Lower Bounds

28. > In one of my research papers, I discovered a comparison-based sorting algorithm runs in ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28n%20%5Clog%20%5Csqrt%20n%29). Given the existence of an ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5COmega%20%28n%20%5Clog%20%5Csqrt%20n%29) lower bound for sorting, how can this be possible ?

    ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%20%5Clog%20%5Csqrt%20n)  can be written as ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%20%5Clog%20n%5E%7B1/2%7D) can be simplified to ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Cfrac%7B1%7D%7B2%7Dn%20%5Clog%20n) which is ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5COmega%20%28n%20%5Clog%20n%29). The above claim in the research paper doesn't violate the lower bounds of sorting.
    
29. > Mr. B. D. C. Dull claims to have developed a new data structure for priority queues that supports the operations *Insert*, *Maximum*, and *Extract-max* all in `O(1)` worst-case time. Prove that he is mistaken.

    If Extraction of maximum takes `O(1)` time, if we have the data structure with `n`  elements then sorting this set would take `O(n)` time.
    
#### Searching

30. > A company database consists of `10,000` sorted names, `40%` of whom are known as good customers and who together account for `60%` of the accesses to the database. There are two data structures options to consider for representing the database:
    >
    > - Put all names in a single array and use binary search
    > - Put the good customers in one array and the rest of them in a second array. Only if we don't find the query name on a binary search of the first array do we do a binary search of the second array.
    >
    > Demonstrate which options gives better expected performance. Does this change if linear search on an unsorted array is used instead of binary search for both options?

    If we put the all the names in a single array and use binary search, the time complexity for searching would be `O(log n)`.

    ```
    n = 10000
    log (10000) = 13.2877123795
    ```

    If we put all the good customers in one array and the rest of them in a second array, the worst case would be customer not found in the first array and second array.

    ```
    n = 4000 (first array)
    log (4000) = 11.96
    
    n = 6000 (second array)
    log (6000) = 12.55
    
    worst-case = 11.96 + 12.55 = 24.51
    ```

    The first option, putting all names in one single array gives us the best run-time.

    If linear search is used instead of binary search, using the two array option is much better.

31. > Suppose you are given an array `A` of  *n* sorted numbers that has been *circularly shifted k* positions to the right. For example, `{35,42,5,15,27,29}` is a sorted array that has been circularly shifted `k=2` positions, while `{27,29,35,42,5,15}` has been shifted `k=4` positions.

    - > suppose you know what *k* is. Give an `O(1)` algorithm to find the largest number in *A*.

      ```python
      A = [35,42,5,15,27,29]
      k = 2
      maximum = A[k - 1]
      print(f"Maximum is {maximum}")
      ```

    - > Suppose you do not know what *k* is. Give an `O(log n)` algorithm to find the largest number in *A*. For partial credit, you may give an `O(n)` algorithm.

      ```c
      // for partial credit
      A = {35,42,5,15,27,29};
      size = sizeof(A)/sizeof(A[0]);
      int max = A[0];
      for (int i = 1; i < size; i++){
          if A[i] > max{
              max = A[i];
          }
      }
      ```

      ```python
      # O(log n) algorithm
      A = [35,42,5,15,27,29]
      leftmost = 0
      rightmost = length(A) - 1
      
      def largestNumber(leftmost, rightmost):
      	# array is already sorted
          if A[leftmost] < A[rightmost]:
          	return A[rightmost]
          elif lestmost == rightmost:
      ```
    # array has only one element
          	return A[rightmost]
        
          # median of the array
          median = leftmost + rightmost / 2
        
          if ((median + 1 <= rightmost) and A[median] > A[median+1]):
              return A[mid]
          elif ((median - 1 >= leftmost) and A[median - 1] > A[median]):
              return A[mid - 1]
          
          # recursion
          if A[mid] < A[rightmost]:
          	return largestNumber(leftmost, median - 1)
          else:
          	return largestNumber(median + 1, rightmost)
      ```
      
      ```
    
32. > Consider the numerical 20 Questions game. In this game, Player 1 thinks of a number in range in 1 to n`. Player 2 has to figure out this number by asking the fewest true/false questions.

    - > What is an optimal strategy if *n* is known ?

      Probably get the median of the numbers in range of `1 to n` and ask if its greater than the median number, if true move right else move left. keep doing this until you find the number.

    - > What is a good strategy if *n* is not known?

      This would be harder to get, randomly select a number and ask if the number is greater or smaller, keep randomly selecting numbers in the given range while asking if the number is greater or smaller.

33. > Suppose that you are given a sorted sequence of *distinct* integers ![](https://latex.codecogs.com/png.latex?%5Cinline%20%7Ba_1%2Ca_2%2C...%2Ca_n%7D). Give an `O( log n)` algorithm to determine whether there exists and `i` index such as ![](https://latex.codecogs.com/png.latex?%5Cinline%20a_i%20%3D%20i). For example, in `{-10,-3,3,5,7}`, `a3 = 3`. In `{2,3,4,5,6,7}`, there is not such `i`.

    ```python
    def iExist(A):
        left = 0
        right = len(A) - 1
        middle = right / 2
    
        while (right >= left):
            # check if the middle value
            # greater or smaller compared
            # with the index
            if A[middle] < middle + 1:
                left = middle + 1
            elif A[middle] > middle + 1:
                right = middle - 1
            else:
                # we found the number
                return True
    	return False
    ```

34. > Suppose that you are given a sorted sequence of distinct integers ![](https://latex.codecogs.com/png.latex?%5Cinline%20%7Ba_1%2Ca_2%2C...%2Ca_n%7D), drawn from `1 to m` where `n < m`. Give an `O(log n)` algorithm to find an `integer <= m` that is not present in `a`. For full credit, find the smallest such integer.
    >
    > *cant understand this question*

    `{2,3,4,5,6,7}`, `n < m: 6 < 7`. `m` is the maximum value in a sorted array. Therefore the integer would be the rightmost element plus one (assuming that `m` is present in the array).

    ```python
    # finding the smallest integer
    left = 0
    right = len(A) - 1
    
    while right >= left:
        # keep diving the array by the median
        median = (left + right) / 2
        if A[median] <= median + 1:
            right = median - 1
        elif A[median] > median + 1:
            left = median + 1
    ```
    
35. > Let `M` be and `n x m` integer matrix in which the entries of each row are sorted in increasing order (from left to right) and the entries in each column are in increasing order (from top to bottom). Give an efficient algorithm to find the position of an integer *x* in *M*, or to determine that *x* is not there. How many comparisons of *x* with matrix entries does your algorithm use in worst case?

    ```python
    M = [[1,2,3],[4,5,6],[7,8,9]]
    """
    1 2 3
    4 5 6
    7 8 9
    """
    
    def findX(arr,n,m,X):
        """
        n -> number of rows
        m -> number of cols
        """
        # starting from the top corner
        row = 0, cols = m - 1
        while (row < n) and (cols >= 0):
            # check if the value is present
            if arr[row][cols] == X:
                return (row,cols)
            elif arr[row][cols] > X:
                # shift to the next col
                cols -= 1
           	else:
                row -= 1
    ```

    This algorithm would take `O(n + m)` time.

36. > Consider an  `n x n` array *A* containing integer elements (positive, negative, and zero). Assume that the elements in each row of *A* are in strictly increasing order, and the elements of each column of *A* are in strictly decreasing order. (Hence there cannot be two zeros in the same row or the same column). Describe an efficient algorithm that counts the number of occurrences of the element `0` in *A*. Analyze its running time.

    ```python
    A = [[7,8,9],[4,5,6],[-1,0,2]]
    """
    7 8 9
    4 5 6
    -1 0 2
    """
    def findZeroCount(arr, n):
        rows = n, cols = n
        zero = 0
        while (rows >= 0) and (cols > 0):
            if arr[row][cols] == 0:
                zero += 1
                # move to the next row
                row -= 1
            elif arr[row][cols] > 0
            	# columns are arrange in decreasing order
                cols -= 1
            else:
                # move to next row
                row -= 1
    ```

37. > Implement versions of several different sorting algorithms, such as selection sort, insertion sort, heap sort, mergesort, and quicksort. Conduct experiments to assess the relative performance of these algorithms in a simple application that reads a large text file and reports exactly one instance of each word that appears within it. This application can be efficiently implemented by sorting all the words that occur in the text and then passing through sorted sequence to identify one instance of each distinct word. Write a brief report with your conclusions.

    
