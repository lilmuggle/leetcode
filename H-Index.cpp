class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i, len = citations.size();
        sort(citations.begin(), citations.end());
        for(i = 0; i < len; i++) {
            if(citations[i] >= len - i)
                return len - i;
        }
    }
};

//Using HashTable
int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}
