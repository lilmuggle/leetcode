class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int dp1[prices.size()], dp2[prices.size()];
        int low = prices[0];
        dp1[0] = 0;
        for(int i = 1; i < prices.size(); i++) {
            low = min(low, prices[i]);
            dp1[i] = max(dp1[i - 1], prices[i] - low);
        }
        int high = prices[prices.size() - 1];
        dp2[prices.size() - 1] = 0;
        for(int i = prices.size() - 2; i >= 0; i--) {
            high = max(high, prices[i]);
            dp2[i] = max(dp2[i + 1], high - prices[i]);
        }
        int res = 0;
        for(int i = 0; i < prices.size(); i++)
            res = max(res, dp1[i] + dp2[i]);
        return res;
    }
};
