class Solution {
public:
    int helper(string s, int n) {
        int len = 0;
        vector<int> a(95, -1);
        for(int i = n; i < s.size(); i++) {
            if(a[s[i] - 32] != -1) {
                int tmp = helper(s, a[s[i] - 32] + 1);
                return len > tmp ? len : tmp;
            }
            else {
                a[s[i] - 32] = i;
                len++;
            }
            if(len == 95)
                break;
        }
        return len;
    }
    int lengthOfLongestSubstring(string s) {
        return helper(s, 0);
    }
};

//O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, start = 0;
        vector<int> a(95, -1);
        for(int i = 0; i < s.size(); i++) {
            start = max(a[s[i] - 32] + 1, start);
            a[s[i] - 32] = i;
            maxlen = max(maxlen, i + 1 - start);
            if(maxlen == 95)
                break;
        }
        return maxlen;
    }
};
