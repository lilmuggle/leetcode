class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i, len = s.size();
        for(i = 0; i < len; i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                stk.push(s[i]);
            else {
                if(stk.empty())
                    return false;
                switch (s[i]) {
                case ')':
                    if(stk.top() == '(') {
                        stk.pop();
                        break;
                    }
                    else
                        return false;
                case ']':
                    if(stk.top() == '[') {
                        stk.pop();
                        break;
                    }
                    else
                        return false;
                case '}':
                    if(stk.top() == '{') {
                        stk.pop();
                        break;
                    }
                    else
                        return false;
                }
            }
        }
        return stk.empty();
    }
};
