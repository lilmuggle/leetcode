struct bucket {
    int minEle;
    int maxEle;
    bool empty;
    bucket(): minEle(INT_MAX), maxEle(0), empty(true) {};
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int bucketCnt, bucketLen, gap, minimum = INT_MAX, maximum = 0;
        for(int i : nums) {
            minimum = min(i, minimum);
            maximum = max(i, maximum);
        }
        bucketLen = (maximum - minimum) / (nums.size() - 1) + 1;
        bucketCnt = (maximum - minimum) / bucketLen + 1;
        vector<bucket> b(bucketCnt, bucket());
        for(int x : nums) {
            int index = (x - minimum) / bucketLen;
            b[index].minEle = min(b[index].minEle, x);
            b[index].maxEle = max(b[index].maxEle, x);
            b[index].empty = false;
        }
        bucket pre = b[0];
        gap = pre.maxEle - pre.minEle;
        for(int i = 1; i < bucketCnt; i++) {
            if(b[i].empty)
                continue;
            gap = max(gap, b[i].minEle - pre.maxEle);
            pre = b[i];
        }
        return gap;
    }
};
