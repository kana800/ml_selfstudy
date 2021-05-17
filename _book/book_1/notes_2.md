Notes obtained from this lecture: [link](https://www.youtube.com/watch?v=z1mkCe3kVUA&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=2)

#### Problem of the Day

*knapsack problem*, find counter example for the following solutions

- Put the elements of `S` in the knapsack in left to right order if they fit. i.e the first algorithm.

  > `s = {1 ,2 ,3}` & `T = 4`, the algorithm would start from `1` , `1` will be added to the sack and we will move the next element `2`, `2` can also be added but we cant add `3` and the optimal solution for the above example should be `sack ->{1,3}` . 

- Put the elements of `S` in the knapsack from smallest to largest, i.e the best-fit algorithm.

  >`s = {1, 2, 3}` & `T = 2`, the algorithm will start from the smallest value which is `1`, `1` will be added to sack but the next two integers cannot be added to sack, the optimal solution for the above example would be `sack ->{2}`

- Put the elements of `S` in the knapsack from largest to smallest?

  > `s = {2, 3, 4}` & `T = 5 `, we will select the largest value which is `4` and we can fit any more values, the optimal solution would be `sack -> {2,3}`

#### Asymptotic Notation (BIG OH')

We have 3 assumptions when it comes to finding run time of an algorithm,

- Each 'simple' operation `+ , - , = , if , call` takes 1 step
- Loops and sub routines calls are not simple operations and depend upon the size of the data and content of a subroutine
- Each Memory access takes exactly 1 step.

we measure the run time by counting the number of steps.

Worst case complexity of an algorithm is the function defined by the maximum number of steps taken on any instance of size n.

Best case complexity of an algorithm is function defined by minimum number of steps taken on any instance of size n.

Exact analysis of the algorithm is hard, we can always talk about lower bound and upper about of the functions.

Definition: 

- `g(n) = O(f(n))` means `C x f(n)` Big Oh is the upper bound on `g(n)`.

- `g(n) = \omega(f(n))` means `C x f(n)` Omega is the lower bound on `g(n)`.

- `g(n) = \theta(f(n))` means `f(n)` both (`C1 x f(n)`)upper bound and (`C2 x f(n)`)lower bound of `g(n)`, `C1 > C2`

Formal Definition:

- `f(n) = O(g(n))` if there are positive constants `n0` and `C`, such that to the right of `n0`, the value of `f(n)` always lies on or below `c . g(n)`.
- `f(n) = \omega(g(n))` if there are positive constants `n0` and `C`, such that to the right of `n0`, the value of `f(n)` always lies on or above `c . g(n)` .
- `f(n) = \theta(g(n))` if there exist positive constant `n0`,`c1` and `c2` such that to the right of `n0`, the value of `f(n)` always lies between `c1 . g(n)` and `c2 . g(n)` inclusive.

Example:

- ![](https://latex.codecogs.com/png.latex?%5Cinline%203n%5E%7B2%7D%20-%20100n%20&plus;%206%20%3D%20O%28n%5E%7B2%7D%29), why `O(n^2)` ? , well the definition of **big oh** is there is constant `C` such ![](https://latex.codecogs.com/png.latex?%5Cinline%20C%20%5Ctimes%20n%5E%7B2%7D)  is greater than ![](https://latex.codecogs.com/png.latex?3n%5E%7B2%7D%20-%20100n%20&plus;%206), `C = 3`. [link](https://youtu.be/z1mkCe3kVUA?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=4320)

#### Problem of the Day

For each of the following pairs of functions `f(n)` and `g(n)`, state whether `f(n) = O(g(n))`, `f(n) = \omega(g(n))`, `f(n) = \theta(g(n))`, or none of the above.

1. ![](https://latex.codecogs.com/png.latex?%5Cinline%20f%28n%29%20%3D%20n%5E%7B2%7D%20&plus;%203n%20&plus;%204%2C%20g%28n%29%3D6n%20&plus;%207) `f(n) = \omega(g(n))`
2. ![](https://latex.codecogs.com/png.latex?%5Cinline%20f%28n%29%20%3D%20n%5Csqrt%7Bn%7D%20%2C%20g%28n%29%20%3D%20n%5E%7B2%7D%20-%20n) `f(n) = O(g(n))`
3. ![](https://latex.codecogs.com/png.latex?%5Cinline%20f%28n%29%20%3D%202%5E%7Bn%7D%20-%20n%5E%7B2%7D%2C%20g%28n%29%20%3D%20n%5E%7B4%7D%20&plus;%20n%5E%7B2%7D) `f(n) = \omega(g(n))`

#### Multiplication and the Big Oh

- Multiplication by a constant does not change the asymptotic,

  ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28c%20%5Ccdot%20f%28n%29%29%20%5Crightarrow%20O%28f%28n%29%29)

- Multiplication by function,

  ![](https://latex.codecogs.com/png.latex?%5Cinline%20O%28f%28n%29%29%20%5Ccdot%20O%28g%28n%29%29%20%5Crightarrow%20O%28f%28n%29%20%5Ccdot%20g%28n%29%29)

  *This is why the running times of two nested loops is*  `O(n^2)`

#### Analyzing Algorithms: Selection and Insertion Sort

```c
// selection sort
void selection_sort(item_type s[], int n){
    int i,j ; // counters
    int min;
    
    for (i = 0; i < n; i++){ // n steps 
        min = i; // 1 step
        for (j = i + 1; j < n; j++){ // n steps
            if (s[j] < s[min]){ // 1 step
                min = j; // 1 step
            }
        }
        swap(&s[i], &s[min]); // steps
    }
}
```

`N( 1 + N + 1) = N^2`, Therefore Big Oh is `O(n^2)`.

An exact count of the number of times the `if` statement is executed is given by:

![](https://latex.codecogs.com/png.latex?%5Cinline%20S%28n%29%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7D%5Csum_%7Bj%20%3D%20i%20&plus;1%7D%5E%7Bn%20-%201%7D%201%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7D%28n%20-%20i&plus;1%29%20%3D%20%5Csum_%7Bi%20%3D%200%7D%5E%7Bn-1%7Di)

```c
void insertion_sort(item_type s[], int n){
    int i, j; //counters
    
    for (i = 1; i <n ; i++){
        j = i;
        while ((j > 0) && (s[j] < s[j - 1])){
            swap(&s[j], &s[j - 1]);
            j = j - 1;
        }
    }
}
```

The Big Oh is `O(n^2)`, Tight Bound is `\theta(n^2)`

#### Testing Dominance

we can say `f(n)` dominates `g(n)` if ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Clim_%7Bn%20%5Cto%20%5Cinfty%7D%20%5Cfrac%7Bg%28n%29%7D%7Bf%28n%29%7D%20%3D%200), which same as saying `g(n) = o(f(n))`.

*little-oh means **grows strictly slower than***

##### Properties of dominance

- ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%5E%7Ba%7D) dominates ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%5E%7Bb%7D) if `a  > b` since

  ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Clim_%7Bn%20%5Cto%20%5Cinfty%7D%20%5Cfrac%7Bn%5E%7Bb%7D%7D%7Bn%5E%7Ba%7D%7D%20%3D%20n%5E%7Bb-a%7D%20%5Cto%200)

- ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%5E%7Ba%7D%20&plus;%20o%28n%5E%7Ba%7D%29) doesn't dominate ![](https://latex.codecogs.com/png.latex?%5Cinline%20n%5E%7Ba%7D)since

  ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Clim_%7Bn%20%5Cto%20%5Cinfty%7D%20%5Cfrac%7Bn%5E%7Ba%7D%7D%7Bn%5E%7Ba%7D%20&plus;%20o%28n%5E%7Ba%7D%29%7D%20%5Cto%201)

  There is no dominance when there is an additive term.
  
  *o(n^a)* means grows strictly slower than `n^a`

#### Logarithms

A logarithm is simply an inverse exponential function. `b^x = y` is equivalent to ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Clog_b%20y), logarithms reflect how many times we can double something until we get to *n*, or halve something until we get to 1.

- [Binary Search](https://youtu.be/9RrdOssuOY4?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=4220)
- [Binary Tree](https://youtu.be/9RrdOssuOY4?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=4311)

