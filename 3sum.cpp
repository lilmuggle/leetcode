class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            while(i != 0 && i < nums.size() && nums[i] == nums[i - 1])
                i++;
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                if(nums[start] + nums[end] + nums[i] == 0) {
                    vector<int> solution;
                    solution.push_back(nums[i]);
                    solution.push_back(nums[start]);
                    solution.push_back(nums[end]);
                    res.push_back(solution);
                    start++, end--;
                    while(start < end && nums[start] == nums[start - 1])
                        start++;
                    while(end > start && nums[end] == nums[end + 1])
                        end--;
                }
                else if(nums[start] + nums[end] + nums[i] > 0)
                    end--;
                else
                    start++;
            }
        }
        return res;
    }
};
