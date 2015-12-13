//DFS
class Solution {
public:
    unordered_set<string> res;
    void dfs(string s, int i, int l, int r, int pair, string str) {
        if(i == s.size()) {
            if(l == 0 && r == 0 && pair == 0)
                res.insert(str);
            return;
        }
        if(s[i] == '(') {
            if(l > 0)
                dfs(s, i + 1, l - 1, r, pair, str);
            dfs(s, i + 1, l, r, pair + 1, str + s[i]);
        }
        else if(c == ')') {
            if(r > 0)
                dfs(s, i + 1, l, r - 1, pair, str);
            if(pair > 0)
                dfs(s, i + 1, l, r, pair - 1, str + s[i]);
        }
        else
            dfs(s, i + 1, l, r, pair, str + s[i]);
    }
    vector<string> removeInvalidParentheses(string s) {
        int left_remove = 0, right_remove = 0;
        for(char c : s) {
            if(c == '(')
                left_remove++;
            else {
                if(left_remove > 0)
                    left_remove--;
                else
                    right_remove++;
            }
        }
        dfs(s, 0, left_remove, right_remove, 0, "");
        return vector<string>(res.begin(), res.end());
    }
};

//BFS
class Solution {
public:
    bool isValid(string s) {
        int cnt = 0;
        for(char c : s) {
            if(c == '(')
                cnt++;
            else if(c == ')' && cnt-- == 0)
                return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        bool found  = false;
        vector<string> res;
        unordered_set<string> foundSet;
        queue<string> q;
        q.push(s);
        while(!q.empty()) {
            string str = q.front();
            q.pop();
            if(isValid(str)) {
                res.push_back(str);
                found = true;
            }
            if(!found) {
                for(int i = 0; i < str.size(); i++) {
                    if(str[i] == '(' || str[i] == ')') {
                        string tmp = str.substr(0, i) + str.substr(i + 1);
                        if(foundSet.find(tmp) == foundSet.end()) {
                            q.push(tmp);
                            foundSet.insert(tmp);
                        }
                    }
                }
            }
        }
        return res;
    }
};
