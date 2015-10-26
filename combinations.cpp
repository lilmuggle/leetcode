class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;
    int nsize, ksize;

    void backtrack(int n, int k) {
        if(k == ksize)
            vec.push_back(v);
        else {
            for(int i = n + 1; i <= nsize; i++) {
                v.push_back(i);
                backtrack(i, k + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ksize = k;
        nsize = n;
        if(n >= k)
            backtrack(0, 0);
        return vec;
    }
};
