class Solution {
public:
    bool isIsomorphic(string s, string t) {
        string s1[95], t1[95], tmp;
        int i, len = s.size();
        for(i = 0; i < len; i++)
        {
            s1[s[i] - 32] += i + '0';
            t1[t[i] - 32] += i + '0';
            if(s1[s[i] - 32] != t1[t[i] - 32])
                return false;
        }
        return true;
    }
};
