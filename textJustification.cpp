class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, j, width, space, gapCnt;
        vector<string> res;
        while(i < words.size()) {
            string s;
            width = 0;
            j = i;
            while(i < words.size() && (int)words[i].size() <= (maxWidth - width))
                width += (1 + words[i++].size());
            space = maxWidth - --width;
            gapCnt = i - j - 1;
            if(i < words.size()) {
                if(gapCnt == 0) {
                    s = words[j];
                    for(int k = 0; k < space; k++)
                        s.push_back(' ');
                    res.push_back(s);
                    continue;
                }
                vector<int> gap(gapCnt, 0);
                int avg = space / gapCnt;
                int left = space % gapCnt;
                for(int k = 0; k < gapCnt; k++) {
                    s += words[j + k];
                    for(int x = 0; x <= avg; x++)
                        s.push_back(' ');
                    if(left > 0) {
                        s.push_back(' ');
                        left--;
                    }
                }
                s += words[i - 1];
            }
            else {
                for(int k = j; k < i; k++)
                    s += words[k] + " ";
                s.pop_back();
                for(int x = 0; x < space; x++)
                    s.push_back(' ');
            }
            res.push_back(s);
        }
        return res;
    }
};
