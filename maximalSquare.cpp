class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int edge = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '0')
                    continue;
                for(int r=i-1,c=j-1;i!=0&&j!=0&&i-r<=dp[i-1][j-1]&&matrix[r][j]!='0'&&matrix[i][c]!='0';r--,c--)
                    dp[i][j]++;
                edge = max(++dp[i][j], edge);
            }
        return edge * edge;
    }
};

//After improvement
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0;
            pre = temp;
        }
    }
    return maxsize * maxsize;
}
