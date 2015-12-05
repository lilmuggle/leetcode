class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k <= 0 || t < 0)
            return false;
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(i > k)
                s.erase(nums[i - k - 1]);
            auto x = s.lower_bound(nums[i] - t);
            if(x != s.end() && *x - nums[i] <= t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
