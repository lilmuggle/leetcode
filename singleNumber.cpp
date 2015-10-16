class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) {
            m[i]++;
        }
        for(auto &w : m) {
            if(m.second == 1)
                return m.first;
        }
    }
};
