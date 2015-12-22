class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coords;
        multiset<int> heights = {0};
        vector<pair<int, int>>  corners;
        for(auto b : buildings) {
            coords[b[0]] = b[2];
            coords[b[1]] = -b[2];
        }
        int x = -1, y = 0;
        for(auto c : coords) {
            if((x >= 0) && (c.first != x) && (corners.empty() || corners.rbegin()->second != y))
                corners.emplace_back(x, y);
            if(c.second >= 0)
                heights.insert(c.second);
            else
                heights.erase(heights.find(-c.second));
            x = c.first;
            y = *heights.rbegin();
        }
        if ((!corners.empty()) && (corners.rbegin()->second != 0))
            corners.emplace_back(x, 0);
        return corners;
    }
};
