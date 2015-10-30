class Solution {
public:
    int partition(vector<int>& A) {
        int n = A.size(), q = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] > 0)
                swap(A[q++], A[i]);
        }
        return q;
    }

    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();
        if(n == 0)
            return 1;
        int k = partition(nums);
        int first_missing_Index = k;
        for(i = 0; i < k; i++) {
            int temp = abs(nums[i]);
            if(temp <= k)
                nums[temp-1]=nums[temp-1]<0?nums[temp-1]: -nums[temp-1];
        }
        for(i=0; i < k; i++) {
            if(nums[i] > 0) {
                first_missing_Index = i;
                break;
            }
        }
        return ++first_missing_Index;
    }
};

//Another
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for(int i = 0; i < n; i++)
            if(nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
