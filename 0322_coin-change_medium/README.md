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
The given code is a solution to the "Coin Change" problem, which is a classic dynamic programming problem. The code uses a top-down approach with memoization to find the fewest number of coins that make up a given amount.

Here's a step-by-step breakdown:

1. The `coinChange` function initializes a dynamic programming (DP) array `dp` of size `amount + 1` with all elements set to `-1`. This array will store the minimum number of coins required to make up each amount from `0` to `amount`.
2. The `helper` function is a recursive function that takes the `coins`, `amount`, and `dp` array as parameters.
3. The base cases for the recursion are:
   - If `amount` is `0`, return `0` because we need `0` coins to make up an amount of `0`.
   - If `amount` is less than `0`, return `INT_MAX` because it's not possible to make up a negative amount with coins.
   - If `dp[amount]` is not `-1`, return the value stored in `dp[amount]` because we've already computed the minimum number of coins required for this amount.
4. The function then iterates over each coin in the `coins` array and recursively calls itself with `amount - coin` as the new amount.
5. If the recursive call returns a value that is not `INT_MAX`, it means we can make up the new amount with coins. In this case, we update the `ans` variable with the minimum of its current value and `res + 1`, where `res` is the result of the recursive call.
6. Finally, the function stores the computed value in `dp[amount]` and returns it.
7. The `coinChange` function calls the `helper` function with the initial `amount` and returns the result. If the result is `INT_MAX`, it means we cannot make up the `amount` with the given coins, so the function returns `-1`.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(amount * n), where n is the number of coins. This is because in the worst case, we need to iterate over all coins for each amount from `1` to `amount`.
- **Space Complexity:** The space complexity is O(amount), which is the space required to store the DP array.

## Optimizations
The given code is already optimal because it uses a top-down approach with memoization, which avoids redundant computations. However, we can consider a few edge cases:

- We should check if the `coins` array is empty. If it is, we should return `-1` immediately because we cannot make up any amount with no coins.
- We should also check if the `amount` is negative. Although the code handles this case correctly, it's worth noting that the problem statement assumes `amount` is non-negative.

## Interview Explanation
Here's a conversational script to explain the solution to an interviewer:

"So, the problem we're trying to solve is the 'Coin Change' problem. We're given an array of coins and an amount, and we need to find the fewest number of coins that make up that amount.

One approach to solve this problem is to use dynamic programming. The idea is to build up a table that stores the minimum number of coins required to make up each amount from 0 to the given amount.

We can use a top-down approach with memoization to avoid redundant computations. We'll create a recursive function that takes the coins, amount, and a DP array as parameters.

The base cases for the recursion are when the amount is 0, in which case we need 0 coins, and when the amount is less than 0, in which case it's not possible to make up the amount with coins.

For each coin, we'll recursively call the function with the amount minus the coin, and if the recursive call returns a value that is not infinity, we'll update our answer with the minimum of its current value and the result of the recursive call plus 1.

We'll store the computed value in the DP array and return it. The main function will call the recursive function with the initial amount and return the result. If the result is infinity, it means we cannot make up the amount with the given coins, so we'll return -1.

In terms of complexity, the time complexity is O(amount * n), where n is the number of coins, and the space complexity is O(amount), which is the space required to store the DP array.

I've considered a few edge cases, such as checking if the coins array is empty and if the amount is negative, but the code handles these cases correctly.

Overall, this solution uses a top-down approach with memoization to efficiently find the fewest number of coins that make up a given amount."