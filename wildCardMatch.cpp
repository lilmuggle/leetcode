class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, sMatch, pMatch = -1;
        while(i < s.size()) {
            if(j < p.size() && p[j] == '*') {
                sMatch = i;
                pMatch = j++;
            }
            else if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if(pMatch >= 0){
                i = ++sMatch;
                j = pMatch + 1;
            }
            else
                return false;
        }
        while(j < p.size() && p[j] == '*')
            j++;
        return j == p.size();
    }
};
