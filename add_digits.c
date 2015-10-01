//10^n กิ 1 (mod 9)
int addDigits(int num)
{
    int res;

    if(num == 0)
        return 0;
    res = num % 9;
    if(res == 0)
        return 9;
    return res;
}
