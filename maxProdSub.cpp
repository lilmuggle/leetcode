class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int prod = nums[0], p = nums[0], n = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 0)
                p = n = 0;
            else if(nums[i] > 0) {
                p = max(p, 1) * nums[i];
                n = n * nums[i];
            }
            else {
                int tmp = p;
                p = min(n, 1) * nums[i];
                n = max(tmp, 1) * nums[i];
            }
            prod = max(prod, p);
        }
        return prod;
    }
};
