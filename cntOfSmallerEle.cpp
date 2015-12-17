class Solution {
public:
    void merge(vector<int> &n, int start, int end, int mid, vector<int> &res, vector<int> &ix) {
        int i, j, cnt = 0;
        vector<pair<int, int>> left, right;
        for(i = start; i <= mid; i++)
            left.push_back(make_pair(n[i], ix[i]));
        for(i = mid + 1; i <= end; i++)
            right.push_back(make_pair(n[i], ix[i]));
        left.push_back(make_pair(INT_MAX, 0));
        right.push_back(make_pair(INT_MAX, 0));
        i = j = 0;
        for(int k = start; k <= end; k++) {
            if(left[i].first <= right[j].first) {
                n[k] = left[i].first;
                ix[k] = left[i].second;
                res[left[i++].second] += cnt;
            }
            else {
                n[k] = right[j].first;
                ix[k] = right[j].second;
                j++;
                cnt++;
            }
        }
    }
    void inversion(vector<int> &n, int start, int end, vector<int> &res, vector<int> &ix) {
        if(start < end) {
            int mid = start + (end - start) / 2;
            inversion(n, start, mid, res, ix);
            inversion(n, mid + 1, end, res, ix);
            merge(n, start, end, mid, res, ix);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index, res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
            index.push_back(i);
        inversion(nums, 0, nums.size() - 1, res, index);
        return res;
    }
};
