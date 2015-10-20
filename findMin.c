int findMin(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    int i, minele;
    minele = nums[0];
    for(i = 1; i < numsSize; i++) {
        if(nums[i] < minele) {
            minele = nums[i];
            break;
        }
    }
    return minele;
}

//binary search
int findMin(vector<int> &num) {
    int start = 0,end = num.size()-1;

    while (start<end) {
        if (num[start] < num[end])
            return num[start];
        int mid = (start + end) / 2;

        if (num[mid] >= num[start]) {
            start = mid + 1;
        else
            end = mid;
    }
    return num[start];
}
