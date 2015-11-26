class Solution {
public:
    vector<string> res;
    int point = 0;
    void backtrack(string s, int n, string ip) {
        if(s.size()-n>(4-point)*3||s.size()-n<4-point)
            return;
        if(point == 4) {
            ip.pop_back();
            res.push_back(ip);
            return;
        }
        for(int i=1;n+i<=s.size()&&atoi(s.substr(n,i).c_str())<256;i++) {
            string tmp = ip;
            ip.insert(ip.begin() + n + i + point, '.');
            point++;
            backtrack(s, n + i, ip);
            point--;
            ip = tmp;
            if(atoi(s.substr(n,i).c_str()) == 0)
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, s);
        return res;
    }
};
