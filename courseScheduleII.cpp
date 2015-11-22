class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        stack<int> stk;
        vector<int> res;
        vector<int> degree(numCourses, 0);
        unordered_map<int, vector<int>> pre;
        for(auto x : prerequisites) {
            if(x.first >= numCourses || x.second >= numCourses)
                return res;
            degree[x.first]++;
            pre[x.second].push_back(x.first);
        }
        for(int i = 0; i < degree.size() ; i++)
            if(degree[i] == 0)
                stk.push(i);
        while(!stk.empty()) {
            int c = stk.top();
            res.push_back(c);
            stk.pop();
            numCourses--;
            for(int i : pre[c])
                if(--degree[i] == 0)
                    stk.push(i);
        }
        if(numCourses != 0)
            res.clear();
        return res;
    }
};
