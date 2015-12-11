class Solution {
public:
    int minCut(string s) {
        if(s.empty())
            return 0;
        vector<int> dp(s.size() + 1);
        vector<vector<bool>> pal(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size(); i >= 0; i--) {
            dp[i] = s.size() - 1 - i;
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};

//After improvement
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
