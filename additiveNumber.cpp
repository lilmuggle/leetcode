class Solution {
public:
    bool check(string s, int n1, int n2, int i) {
        if(i == s.size())
            return true;
        for(int j = i, n3 = 0; j < s.size() ; j++) {
            n3 = n3 * 10 + s[j] - '0';
            if(n1 + n2 == n3)
                return check(s, n2, n3, j + 1);
            if(n3 == 0)
                return false;
        }
    }
    bool isAdditiveNumber(string num) {
        for(int i = 0, n1 = 0; i < num.size() - 2; i++) {
            n1 = n1 * 10 + num[i] - '0';
            for(int j = i + 1, n2 = 0; j < num.size() - 1; j++) {
                n2 = n2 * 10 + num[j] - '0';
                if(check(num, n1, n2, j + 1))
                    return true;
                if(n2 == 0)
                    break;
            }
            if(n1 == 0)
                break;
        }
        return false;
    }
};
