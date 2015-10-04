int climbStairs(int n)
{
    int a0, a1, a2, tmp;
    int i;

    a0 = 1;
    a1 = 1;

    if(n == 1)
        return 1;
    for(i = 2; i <= n; i++)
    {
        a2 = a0 + a1;
        a0 = a1;
        a1 = a2;
    }
    return a2;
}
