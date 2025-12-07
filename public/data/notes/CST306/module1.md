# Module 1: Introduction to Algorithm Analysis

## 1. Characteristics of Algorithms

An **algorithm** is a finite sequence of well-defined, unambiguous instructions for solving a problem or accomplishing a specific task.

### Key Characteristics:
1. **Finiteness** - Algorithm must terminate after a finite number of steps
2. **Definiteness** - Each instruction must be clear and unambiguous
3. **Input** - Zero or more inputs
4. **Output** - One or more outputs
5. **Effectiveness** - Each operation must be basic enough to be performed exactly
6. **Generality** - Applicable to a set of inputs, not just specific cases

## 2. Criteria for Analysing Algorithms

When analyzing algorithms, we consider:

1. **Correctness** - Does the algorithm solve the problem correctly?
2. **Time Efficiency** - How fast does the algorithm run?
3. **Space Efficiency** - How much memory does the algorithm use?
4. **Simplicity** - Is the algorithm easy to understand and implement?
5. **Optimality** - Is this the best possible solution?

## 3. Time and Space Complexity

### Time Complexity
- Amount of time taken by an algorithm to run as a function of input size (n)
- Measured by counting the number of basic operations

### Space Complexity
- Amount of memory space required by an algorithm as a function of input size (n)
- Includes space for: variables, constants, function calls, etc.

### Cases of Complexity Analysis:

#### 1. Best Case Complexity
- Minimum time/space required for input of size n
- Represented as Ω-notation (lower bound)
- **Example**: Linear search - element found at first position

#### 2. Worst Case Complexity
- Maximum time/space required for input of size n
- Represented as O-notation (upper bound)
- **Example**: Linear search - element found at last position or not present

#### 3. Average Case Complexity
- Expected time/space for random input of size n
- Represented as Θ-notation (tight bound)
- Requires probability distribution of inputs

## 4. Asymptotic Notations

Asymptotic notations describe the limiting behavior of functions as n approaches infinity.

### Big-Oh Notation (O)
- **Definition**: f(n) = O(g(n)) if there exist positive constants c and n₀ such that:
  0 ≤ f(n) ≤ c·g(n) for all n ≥ n₀
- Represents **upper bound** of growth rate
- **Example**: 3n² + 2n + 1 = O(n²)

### Big-Omega Notation (Ω)
- **Definition**: f(n) = Ω(g(n)) if there exist positive constants c and n₀ such that:
  0 ≤ c·g(n) ≤ f(n) for all n ≥ n₀
- Represents **lower bound** of growth rate
- **Example**: 3n² + 2n + 1 = Ω(n²)

### Big-Theta Notation (Θ)
- **Definition**: f(n) = Θ(g(n)) if there exist positive constants c₁, c₂, and n₀ such that:
  0 ≤ c₁·g(n) ≤ f(n) ≤ c₂·g(n) for all n ≥ n₀
- Represents **tight bound** (both upper and lower)
- **Example**: 3n² + 2n + 1 = Θ(n²)

### Little-oh Notation (o)
- **Definition**: f(n) = o(g(n)) if for every positive constant c, there exists n₀ such that:
  0 ≤ f(n) < c·g(n) for all n ≥ n₀
- Represents an **upper bound that is not asymptotically tight**
- **Example**: n = o(n²), but n² ≠ o(n²)

### Little-Omega Notation (ω)
- **Definition**: f(n) = ω(g(n)) if for every positive constant c, there exists n₀ such that:
  0 ≤ c·g(n) < f(n) for all n ≥ n₀
- Represents a **lower bound that is not asymptotically tight**
- **Example**: n² = ω(n), but n ≠ ω(n)

### Properties of Asymptotic Notations:

#### Reflexivity:
- f(n) = O(f(n))
- f(n) = Ω(f(n))
- f(n) = Θ(f(n))

#### Transitivity:
- If f(n) = O(g(n)) and g(n) = O(h(n)), then f(n) = O(h(n))
- Similar for Ω and Θ

#### Symmetry:
- f(n) = Θ(g(n)) if and only if g(n) = Θ(f(n))

#### Transpose Symmetry:
- f(n) = O(g(n)) if and only if g(n) = Ω(f(n))
- f(n) = o(g(n)) if and only if g(n) = ω(f(n))

## 5. Classifying Functions by Asymptotic Growth Rate

### Common Growth Rates (from slowest to fastest):

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Accessing array element |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search |
| O(n log n) | Linearithmic | Merge sort, Heap sort |
| O(n²) | Quadratic | Bubble sort, Selection sort |
| O(n³) | Cubic | Matrix multiplication (naive) |
| O(2ⁿ) | Exponential | Tower of Hanoi |
| O(n!) | Factorial | Traveling salesman (brute force) |

### Hierarchy of Growth Rates:
```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

## 6. Complexity Calculation of Simple Algorithms

### Example 1: Linear Search
```python
def linear_search(arr, key):
    for i in range(len(arr)):  # n iterations
        if arr[i] == key:      # 1 operation
            return i           # 1 operation
    return -1                  # 1 operation
```
- **Worst Case**: O(n) - element not found or at last position
- **Best Case**: Ω(1) - element at first position
- **Average Case**: Θ(n) - element at middle position

### Example 2: Bubble Sort
```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):                 # n iterations
        for j in range(0, n-i-1):      # (n-1)+(n-2)+...+1 = n(n-1)/2 iterations
            if arr[j] > arr[j+1]:      # 1 operation
                arr[j], arr[j+1] = arr[j+1], arr[j]  # 1 operation
