class Solution {
public:
    int mySqrt(int x) {
        if(x < 0)
            return INT_MIN;
        int low = 0, high = 46340, mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(mid * mid == x)
                return mid;
            if(mid * mid < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low * low <= x ? low : --low;
    }
};
