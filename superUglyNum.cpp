class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m;
        vector<int> k(n), p(primes.size(), 0);
        k[0] = 1;
        for(int i = 1; i < n; i++) {
            m = INT_MAX;
            for(int j =0; j < primes.size(); j++)
                m = min(m, k[p[j]] * primes[j]);
            k[i] = m;
            for(int j =0; j < primes.size(); j++)
                if(m == k[p[j]] * primes[j])
                    p[j]++;
        }
        return k[n - 1];
    }
};
