class Solution {
public:
    int numDecodings(string s) {
        int tmp, pre = 0, cur = 1;
        for(int i = 0; i < s.size(); i++) {
            tmp = cur;
            if(s[i] == '0') {
                if(i == 0 || (s[i - 1] != '1' && s[i - 1] != '2'))
                    return 0;
                if(s[i - 2] == '1' || s[i - 2] == '2')
                    cur = pre;
            }
            else {
                if(i > 0)
                    if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] > '0' && s[i] < '7'))
                        cur += pre;
            }
            pre = tmp;
        }
        return s.size() == 0 ? 0 : cur;
    }
};
