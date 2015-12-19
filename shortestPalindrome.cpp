class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size(), longest;
        if(len < 2)
            return s;
        for(int k = 0; k <= len / 2;) {
            int i = k, j = k;
            while(j < len - 1 && s[j + 1] == s[j])
                j++;
            k = j + 1;
            while(j < len - 1 && i > 0 && s[j + 1] == s[i - 1])
                j++, i--;
            if(i == 0)
                longest = j - i + 1;
        }
        string tmp = s.substr(longest);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }
};

//Using KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};
