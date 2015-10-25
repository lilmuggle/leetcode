class Solution {
public:
    vector<vector<string>> solution;
    int q, *x;

    bool place(int k) {
        for(int i = 0; i < k; i++)
            if(x[k]==x[i]||abs(k-i)==abs(x[k]-x[i]))
                return false;
        return true;
    }

    vector<string> x2Q() {
        vector<string> Q;
        for(int i = 0; i < q; i++) {
            string str(q, '.');
            str[x[i]] = 'Q';
            Q.push_back(str);
        }
        return Q;
    }

    void backtrack(int t) {
        if(t >= q)
            solution.push_back(x2Q());
        else {
            for(int i = 0; i < q; i++) {
                x[t] = i;
                if(place(t))
                    backtrack(t + 1);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int *p = new int[n];
        for(int i = 0; i < n; i++)
            p[i] = 0;
        x = p;
        q = n;
        backtrack(0);
        delete []p;
        return solution;
    }
};

//bit manipulation
class Solution {
public:
    int upperlim, q;
    vector<vector<string>> solution;
    vector<string> ans;

    string getQ(int p) {
        string s(q, '.');
        int c = 0;
        while(p != 1) {
            p >>= 1;
            c++;
        }
        s[q - 1 - c] = 'Q';
        return s;
    }

    void test(int row, int ld, int rd) {
        if(row != upperlim) {
            int pos = upperlim & ~(row | ld | rd);
            while(pos) {
                int p = pos & -pos, j = -1;
                pos -= p;
                ans.push_back(getQ(p));
                test(row + p, (ld + p) << 1, (rd + p) >> 1);
                ans.pop_back();
            }
        }
        else
            solution.push_back(ans);
    }

    vector<vector<string>> solveNQueens(int n) {
        q = n;
        upperlim = (1 << n) - 1;
        test(0, 0, 0);
        return solution;
    }
};