```
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1) - in-place sorting

### Rules for Calculating Complexity:
1. **Sequential statements**: Add complexities
2. **Loop statements**: Multiply loop iteration count by complexity of loop body
3. **Conditional statements**: Take maximum complexity of branches
4. **Nested loops**: Multiply complexities

## 7. Analysis of Recursive Algorithms

Recursive algorithms are analyzed using **recurrence relations**.

### Recurrence Equations
A recurrence relation defines a function in terms of its value at smaller inputs.

**Example**: Fibonacci sequence
```
T(n) = T(n-1) + T(n-2) + O(1) for n > 1
T(0) = O(1)
T(1) = O(1)
```

**Example**: Merge Sort
```
T(n) = 2T(n/2) + O(n) for n > 1
T(1) = O(1)
```

## 8. Solving Recurrence Equations

### 1. Iteration Method (Telescoping Method)
Expand the recurrence repeatedly until a pattern emerges.

**Example**:
```
T(n) = T(n-1) + 1
     = [T(n-2) + 1] + 1 = T(n-2) + 2
     = [T(n-3) + 1] + 2 = T(n-3) + 3
     ...
     = T(1) + (n-1)
     = O(n)
```

### 2. Recursion Tree Method
Visualize the recurrence as a tree and sum costs at each level.

**Example**: T(n) = 2T(n/2) + n
```
Level 0: cost = n
Level 1: cost = n/2 + n/2 = n
Level 2: cost = n/4 + n/4 + n/4 + n/4 = n
...
Height: log₂n
Total cost = n × log₂n = O(n log n)
```

### 3. Substitution Method
1. Guess the form of the solution
2. Use mathematical induction to prove the guess

**Example**: T(n) = 2T(n/2) + n
- Guess: T(n) = O(n log n)
- Assume: T(n/2) ≤ c(n/2)log(n/2)
- Prove: T(n) ≤ cn log n

### 4. Master's Theorem
For recurrences of the form:
```
T(n) = aT(n/b) + f(n) where a ≥ 1, b > 1
```
Compare f(n) with n^(log_b a):

**Case 1**: If f(n) = O(n^(log_b a - ε)) for some ε > 0, then T(n) = Θ(n^(log_b a))

**Case 2**: If f(n) = Θ(n^(log_b a) log^k n) for some k ≥ 0, then T(n) = Θ(n^(log_b a) log^(k+1) n)

**Case 3**: If f(n) = Ω(n^(log_b a + ε)) for some ε > 0, and af(n/b) ≤ cf(n) for some c < 1 and sufficiently large n, then T(n) = Θ(f(n))

#### Master's Theorem Examples:
1. **Binary Search**: T(n) = T(n/2) + O(1)
   - a=1, b=2, f(n)=O(1), n^(log₂1)=n⁰=1
   - Case 2: T(n) = Θ(log n)

2. **Merge Sort**: T(n) = 2T(n/2) + O(n)
   - a=2, b=2, f(n)=O(n), n^(log₂2)=n¹=n
   - Case 2: T(n) = Θ(n log n)

3. **Recursive Matrix Multiplication**: T(n) = 8T(n/2) + Θ(n²)
   - a=8, b=2, f(n)=Θ(n²), n^(log₂8)=n³
   - Case 1: T(n) = Θ(n³)

## Summary Table of Common Recurrences

| Recurrence | Solution | Example Algorithm |
|------------|----------|-------------------|
| T(n) = T(n-1) + O(1) | O(n) | Linear Search (Recursive) |
| T(n) = T(n-1) + O(n) | O(n²) | Selection Sort |
| T(n) = 2T(n-1) + O(1) | O(2ⁿ) | Tower of Hanoi |
| T(n) = T(n/2) + O(1) | O(log n) | Binary Search |
| T(n) = 2T(n/2) + O(1) | O(n) | Tree Traversal |
| T(n) = 2T(n/2) + O(n) | O(n log n) | Merge Sort, Quick Sort (avg) |
| T(n) = T(n/2) + O(n) | O(n) | |
| T(n) = 2T(n/2) + O(n log n) | O(n log² n) | |

## Important Points to Remember

1. **Big-O** is used for worst-case analysis
2. **Big-Ω** is used for best-case analysis  
3. **Big-Θ** gives tight bounds for average-case analysis
4. Space complexity includes auxiliary space and input space
5. Recursive algorithms often have higher space complexity due to call stack
6. Master's theorem cannot be applied if:
   - a is not constant
   - f(n) is not polynomial
   - n/b is not an integer
   - The regularity condition in Case 3 fails

## Practice Problems

1. Find the time complexity of:
   ```python
   for i in range(n):
       for j in range(i, n):
           print(i, j)
   ```
   **Answer**: O(n²)

2. Solve: T(n) = 3T(n/4) + n log n
   **Answer**: Using Master's Theorem, Case 1: Θ(n^(log₄3))

3. Prove that 2n³ + 3n² + 1 = Θ(n³)
   **Proof**: Choose c₁=2, c₂=5, n₀=1, then 2n³ ≤ 2n³+3n²+1 ≤ 5n³ for n≥1
