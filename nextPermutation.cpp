class Solution {
public:
    void replace(vector<int>& a, int low) {
        int high = a.size() - 1, tmp = low - 1;
        while(low < high - 1) {
            int mid = low + (high - low) / 2;
            if(a[mid] > a[tmp])
                low = mid;
            else
                high = mid - 1;
        }
        if(a[high] > a[tmp])
            low = high;
        swap(a[low], a[tmp]);
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                replace(nums, i);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

//O(n)
class Solution {
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1;
        for (int i = nums.size() - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());

