//Original
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s, tmp;
        int i = 0, j, k, len = strs.size(), len2;

        if(len == 0)
            return s;
        if(len == 1)
            return strs[0];
        while(strs[0][i]!='\0'&&strs[1][i]!='\0'&&strs[0][i]==strs[1][i])
                s += strs[0][i++];
        for(i = 2; i < len; i++)
        {
            len2 = s.size();
            for(j=0;strs[i][j]!='\0'&&j<len2&&strs[i][j]==s[j];j++){}
            k = 0;
            while(k < j)
                tmp += s[k++];
            s = tmp;
            tmp.clear();
        }
        return s;
    }
};

//After improvement
string longestCommonPrefix(vector<string>& strs) {
    string s="";
    int len = strs.size();
    for(int i=0;len>0;s+=strs[0][i++])
        for(int j=0;j<len;j++)
            if(i>=strs[j].size()||(j>0&&strs[j-1][i]!=strs[j][i]))
               return s;
    return s;
}
