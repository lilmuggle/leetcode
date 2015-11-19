class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mm;
        reverse(strs.begin(), strs.end());
        for(int i = 0; i < strs.size(); i++) {
            int j = 0;
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mm.find(tmp) != mm.end())
                res[mm[tmp]].push_back(strs[i]);
            else {
                res.push_back(vector<string>());
                res[res.size() - 1].push_back(strs[i]);
                mm[tmp] = res.size() - 1;
            }
        }
        for(int i = 0; i < res.size(); i++)
            sort(res[i].begin(), res[i].end());
        return res;
    }
};
