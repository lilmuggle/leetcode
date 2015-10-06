class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        unordered_set<int> num;
        for(int i: nums)
        {
            if(num.count(i) == 0)
                num.insert(i);
            else
                return true;
        }
        return false;
    }
};
