class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0, len, tmp;
        unordered_set<int> s;
        for(int i : nums)
            s.insert(i);
        for(int i : nums) {
            if(s.find(i) != s.end()) {
                len = 1;
                s.erase(i);
                tmp = i - 1;
                while(s.find(tmp) != s.end()) {
                    len++;
                    s.erase(tmp);
                    tmp--;
                }
                tmp = i + 1;
                while(s.find(tmp) != s.end()) {
                    len++;
                    s.erase(tmp);
                    tmp++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};

//After improvement
int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}
