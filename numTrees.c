//Original
int numTrees(int n) {
    long long pre = 1, cur, prod;
    for(int i = 1; i <= n; i++) {
        prod = (4 * i -2) * pre;
        cur = prod / (i + 1);
        pre = cur;
    }
    int c = cur;
    return c;
}

//After improvement
int numTrees(int n) {
    int i, j, *g;
    g = malloc(sizeof(int) * (n + 1));
    g[0] = g[1] = 1;
    for(i = 2; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            g[i] += g[j - 1] * g[i - j];
        }
    }
    return g[n];
}
