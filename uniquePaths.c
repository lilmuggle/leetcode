int uniquePaths(int m, int n) {
    int i, j, x;
    x = m > n ? m : n;
    long long prod = 1;
    for(i = (m + n -2), j = 1; i > (x - 1); i--, j++) {
        prod *= i;
        prod /= j;
    }
    return (int)prod;
}
