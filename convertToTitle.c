char* converToTitle(int n)
{
    int i, res, tmp, nsize = 0;
    char *c;

    tmp = n;
    while(tmp > 0)
    {
        tmp = (tmp - 1) / 26;
        nsize++;
    }
    c = (char *)malloc(sizeof(char) * nsize);
    i = nsize - 1;
    while(i >= 0)
    {
        res = --n % 26;
        n /= 26;
        c[i] = (char)(res + 65);
        i--;
    }
    return c;
}
