class Solution {
public:
    int upperlim, sum;

    void test(int row, int ld, int rd) {
        if(row != upperlim) {
            int pos = upperlim & ~(row | ld | rd);
            while(pos) {
                int p = pos & -pos, j = -1;
                pos -= p;
                test(row + p, (ld + p) << 1, (rd + p) >> 1);
            }
        }
        else
            sum++;
    }

    int totalNQueens(int n) {
        sum = 0;
        upperlim = (1 << n) - 1;
        test(0, 0, 0);
        return sum;
    }
};
