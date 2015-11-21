class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        stack<int> stk;
        unordered_map<int, int> degree;
        unordered_map<int, vector<int>> pre;
        for(auto x : prerequisites) {
            if(x.first >= numCourses || x.second >= numCourses)
                return false;
            degree[x.first]++;
            pre[x.second].push_back(x.first);
            if(degree.find(x.second) == degree.end())
                degree[x.second] = 0;
        }
        for(auto w : degree)
            if(w.second == 0)
                stk.push(w.first);
        int count = degree.size();
        while(!stk.empty()) {
            int c = stk.top();
            stk.pop();
            count--;
            for(int i : pre[c])
                if(--degree[i] == 0)
                    stk.push(i);
        }
        return count == 0 ? true : false;
    }
};

//DFS
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    unordered_set<int> visited;
    vector<bool> flag(numCourses, false);
    for(int i = 0; i < numCourses; ++ i)
        if(!flag[i])
            if(DFS(matrix, visited, i, flag))
                return false;
    return true;
}
bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
{
    flag[b] = true;
    visited.insert(b);
    for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
        if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
            return true;
    visited.erase(b);
    return false;
}
