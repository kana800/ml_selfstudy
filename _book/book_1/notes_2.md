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