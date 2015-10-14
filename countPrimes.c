#include "stdio.h"

int countPrimes(int n) {
    int i, j, count, *flag;
    flag = (int *)malloc(sizeof(int) * (n - 1));
    if(n <= 1)
        return 0;
    for(i = 0; i < n - 1; i++)
        flag[i] = 1;
    count = n - 2;
    for(i = 2; i * i <= n; i++) {
        if(flag[i - 1]) {
            for(j = i + i; j <= n - 1; j += i) {
                if(flag[j -1]) {
                    flag[j - 1] = 0;
                    count--;
                }
            }
        }
    }
    return count;
}

void main() {
    int n;
    scanf("%d", &n);
    n = countPrimes(n);
    printf("%d", n);
}
