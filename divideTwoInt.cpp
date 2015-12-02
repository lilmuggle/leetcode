//bit manipulation
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == -2147483648 && divisor == -1))
            return INT_MAX;
        int res = 0, flag = 1;
        if((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            flag = 0;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while(dvd >= dvs) {
            long long tmp = dvs, multiple = 1;
            while(dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            res += multiple;
            dvd -= tmp;
        }
        return flag == 0 ? res : -res;
    }
};
