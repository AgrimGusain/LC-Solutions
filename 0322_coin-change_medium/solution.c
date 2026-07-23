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
