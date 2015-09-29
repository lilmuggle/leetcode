int addDigits(int num)
{
    int s, y;
    s = num / 10;
    while(s != 0)
    {
        y = num % 10;
        num = y + s;
        s = num / 10;
    }
    return num;
}
