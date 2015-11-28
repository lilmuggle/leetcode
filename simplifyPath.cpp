class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0)
            return "";
        string res;
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                while(i < path.size() - 1 && path[i + 1] == '/')
                    i++;
                res.push_back('/');
            }
            else if(path[i] == '.') {
                string tmp = ".";
                while(i < path.size() - 1 && path[i + 1] == '.')
                    tmp.push_back(path[++i]);
                if(tmp.size() < 3) {
                    if(i < path.size() - 1 && path[i + 1] != '/')
                        res += tmp;
                    else {
                        res.pop_back();
                        if(tmp.size() == 2) {
                            for(int j=res.size()-1;j>=0&&res[j]!='/';j--,res.pop_back()) {}
                            if(res.size() > 0)
                                res.pop_back();
                        }
                    }
                }
                else
                    res += tmp;
            }
            else
                res.push_back(path[i]);
        }
        if(res.size()  == 0)
            return "/";
        if(res.size() > 1 && res[res.size() -1 ] == '/')
            res.pop_back();
        return res;
    }
};

//Concise one
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
