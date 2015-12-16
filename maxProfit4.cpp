class Solution {
public:
    int profit(vector<int> prices) {
        int total = 0;
        for(int i = 0; i< prices.() - 1; i++)
            if(prices[i + 1] > prices[i])
                total += prices[i + 1] - prices[i];
        return total;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        if(k >= n / 2)
            return profit(prices);
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for(int kk = 1; kk <= k; kk++) {
            int tempMax = dp[kk - 1][0] - prices[0];
            for(int i = 1; i < n; i++) {
                dp[kk][i] = max(dp[kk][i - 1], prices[i] + tempMax);
                tempMax = max(tempMax, dp[kk - 1][i] - prices[i]);
            }
        }
        return dp[k][n - 1];
    }
};
