class Solution {
public:
    vector<vector<int>> vec;
    vector<int> vn;
    int* flag;

    void backtrack(vector<int>& nums, int n) {
        if(n == nums.size())
            vec.push_back(vn);
        else {
            int i, tmp;
            for(i = 0; i < nums.size() ; i += tmp) {
                tmp = 1;
                if(flag[i]) {
                    for(int j=i;j<nums.size()-1&&nums[j]==nums[j + 1];j++)
                        tmp++;
                    vn.push_back(nums[i]);
                    flag[i] = 0;
                    backtrack(nums, n + 1);
                    vn.pop_back();
                    flag[i] = 1;
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int *p = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            p[i] = 1;
        flag = p;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        delete []p;
        return vec;
    }
};
