class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int pos, prod, carry = 0;
        if(num1 == "0" || num2 == "0")
            return "0";
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                prod = (num1[i] - '0') * (num2[j] - '0');
                carry = prod / 10;
                pos = num1.size() + num2.size() - 2 - i - j;
                if(pos == res.size())
                    res.push_back(prod % 10 + '0');
                else {
                    prod = res[pos] - '0' + prod % 10;
                    carry += prod / 10;
                    res[pos] = prod % 10 + '0';
                }
                pos++;
                while(carry != 0) {
                    if(pos == res.size()) {
                        res.push_back(carry + '0');
                        carry = 0;
                    }
                    else {
                        prod = res[pos] - '0' + carry;
                        carry = prod / 10;
                        res[pos] = prod % 10 + '0';
                    }
                    pos++;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//Improvement
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}
