class Solution {
public:
    vector<vector<int>> vec;
    vector<int> vn;
    int* flag;

    void backtrack(vector<int>& nums, int n) {
        if(n == nums.size())
            vec.push_back(vn);
        else {
            for(int i = 0; i < nums.size() ; i++) {
                if(flag[i]) {
                    vn.push_back(nums[i]);
                    flag[i] = 0;
                    backtrack(nums, n + 1);
                    vn.pop_back();
                    flag[i] = 1;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int *p = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            p[i] = 1;
        flag = p;
        backtrack(nums, 0);
        delete []p;
        return vec;
    }
};

//Another
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};
