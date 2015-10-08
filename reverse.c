int reverse(int x)
{
    long long r;

    while(x)
    {
        r = r * 10 + x % 10;
        x /= 10;
    }
    if(r > INT_MAX || r < INT_MIN)
        r = 0;
    return r;
}
