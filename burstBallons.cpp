class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int len = 2; len < nums.size(); len++) {
            for(int i = 0; i < nums.size() - len; i++) {
                int j = i + len;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }
        return dp[0][nums.size() - 1];
    }
};
