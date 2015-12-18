class Solution {
public:
    vector<string> res;
    void backtrack(string n, int i, string cur, int t, long eval, long mult) {
        if(i == n.size()) {
            if(eval == t)
                res.push_back(cur);
            return;
        }
        for(int j = 0; j < n.size() - i; j++) {
            if(j != 0 && n[i] == '0')
                break;
            string str = n.substr(i, j + 1);
            long tmp = stol(str);
            if(i == 0)
                backtrack(n, i + j + 1, cur + str, t, tmp, tmp);
            else {
                backtrack(n, i + j + 1, cur + "+" + str, t, eval + tmp, tmp);
                backtrack(n, i + j + 1, cur + "-" + str, t, eval - tmp, -tmp);
                backtrack(n, i + j + 1, cur + "*" + str, t, eval - mult + mult * tmp, mult * tmp);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        backtrack(num, 0, "", target, 0, 0);
        return res;
    }
};
