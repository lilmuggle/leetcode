class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i < input.size(); i++) {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*') {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(int l : left) {
                    for(int r : right) {
                        if(input[i] == '+')
                            res.push_back(l + r);
                        else if(input[i] == '-')
                            res.push_back(l - r);
                        else
                            res.push_back(l * r);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(atoi(input.c_str()));
        return res;
    }
};

//The same as above
vector<int> diffWaysToCompute(string input) {
    vector<int> output;
    for (int i=0; i<input.size(); i++) {
        char c = input[i];
        if (ispunct(c))
            for (int a : diffWaysToCompute(input.substr(0, i)))
                for (int b : diffWaysToCompute(input.substr(i+1)))
                    output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
    }
    return output.size() ? output : vector<int>{stoi(input)};
}

//Using map
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }

    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = computeWithDP(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = computeWithDP(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
    }
};
