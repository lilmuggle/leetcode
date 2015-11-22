class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n, 0), fac(n, 1);
        string s;
        for(int i = 1; i < n; i++)
            fac[i] = fac[i - 1] * i;
        for(int i = 1; i <= n; i++) {
            int tmp = (k - 1) / fac[n - i];
            int j, count = 0;
            for(j = 0; j < n; j++) {
                if(a[j] == 0)
                    count++;
                if(tmp + 1 == count)
                    break;
            }
            s.push_back(j + 1 + '0');
            a[j] = 1;
            k -= tmp * fac[n - i];
        }
        return s;
    }
};
