class Solution {
public:
    int len = 0;
    string res;
    int getDigit(string s, int n) {
        return n>=s.size()?s[0]-'0':s[n]-'0';
    }
    void helper(vector<string> str, int n) {
        vector<vector<string>> b(10, vector<string>());
        if(n == len) {
            for(string x : str)
                b[x.size()>1?x[x.size()-2]-'0':x[0]-'0'].push_back(x);
            for(auto x : b)
                for(string s : x)
                    res += s;
            return;
        }
        for(string x : str)
            b[getDigit(x, n)].push_back(x);
        for(int i = 9; i >= 0; i--) {
            if(b[i].size() == 0) {}
            else if(b[i].size() == 1)
                res += b[i][0];
            else
                helper(b[i], n + 1);
        }
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i : nums) {
            str.push_back(to_string(i));
            len = max(len, (int)to_string(i).size());
        }
        helper(str, 0);
        return res[0] == '0' ? "0" : res;
    }
};

//Another
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
