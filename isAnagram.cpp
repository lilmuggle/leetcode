//Original
class Solution {
public:
    unordered_map<char, int> sMap;
    bool isAnagram(string s, string t) {
        for(char c1: s)
        {
            sMap[c1]++;
        }
        for(char c2: t)
        {
            if(--sMap[c2] < 0)
                return false;
        }
        for(const auto &w : sMap)
        {
            if(w.second > 0)
                return false;
        }
        return true;
    }
};

//After improvement
bool isAnagram(string s, string t) {
    int i;
    int alp[26] = {0};

    if(s.length() != t.length())
        return false;
    for(int i = 0; i < s.length(); i++)
    {
        alp[s[i] - 97]++;
        alp[t[i] - 97]--;
    }
    for(i = 0; i < 26; i++)
    {
        if(alp[i] > 0)
            return false;
    }
    return true;
}
