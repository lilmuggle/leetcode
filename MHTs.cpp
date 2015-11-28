class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1)
            return vector<int>{0};
        vector<int> leaf;
        vector<vector<int>> v(n, vector<int>());
        for(auto x : edges) {
            v[x.first].push_back(x.second);
            v[x.second].push_back(x.first);
        }
        for(int i = 0; i < n; i++) {
            if(v[i].size() == 1)
                leaf.push_back(i);
        }
        while(n > 2) {
            vector<int> newleaf;
            for(int i : leaf) {
                for(int j = 0; j < v[v[i][0]].size(); j++) {
                    if(v[v[i][0]][j] == i) {
                        v[v[i][0]].erase(v[v[i][0]].begin() + j);
                        if(v[v[i][0]].size() == 1)
                            newleaf.push_back(v[i][0]);
                        break;
                    }
                }
            }
            leaf = newleaf;
        }
        return leaf;
    }
};
