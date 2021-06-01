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

6. 
