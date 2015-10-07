int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int * ret;

    for(int i = digitsSize - 1; i >= 0; i--)
    {
        if(++digits[i] <= 9)
        {
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    *returnSize = digitsSize + 1;
    ret = (int *)malloc(sizeof(int) * (*returnSize));
    memset(ret, 0, sizeof(int) * (*returnSize));
    ret[0] = 1;
    return ret;
}
