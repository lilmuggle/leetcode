class Solution {
public:
    int calculate(string s) {
        stack<char> stk;
        stack<int> istk;
        string postfix;
        for(char c : s) {
            if(c == '+' || c == '-') {
                if(!stk.empty() && stk.top() != '(') {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                else
                    postfix.push_back(' ');
                stk.push(c);
            }
            else if(c == '(')
                stk.push(c);
            else if(c == ')') {
                while(stk.top() != '(') {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else {
                if(c != ' ')
                    postfix.push_back(c);
            }
        }
        while(!stk.empty()) {
            postfix.push_back(stk.top());
            stk.pop();
        }
        int i = 0;
        while(i < postfix.size()) {
            if(postfix[i] == '+' || postfix[i] == '-') {
                int n1 = istk.top();
                istk.pop();
                int n2 = istk.top();
                istk.pop();
                if(postfix[i] == '+')
                    istk.push(n1 + n2);
                else
                    istk.push(n2 - n1);
                i++;
            }
            else if(postfix[i] != ' '){
                int num = 0;
                while(postfix[i] - '0' >= 0 && postfix[i] - '0' <= 9) {
                    num = num * 10 + postfix[i] - '0';
                    i++;
                }
                istk.push(num);
            }
            else
                i++;
        }
        return istk.top();
    }
};
