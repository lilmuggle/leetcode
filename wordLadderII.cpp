class Solution {
public:
    int minstep = INT_MAX;
    vector<vector<string>> res;
    unordered_map<string, vector<string>> ladder;
    void dfs(string e, int step, vector<string> &vec) {
        string b = vec[vec.size() - 1];
        if(b == e && step == minstep) {
            res.push_back(vec);
            return;
        }
        for(string word : ladder[b]) {
            vec.push_back(word);
            dfs(e, step + 1, vec);
            vec.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int step = 0;
        queue<string> q;
        set<string> cur;
        unordered_set<string> visited;
        wordList.erase(beginWord);
        wordList.insert(endWord);
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()) {
            int num = q.size();
            for(int i = 0; i < num; i++) {
                string s = q.front();
                q.pop();
                if(s == endWord)
                    minstep = step;
                else {
                    for(int j = 0; j < s.size(); j++) {
                        string tmp = s;
                        for(char c = 'a'; c <= 'z'; c++) {
                            tmp[j] = c;
                            if(wordList.find(tmp) != wordList.end()) {
                                ladder[s].push_back(tmp);
                                cur.insert(tmp);
                                if(visited.find(tmp) == visited.end()) {
                                    q.push(tmp);
                                    visited.insert(tmp);
                                }
                            }
                        }
                    }
                }
            }
            if(minstep != INT_MAX)
                break;
            for(string ss : cur)
                wordList.erase(ss);
            cur.clear();
            step++;
        }
        if(minstep != INT_MAX) {
            vector<string> vec{beginWord};
            dfs(endWord, 0, vec);
        }
        return res;
    }
};
