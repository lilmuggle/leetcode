class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= p.size(); j++)
            if(p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') {
                    /*int cnt = 0;
                    while(i >= cnt && (cnt == 0 || p[j - 2] == '.' || p[j - 2] == s[i - cnt])) {
                        if(dp[i - cnt][j - 2]) {
                            dp[i][j] = true;
                            break;
                        }
                        cnt++;
                    }*/
                    //After improvement
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};


//Recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();

        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
