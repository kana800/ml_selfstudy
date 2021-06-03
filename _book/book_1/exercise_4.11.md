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