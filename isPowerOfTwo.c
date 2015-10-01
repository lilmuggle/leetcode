bool isPowerOfTwo(int n)
{
    while(n % 2 == 0 && n != 0)
        n /= 2;
    if(n == 1)
        reuturn true;
    return false;
}
