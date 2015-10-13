class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        int i, j, len = s.size();
        for(i = 0; i < len; i++) {
            if('A'<=s[i]&&s[i]<='Z')
                t += s[i] + 32;
            else if(('a'<=s[i]&&s[i]<='z')||('0'<=s[i]&&s[i]<='9'))
                t += s[i];
        }
        len = t.size();
        j = len - 1;
        len /= 2;
        for(i = 0; i < len; i++, j--)
            if(t[i] != t[j])
                return false;
        return true;
    }
};
