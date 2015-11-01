class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;

    void backtrack(vector<int>& n, int start) {
        vec.push_back(v);
        int tmp;
        for(int i = start; i < n.size(); i += tmp) {
            tmp = 1;
            for(int j=i;j<n.size()-1&&n[j]==n[j + 1];j++)
                tmp++;
            v.push_back(n[i]);
            backtrack(n, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return vec;
    }
};
