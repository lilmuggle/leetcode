//Original
bool isPalindrome(int x)
{
    int tmp;
    long long sum = 0;

    if(x < 0)
        return false;
    tmp = x;
    while(x)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    if(sum > INT_MAX)
        return false;
    else
    {
        if(sum == tmp)
            return true;
        else
            return false;
    }
}

//After improvement
bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int sum = 0;
    while(x > sum)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return (x == sum) || (x == sum / 10);
}
