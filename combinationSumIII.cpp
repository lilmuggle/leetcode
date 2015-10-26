class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;
    int k, n;

    void backtrack(int last, int num, int sum) {
        if(num > k)
            return;
        if(sum == n && num == k)
            vec.push_back(v);
        else {
            for(int i = last + 1; i < 10; i++) {
                if(sum + i <= n) {
                    v.push_back(i);
                    backtrack(i, num + 1, sum + i);
                    v.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k <= 9 && n <= 45) {
            this->k = k;
            this->n = n;
            backtrack(0, 0, 0);
        }
        return vec;
    }
};
