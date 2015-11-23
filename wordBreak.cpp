class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        string first;
        for(int i = 0; i < s.size(); i++) {
            first.push_back(s[i]);
            while(i < s.size() - 1 && s[i] == s[i + 1]) {
                first.push_back(s[++i]);
                if(wordDict.find(first) == wordDict.end()) {
                    first.pop_back();
                    i--;
                    break;
                }
            }
            if(wordDict.find(first) != wordDict.end()) {
                if(i == s.size() - 1)
                    return true;
                else
                    if(wordBreak(s.substr(i + 1), wordDict))
                        return true;
            }
        }
        return false;
    }
};

//dp
bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }

//BFS
bool wordBreak(string s, unordered_set<string> &dict) {
    // BFS
    queue<int> BFS;
    unordered_set<int> visited;

    BFS.push(0);
    while(BFS.size() > 0)
    {
        int start = BFS.front();
        BFS.pop();
        if(visited.find(start) == visited.end())
        {
            visited.insert(start);
            for(int j=start; j<s.size(); j++)
            {
                string word(s, start, j-start+1);
                if(dict.find(word) != dict.end())
                {
                    BFS.push(j+1);
                    if(j+1 == s.size())
                        return true;
                }
            }
        }
    }

    return false;
}
