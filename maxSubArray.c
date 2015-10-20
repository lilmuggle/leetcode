int maxSubArray(int* nums, int numsSize) {
    int i, sum = 0, maxsum = -2147483648;
    for(i = 0; i < numsSize; i++) {
        sum += nums[i];
        if(sum > maxsum)
            maxsum = sum;
        if(sum < 0)
            sum = 0;
    }
    return maxsum;
}

//divide-and-conquer
#define m -2147483648
#define max(x,y) (x>y)?x:y
int maxSubSum(int *n, int left, int right) {
    int maxl, maxr, maxlb, maxrb, lb, rb, center, i;
    if(left == right)
        return n[left];
    center = left + (right - left) / 2;
    maxl = maxSubSum(n, left, center);
    maxr = maxSubSum(n, center + 1, right);
    maxlb = lb = m;
    for(i = center; i >= left; i--) {
        lb += n[i];
        if(lb > maxlb)
            maxlb = lb;
    }
    maxrb = rb = m;
    for(i = center + 1; i <= right; i++) {
        rb += n[i];
        if(rb > maxrb)
            maxrb = rb;
    }
    return max(max(mal, maxr), maxlb + maxrb);
}

int maxSubArray(int* nums, int numsSize) {
    return maxSubSum(nums, 0, numsSize - 1);
}

//After improvement
public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int max = dp[0];

        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }

        return max;
}
