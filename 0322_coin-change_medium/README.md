# Coin Change

## Problem Description
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:

Input: coins = [2], amount = 3
Output: -1


Example 3:

Input: coins = [1], amount = 0
Output: 0


 
Constraints:


	1 <= coins.length <= 12
	1 <= coins[i] <= 231 - 1
	0 <= amount <= 104



## My Code
```cpp
class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int coin : coins) {
            int res = helper(coins, amount - coin, dp);
            if(res != INT_MAX) ans = min(ans, res + 1);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = helper(coins, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};

```

## Code Explanation
The provided code is a solution to the "Coin Change" problem on LeetCode. It utilizes dynamic programming to find the fewest number of coins needed to make up a given amount. Here's a step-by-step breakdown of how it works:
1. The `helper` function takes in a vector of coins, an amount, and a dynamic programming (DP) vector as parameters.
2. If the amount is 0, it returns 0, because we need 0 coins to make up an amount of 0.
3. If the amount is less than 0, it returns `INT_MAX`, indicating that it's not possible to make up the amount with the given coins.
4. If the DP vector already contains a value for the current amount, it returns that value, avoiding redundant calculations.
5. It then iterates through each coin in the coins vector, subtracting the coin value from the current amount and recursively calling the `helper` function with the updated amount.
6. If the recursive call returns a value that is not `INT_MAX`, it updates the minimum number of coins needed (`ans`) by taking the minimum of the current `ans` and the result of the recursive call plus 1.
7. The updated `ans` value is then stored in the DP vector for the current amount and returned.
8. The `coinChange` function initializes a DP vector with a size of `amount + 1`, fills it with -1, and calls the `helper` function with the initial amount.
9. Finally, it checks if the result from the `helper` function is `INT_MAX` and returns -1 if it is, indicating that it's not possible to make up the amount with the given coins. Otherwise, it returns the result.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(amount * n), where n is the number of coins. This is because in the worst case, we need to iterate through each coin for each amount from 1 to the target amount.
- **Space Complexity:** The space complexity is O(amount), which is the size of the DP vector used to store the results of subproblems.

## Optimizations
The provided code is already quite optimized, as it uses dynamic programming to avoid redundant calculations. However, there are a few potential optimizations to consider:
- **Early Termination:** If the amount is less than the smallest coin, we can immediately return -1, as it's not possible to make up the amount.
- **Coin Sorting:** Sorting the coins in descending order before the dynamic programming loop can potentially reduce the number of iterations needed, as we can stop exploring branches that exceed the remaining amount.

## Interview Explanation
Here's a script for explaining this solution to an interviewer:
"Okay, so the problem is asking us to find the fewest number of coins needed to make up a given amount using an infinite number of coins of different denominations. To approach this, I used dynamic programming, which is a technique for solving complex problems by breaking them down into smaller subproblems and storing the results of these subproblems to avoid redundant calculations.
"The key idea here is to create a DP vector, which is an array that stores the minimum number of coins needed to make up each amount from 0 to the target amount. We initialize this vector with -1, indicating that we don't know the answer yet.
"Then, we define a helper function that takes in the vector of coins, the current amount, and the DP vector. This function checks if we've already computed the result for the current amount, and if so, returns it. Otherwise, it tries using each coin to make up the current amount, recursively calling itself with the updated amount.
"If the recursive call returns a valid result, we update the minimum number of coins needed and store it in the DP vector. Finally, we return the result for the current amount.
"In the main function, we initialize the DP vector, call the helper function with the initial amount, and check if the result is valid. If it is, we return the result; otherwise, we return -1, indicating that it's not possible to make up the amount with the given coins.
"The time complexity of this solution is O(amount * n), where n is the number of coins, because we need to iterate through each coin for each amount. The space complexity is O(amount), which is the size of the DP vector.
"I chose dynamic programming for this problem because it allows us to avoid redundant calculations and efficiently explore the search space. By storing the results of subproblems, we can avoid recomputing them and reduce the overall time complexity of the solution."