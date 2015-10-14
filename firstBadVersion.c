// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low, high, mid;
    low  = 1;
    high = n;
    while(low < high) {
        mid = low + (high -low) / 2;
        if(isBadVersion(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
