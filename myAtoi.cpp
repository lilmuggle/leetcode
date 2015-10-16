class Solution {
public:
    int myAtoi(string str) {
        int i, number, flag = 1, len = str.size();
        long long sum = 0;
        for(i = 0; i < len; i++) {
            if(str[i] == ' ') {}
            else if(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')){
                if(str[i] == '-')
                    flag = 0;
                if(str[i] == '-' || str[i] == '+')
                    i++;
                while(i < len && str[i] >= '0' && str[i] <= '9') {
                    if(flag)
                        sum = sum * 10 + (str[i] - '0');
                    else
                        sum = sum * 10 - (str[i] - '0');
                    i++;
                    if(sum > INT_MAX)
                        return INT_MAX;
                    else if(sum < INT_MIN)
                        return INT_MIN;
                }
                number = sum;
                return number;
            }
            else
                break;
        }
        return 0;
    }
};
