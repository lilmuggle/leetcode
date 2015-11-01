//Using sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[--k];
    }
};

//Using heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        while(k > 1) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            k--;
        }
        return nums[0];
    }
};

//Using quickselect
class Solution {
public:
    void Qselect(vector<int>& a, int k, int left, int right) {
        if(left < right) {
        int pivot = a[left];
        int i = left + 1;
        int j = right;
        for(;;) {
            while(i <= j && a[i] > pivot)
                i++;
            while(i <= j && a[j] <= pivot)
                j--;
            if(i < j)
                swap(a[i], a[j]);
            else
                break;
        }
        swap(a[left], a[j]);
        if(k > i)
            Qselect(a, k, j + 1, right);
        else if(k < i)
            Qselect(a, k, left, j - 1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        Qselect(nums, k, 0, nums.size() - 1);
        return nums[k - 1];
    }
};
