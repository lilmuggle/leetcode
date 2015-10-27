class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;

    void backtrack(vector<int>& n, int i) {
        if(i == n.size()) {
            vector<int> tmp(v.begin(), v.end());
            sort(tmp.begin(), tmp.end());
            vec.push_back(tmp);
        }
        else {
            backtrack(n, i + 1);
            v.push_back(n[i]);
            backtrack(n, i + 1);
            v.pop_back();
            }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> n(nums.rbegin(), nums.rend());
        backtrack(n, 0);
        return vec;
    }
};
