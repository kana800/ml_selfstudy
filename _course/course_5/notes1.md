[Notes are from the Lecture #1: Introduction and Proof](https://www.youtube.com/watch?v=L3LMbpZIKhQ&list=PLB7540DEDD482705B&index=1)

---

[What is a Proof?](https://youtu.be/L3LMbpZIKhQ?list=PLB7540DEDD482705B&t=83)

A proof is a method for ascertaining (establish/verify) the truth. 

Ways of ascertaining the truth:

- Experimentation & Observations
- Sampling & Counterexamples

A mathematical proof is a verification of  a proposition by a chain of logical deductions from a set of axioms.

-  Proposition is a statement that is either true or false.

[Example](https://youtu.be/L3LMbpZIKhQ?list=PLB7540DEDD482705B&t=600):

- ![](https://latex.codecogs.com/png.latex?%5Cinline%20%5Cforall%20%5Cin%20%5Cmathbb%7BN%7D%2C%20n%5E%7B2%7D%20&plus;%20n&plus;%201) is a prime number. `n^2 + n + 41 is a prime number` is called the predicate. A predicate is a proposition whose truth depends on the value of variables. 

  | n    | `n^2 + n + 41` | is prime? |
  | ---- | -------------- | --------- |
  | 0    | 41             | True      |
  | 1    | 43             | True      |
  | 2    | 47             | True      |

  This proposition is false  

  counter examples:  `n = 40`, `n = 41`

- Implies -  An implication `p -> q` is true if `p` if for `q` is True

  | p    | q    | p implies q |
  | ---- | ---- | ----------- |
  | T    | T    | T           |
  | T    | F    | F           |
  | F    | T    | T           |
  | F    | F    | T           |

[Axioms](https://youtu.be/L3LMbpZIKhQ?list=PLB7540DEDD482705B&t=2154)

An axiom is a proposition that is assumed to be True. There is no proof that axiom is True.

Example:

- If `a=b` & `b=c`, then `a = c`

Axioms should be 

- consistent: A set of axioms is consistent if no proposition can be proved to both True and False.
- complete: A set of axioms is complete if it can used to prove if every proposition can be True and False.
