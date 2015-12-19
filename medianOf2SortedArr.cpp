class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        int i, j, low = 0, high = m, mid1, mid2, a, b;
        while(low <= high) {
            i = low + (high - low) / 2;
            j= (m + n + 1) / 2 - i;
            if(j > 0 && i < m && nums2[j - 1] > nums1[i])
                low = i + 1;
            else if(i > 0 && j < n && nums1[i - 1] > nums2[j])
                high = i - 1;
            else
                break;
        }
        a = i == 0 ? INT_MIN : nums1[i - 1];
        b = j == 0 ? INT_MIN : nums2[j - 1];
        mid1 = max(a, b);
        if((m + n) & 1)
            return mid1;
        a = i == m ? INT_MAX : nums1[i];
        b = j == n ? INT_MAX : nums2[j];
        mid2 = min(a, b);
        return (mid1 + mid2) / 2.0;
    }
};
