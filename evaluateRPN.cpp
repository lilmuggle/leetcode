class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s : tokens) {
            if(s=="+"||s=="-"||s=="*"||s=="/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if(s == "+")
                    stk.push(a + b);
                else if(s == "-")
                    stk.push(b - a);
                else if(s == "*")
                    stk.push(a * b);
                else
                    stk.push(b / a);
            }
            else
                stk.push(atoi(s.c_str()));
        }
        return stk.top();
    }
};

//Recursive
int evalRPN(vector<string> &n) {
    string s = n.back(); n.pop_back();
    if ( s== "*" || s=="/" || s=="+" || s == "-" ){
        int r2 = evalRPN(n);
        int r1 = evalRPN(n);
        if ( s=="*") return r1*r2;
        if ( s=="/") return r1/r2;
        if ( s=="+") return r1+r2;
        if ( s=="-") return r1-r2;
    }
    else
        return atoi(s.c_str());
}
