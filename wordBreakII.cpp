//DP
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        for(int i = s.size() - 1; i >= 0; i--) {
            if(wordDict.find(s.substr(i)) != wordDict.end())
                break;
            if(i == 0)
                return vector<string>();
        }
        int minlen = INT_MAX, maxlen = INT_MIN;
        unordered_map<int, vector<string>> sentence;
        for (string w : wordDict) {
            minlen = min(minlen, (int)w.size());
            maxlen = max(maxlen, (int)w.size());
        }
        for(int start = 0; start < s.size(); start++) {
            for(int i=start+minlen-1; i < min(start+maxlen,(int)s.size()); i++) {
                string word = s.substr(start, i - start + 1);
                if(wordDict.find(word) != wordDict.end()) {
                    if(start == 0)
                        sentence[i + 1].push_back(word);
                    else {
                        for(int j = 0; j < sentence[start].size(); j++)
                            sentence[i+1].push_back(sentence[start][j]+" "+word);
                    }
                }
            }
        }
        return sentence[s.size()];
    }
};

//Backtracking
class Solution {
public:
    vector<string> res;
    int minlen = INT_MAX, maxlen = INT_MIN;
    void backtrack(string s, int n, string sol, unordered_set<string> w) {
        if(n == s.size())
            res.push_back(sol);
        else {
            if(n != 0)
                sol.insert(sol.begin() + n + sol.size() - s.size(), ' ');
            for(int i=n+minlen-1; i < min(n+maxlen,(int)s.size()); i++) {
                string word = s.substr(n, i - n + 1);
                if(w.find(word) != w.end())
                    backtrack(s, i + 1, sol, w);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        for(int i = s.size() - 1; i >= 0; i--) {
            if(wordDict.find(s.substr(i)) != wordDict.end())
                break;
            if(i == 0)
                return vector<string>();
        }
        for (string w : wordDict) {
            minlen = min(minlen, (int)w.size());
            maxlen = max(maxlen, (int)w.size());
        }
        backtrack(s, 0, s, wordDict);
        return res;
    }
};

//Others
    class Solution {
    public:
        // the run time is still 4ms even with hash
        unordered_map<string , vector<string>> dpHash;

        // it runs 4ms. the key factor it that it checks from both side to filter
        // out impossible combination in every early stage
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            vector<string> res;
            // check hash first
            if (dpHash.find(s) != dpHash.end()) {
                return dpHash[s];
            }

            // check if need go further
            // it there's no checking here, the run time will be
            // wi hash : 20ms
            // wo hash : TLE
            bool notFound = true;
            for (int i = s.size() - 1; i >=0; --i) {   // key here
                if (wordDict.find(s.substr(i)) != wordDict.end()) {
                    notFound = false;
                    break;
                }
            }
            if (notFound) { return res; }

            // go further
            if (wordDict.find(s) != wordDict.end()) { res.push_back(s); }
            for (int i = s.size() - 2; i >= 0; --i) {
                if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                    vector<string> subRes = wordBreak(s.substr(i + 1), wordDict);
                    for (auto tmp : subRes) {
                        res.push_back(s.substr(0, i + 1) + " " + tmp);
                    }
                }
            }

            dpHash[s] = res;  // update hash
            return res;
        }
};

//DP + DFS
class Solution {
private: //DFS path build function
    void buildPath(bool isBreakable[], string &s, int pos, vector<string> &res, string curP, unordered_set<string>& wordDict, int minlen, int maxlen)
    {
        int i, len = s.size();
        for(i =minlen; i<= min(maxlen, len - pos); ++i)
            if( isBreakable[pos+i] && wordDict.count(s.substr(pos,i)) )
                if(pos+i == len) res.push_back(curP + s.substr(pos,i));
                else buildPath(isBreakable, s, pos+i, res, curP + s.substr(pos,i) + " ", wordDict, minlen, maxlen);
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
        vector<string> res;
        bool isBreakable[sSize+1];
        fill_n(isBreakable, sSize+1, false);

        for (string word : wordDict) { // find the minimum and maximum word length
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length());
        }
        //DP to build isBreakable
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len)
            {
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) {isBreakable[i] = true; break;}
            }
        //if breakable, do DFS path building
        if(isBreakable[0]) buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
        return res;
    }
};
