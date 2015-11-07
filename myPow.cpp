class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n < 0) {
            n = -n;
            x = 1 / x;
        }
        if((n & 1) == 0)
            return myPow(x * x, n / 2);
        else
            return myPow(x * x, n / 2) * x;
    }
};
