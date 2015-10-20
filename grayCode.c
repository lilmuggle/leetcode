/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int i, *a, *b, num = pow(2, n);
    a = malloc(sizeof(int) * num);
    if(n == 0) {
        a[0] = 0;
        *returnSize = num;
        return a;
    }
    b = grayCode(n - 1, returnSize);
    for(i = 0; i < *returnSize; i++) {
        a[i] = b[i];
        a[num - i - 1] = b[i] + *returnSize;
    }
    *returnSize = num;
    return a;
}

//Others
vector<int> grayCode(int n)
{
    vector<int> result(1, 0);
    for (int i = 0; i < n; i++) {
        int curCount = result.size();
        // push back all element in result in reverse order
        while (curCount) {
            curCount--;
            int curNum = result[curCount];
            curNum += (1<<i);
            result.push_back(curNum);
        }
    }
    return result;
}
