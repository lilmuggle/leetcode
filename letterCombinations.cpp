class Solution {
public:
    vector<string> res;
    string str;
    string ss[10]  = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(string s, int n) {
        if(n == s.size())
            res.push_back(str);
        else {
            string chars = ss[s[n] - '0'];
            for(int i = 0; i < chars.size(); i++) {
                str.push_back(chars[i]);
                backtrack(s, n + 1);
                str.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        backtrack(digits, 0);
        return res;
    }
};

//iterative solution
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
