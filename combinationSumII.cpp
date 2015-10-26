class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;
    int t;

    void backtrack(vector<int>& c, int last, int sum) {
        if(sum == t)
            vec.push_back(v);
        else {
            for(int i = last + 1; i < c.size(); i++) {
                if(sum + c[i] <= t) {
                    if(i > -1 && c[i - 1] == c[i] && i > last + 1)
                        continue;
                    v.push_back(c[i]);
                    backtrack(c, i, sum + c[i]);
                    v.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        t = target;
        backtrack(candidates, -1, 0);
        return vec;
    }
};
