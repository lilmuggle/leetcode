int hIndex(int* citations, int citationsSize) {
    int low, high, mid;
    low = 0;
    high = citationsSize - 1;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(citations[mid] == citationsSize - mid)
            return citationsSize - mid;
        if(citations[mid] > citationsSize - mid)
            high = mid;
        else
            low = mid + 1;
    }
    return citations[low] < citationsSize -low ? citations[low] : citationsSize - low;
}
