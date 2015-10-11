class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0, j;
        string s[26];

        for(char c: pattern)
        {
            string word;
            while(str[i] != ' ' && str[i] != '\0')
                word += str[i++];
            if(str[i] != '\0')
                i++;
            if(!s[c - 97].empty())
            {
                if(s[c - 97] != word)
                    return false;
            }
            else
            {
                for(j = 0; j < 26; j++)
                {
                    if(word == s[j])
                        return false;
                }
                s[c - 97] = word;
            }
        }
        if(str[i] != '\0')
            return false;
        return true;
    }
};
