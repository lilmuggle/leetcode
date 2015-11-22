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

