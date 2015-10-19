class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) {
            m[i]++;
        }
        for(auto &w : m) {
            if(w.second == 1)
                return w.first;
        }
    }
};
