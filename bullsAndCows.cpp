class Solution {
public:
    string num2str(int i) {
        stringstream ss;
        ss << i;
        return ss.str();
    }

    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        string s;
        vector<int> v(secret.size(), 0);
        for(int i = 0; i < guess.size(); i++) {
            if(guess[i] == secret[i])
                a++;
            else {
                for(int j = 0; j < secret.size(); j++)
                    if(secret[j]==guess[i]&&secret[j]!=guess[j]&&v[j]!=1) {
                        b++;
                        v[j] = 1;
                        break;
                    }
            }
        }
        s = num2str(a) + "A" + num2str(b) + "B";
        return s;
    }
};

//Others
class Solution {
public:
    // only contains digits
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt;
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};
