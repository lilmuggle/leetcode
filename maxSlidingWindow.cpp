class Solution {
public:
    int helper(vector<int> n, int start, int end) {
        int m = INT_MIN;
        for(int i = start; i < end; i++)
            m = max(m, n[i]);
        return m;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k == 0)
            return res;
        for(int i = 0; i < nums.size() - k + 1; i++)
            res.push_back(helper(nums, i, i + k));
        return res;
    }
};

//After improvement
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
