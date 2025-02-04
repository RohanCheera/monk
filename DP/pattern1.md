# **Dynamic Programming: Interval Splitting Pattern**  

## **Introduction**  
The **Interval Splitting DP Pattern** is a common approach for solving problems that involve breaking a range or sequence into smaller subproblems. This pattern is widely used in **game theory, partitioning, and cost minimization problems** where we make **optimal decisions** within an interval.  

## **Key Characteristics of Interval DP Problems**  
1. **The problem involves a continuous range or sequence** (e.g., numbers from 1 to n, array elements).  
2. **The solution depends on choosing a partition point** within the interval.  
3. **Overlapping subproblems exist**, making **memoization** or **bottom-up DP** essential.  
4. **Optimal substructure is present**, meaning that the final solution is derived from smaller optimal solutions.  

## **General Approach to Solving Interval DP Problems**  

### **1. Define the State**  
The key step is defining a **dp[i][j]**, where:  
- `i` and `j` represent a **range** (interval).  
- `dp[i][j]` stores the **optimal solution** for the subproblem covering the interval `[i, j]`.  
- The goal is usually to compute `dp[1][n]` (or `dp[0][n-1]` if working with arrays).  

### **2. Base Case Handling**  
- If `i == j`, the interval has a **single element**, and often the result is **trivial** (e.g., 0 cost, 1 partition, etc.).  
- If `i > j`, the interval is **invalid**, so we return 0.  

### **3. Recursive Transition (Splitting the Interval)**  
We iterate over **possible split points k** where:  
- The interval `[i, j]` is split into two subproblems: `[i, k]` and `[k+1, j]`.  
- We take the **optimal combination** of both intervals.  
- The exact formula depends on the problem, but it often looks like:  
  \[
  dp[i][j] = \min_{k} \{ \text{cost}(i, j, k) + dp[i][k] + dp[k+1][j] \}
  \]
  or  
  \[
  dp[i][j] = \max_{k} \{ \text{value}(i, j, k) + dp[i][k] + dp[k+1][j] \}
  \]

### **4. Iterative Bottom-Up Computation (Optional)**  
Instead of recursion + memoization, we can use **bottom-up DP** by computing `dp[i][j]` for **small intervals first**, then gradually solving larger ones. The iteration order is typically:  
- **Length of the interval (L)**
- **Start of the interval (i)**
- **End of the interval (j = i + L - 1)**  
- **Splitting point (k)**  

### **5. Return the Final Answer**  
The solution is stored in `dp[1][n]` (or `dp[0][n-1]` for 0-based indexing).  

---

## **Template Code for Interval DP**  

```cpp
int dp[202][202];  // Adjust size as needed

int solve(int low, int high) {
    if (low >= high) return 0;  // Base case: No interval to process
    if (dp[low][high] != -1) return dp[low][high];  // Return cached result

    int best = INT_MAX;  // Or INT_MIN depending on min/max problem

    for (int k = low; k <= high; k++) {  // Try splitting at every point
        int cost = compute_cost(low, high, k);  // Define cost function as needed
        int left = solve(low, k - 1);
        int right = solve(k + 1, high);

        best = min(best, cost + max(left, right));  // Pick optimal choice
    }

    return dp[low][high] = best;  // Store result
}
```

---

## **Examples of Problems Using Interval DP**  

1. **Guessing Game (Min Cost to Guess a Number)** → Find the minimum cost to guarantee guessing a number.  
2. **Matrix Chain Multiplication** → Find the optimal way to multiply matrices to minimize cost.  
3. **Burst Balloons** → Find the maximum coins collected by bursting balloons in optimal order.  
4. **Palindrome Partitioning** → Minimize the number of cuts needed to partition a string into palindromes.  

---

## **Conclusion**  
The **Interval DP Pattern** is useful for problems that involve **partitioning a range and optimizing decisions**. By defining the **state**, **transition**, and using **memoization or bottom-up DP**, we can efficiently solve problems that would otherwise be infeasible via brute force.  

Would you like a **detailed example with full implementation**? 🚀
