class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++) {
            if(s.size() - i <= res.size() / 2)
                break;
            int left = i - 1, right = i + 1;
            while(right < s.size() && s[i] == s[right])
                 right++;
            while(left >= 0 && right < s.size()) {
                if(s[left] != s[right])
                    break;
                left--, right++;
            }
            res=right-left-1>res.size()?s.substr(left + 1, right - left - 1):res;
        }
        return res;
    }
};
