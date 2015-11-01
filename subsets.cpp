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

//Another backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        genSubsets(nums, 0, sub, subs);
        return subs;
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};

//Bit Manipulation
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};
