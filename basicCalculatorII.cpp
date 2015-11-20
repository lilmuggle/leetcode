class Solution {
public:
    int calculate(string s) {
        stack<char> stk;
        stack<int> istk;
        string postfix;
        for(char c : s) {
            if(c == ' ')
                continue;
            else if(c >= '0' && c <= '9')
                postfix.push_back(c);
            else if(c == '+' || c == '-'){
                while(!stk.empty()) {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                postfix.push_back(' ');
                stk.push(c);
            }
            else {
                if(!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                else
                    postfix.push_back(' ');
                stk.push(c);
            }
        }
        while(!stk.empty()) {
            postfix.push_back(stk.top());
            stk.pop();
        }
        int i = 0;
        while(i < postfix.size()) {
            if(postfix[i] == ' ')
                i++;
            else if(postfix[i] >= '0' && postfix[i] <= '9'){
                int num = 0;
                while(postfix[i] - '0' >= 0 && postfix[i] - '0' <= 9) {
                    num = num * 10 + postfix[i] - '0';
                    i++;
                }
                istk.push(num);
            }
            else {
                int n1 = istk.top();
                istk.pop();
                int n2 = istk.top();
                istk.pop();
                switch(postfix[i]) {
                case '+':
                    istk.push(n1 + n2);
                    break;
                case '-':
                    istk.push(n2 - n1);
                    break;
                case '*':
                    istk.push(n2 * n1);
                    break;
                case '/':
                    istk.push(n2 / n1);
                    break;
                }
                i++;
            }
        }
        return istk.top();
    }
};
