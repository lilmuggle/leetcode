class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        int i = findIndex(num);
        a.insert(a.begin() + i, num);
    }

    // Returns the median of current data stream
    double findMedian() {
        int mid = (int)(a.size() - 1) / 2;
        if((int)a.size() % 2 == 0)
            return ((double)a[mid] + (double)a[mid + 1]) / 2;
        else
            return a[mid];
    }
private:
    vector<int> a;
    int findIndex(int n) {
        int mid, low = 0, high = a.size() - 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(a[mid] == n)
                return mid;
            else if(a[mid] > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

//Using heap
class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());//C++'s priority_queue is a max-queue
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};
