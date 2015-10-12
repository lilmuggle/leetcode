class Solution {
public:
    string countAndSay(int n) {
        int i, c;
        string s1 = "1", s2;
        for(; n > 1; n--)
        {
            for(i = 0; s1[i] != '\0'; i++)
            {
                c = 1;
                while(s1[i + 1] != '\0' && s1[i] == s1[i + 1])
                {
                    c++;
                    i++;
                }
                s2 += std::to_string(c) + s1[i];
            }
            s1 = s2;
            s2.clear();
        }
        return s1;
    }
};
