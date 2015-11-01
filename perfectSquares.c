#define m 2147483647
int numSquares(int n) {
    int *a = malloc(sizeof(int) * n);
    for(int i = 1; i <= n; i++) {
        int s = sqrt(i);
        if(s * s == i)
            a[i - 1] = 1;
        else {
            int min = m;
            for(int j=s; j>0; j--) {
                int tmp=1+a[i-1-j*j];
                min = tmp<min?tmp:min;
            }
            a[i - 1] = min;
        }
    }
    return a[n - 1];
}
