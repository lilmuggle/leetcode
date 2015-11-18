class Solution {
public:
    vector<vector<string>> res;
    vector<string> vn;
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
    void backtrack(string s, int len) {
        string str;
        if(len == s.size()) {
            res.push_back(vn);
            return;
        }
        for(int i = len; i < s.size(); i++) {
            str.push_back(s[i]);
            if(isPalindrome(str)) {
                vn.push_back(str);
                backtrack(s, i + 1);
                vn.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
