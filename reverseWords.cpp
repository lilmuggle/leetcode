class Solution {
public:
    void reverseWords(string &s) {
        string tmp, res;
        stringstream ss(s);
        while(getline(ss, tmp, ' ')) {
            if(tmp == "") continue;
            res = tmp + " " + res;
        }
        if(res.size() > 0)
            res.pop_back();
        s = res;
    }
};
