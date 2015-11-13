class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                sum = nums[start] + nums[end] + nums[i];
                if(sum == target)
                    return sum;
                else if(sum > target)
                    end--;
                else
                    start++;
                diff = abs(diff)<abs(sum-target)?diff:sum-target;
            }
        }
        return target + diff;
    }
};
