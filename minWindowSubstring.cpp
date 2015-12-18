class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1;
        string res;
        unordered_map<char, int> ms, mt, tmp;
        for(char c : t)
            mt[c]++;
        tmp = mt;
        for(int i = 0; i < s.size(); i++) {
            if(tmp.find(s[i]) == tmp.end())
                continue;
            ms[s[i]]++;
            if(mt.find(s[i]) != mt.end() && --mt[s[i]] == 0)
                mt.erase(s[i]);
            if(start == -1)
                start = i;
            while(mt.size() == 0) {
                if(res == "")
                    res = s.substr(start, i - start + 1);
                else
                    res = ((int)res.size() <= (i - start + 1) ? res : s.substr(start, i - start + 1));
                if(--ms[s[start]] < tmp[s[start]])
                    mt[s[start]]++;
                while(++start < s.size() && (tmp.find(s[start]) == tmp.end())) {}
            }
        }
        return res;
    }
};

//Another
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};
