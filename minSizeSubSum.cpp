//O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX, start = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minlen = minlen<(i-start+1)?minlen:(i-start+1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

//O(nlogn)
class Solution {
public:
    int find(vector<int> a, int high, int tar) {
        int low = 0;
        while(low < high) {
            int mid = low + (high -  low) / 2;
            if(a[mid] > tar)
                high = mid - 1;
            else {
                if(mid == low)
                    return mid;
                low = mid;
            }
        }
        return a[low] <= tar ? low : -1;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] += i == 0 ? 0 : nums[i - 1];
            if(nums[i] >= s) {
                int len = i - find(nums, i - 1, nums[i] - s);
                minlen = minlen < len ? minlen : len;
                if(minlen == 1)
                    return 1;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
69743
[3741,1493,7770,3018,5398,6215,8601,
6244,7551,2587,2254,3607,1147,5184,9173,
8680,8610,1597,1763,7914,3441,7006,1318,7044,
7267,8206,9684,4814,9748,4497,2239]
