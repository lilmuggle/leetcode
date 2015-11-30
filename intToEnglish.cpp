class Solution {
public:
    vector<string> a{"Hundred","Thousand","Million","Billion"};
    vector<string> b{"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    vector<string> c{"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> d{"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string helper(int num, int n) {
        string s;
        if(num >= 100) {
            s = d[num / 100 - 1] + " " + a[0];
            num %= 100;
        }
        if(num >= 10) {
            if(s.size() > 0)
                s += " ";
            if(num / 10 == 1) {
                s += c[num - 10];
                num = 0;
            }
            else {
                s += b[num / 10 - 2];
                num %= 10;
            }
        }
        if(num > 0) {
            if(s.size() > 0)
                s += " ";
            s += d[num - 1];
        }
        if(s.size() != 0 && n != 0)
            s += " " + a[n];
        return s;
    }
    string numberToWords(int num) {
        string res;
        for(int i = 0; num; i++) {
            string tmp = helper(num % 1000, i);
            if(tmp.size() != 0) {
                if(res.size() == 0)
                    res = tmp;
                else
                    res = tmp + " " + res;
            }
            num /= 1000;
        }
        return res.size() == 0 ? "Zero" : res;
    }
};
