//DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ')') {
                if(s[i - 1] == '(')
                   dp[i] = 2 + (i > 1 ? dp[i - 2] : 0);
                else {
                    if(i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = 2 + dp[i - 1] + (i - dp[i -1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                }
                len = max(len, dp[i]);
            }
        }
        return len;
    }
};

//Using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        stack<int> stk;
        s += "x";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' && !stk.empty() && s[stk.top()] == '(')
                stk.pop();
            else {
                len = max(len, i - 1 - (stk.empty() ? -1 : stk.top()));
                stk.push(i);
            }
        }
        return len;
    }
};
