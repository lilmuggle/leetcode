class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int index = 0, res = 0;
        vector<int> tmp{0};
        while(1) {
            index = tmp[0];
            for(int i = 1; i < tmp.size(); i++)
                if(tmp[i] + nums[tmp[i]] > index + nums[index])
                    index = tmp[i];
            tmp.clear();
            res++;
            for(int i = 1; i <= nums[index]; i++) {
                if(i + index >= nums.size() - 1)
                    return res;
                tmp.push_back(i + index);
            }
        }
    }
};
