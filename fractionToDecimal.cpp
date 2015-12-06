class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int i, flag = 1;
        string res;
        unordered_map<int, int> de;
        if((numerator > 0 && denominator < 0) || (numerator < 0) && (denominator > 0))
            flag = 0;
        long num = labs(numerator), den = labs(denominator);
        long n = num / den, reminder = num % den;
        res = to_string(n);
        if(reminder != 0)
            res.push_back('.');
        i = res.size();
        de[reminder] = i++;
        while(reminder) {
            n = reminder * 10 / den;
            reminder = reminder * 10 % den;
            res.push_back(n + '0');
            if(de.find(reminder) != de.end()) {
                res.insert(res.begin() + de[reminder], '(');
                res.push_back(')');
                break;
            }
            else
                de[reminder] = i++;
        }
        return flag == 1 ? res : "-" + res;
    }
};
