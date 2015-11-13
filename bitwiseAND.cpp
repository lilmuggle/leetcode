class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0, tmp = 0;
        n -= m;
        if(n == 0)
            return m;
        for(int c = 0; c < 32; c++) {
            while(m & 1 == 0 && c < 32) {
                m >>= 1;
                c++;
            }
            if(m & 1 == 1) {
                tmp += pow(2, c);
                if(n < pow(2, c + 1) - tmp)
                    res += pow(2, c);
            }
            m >>= 1;
        }
        return res;
    }
};

//One-line
int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}
