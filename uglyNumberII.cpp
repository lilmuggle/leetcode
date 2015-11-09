class Solution {
public:
    int minium(int a, int b, int c) {
        if(a <= b && a <= c)
            return a;
        if(b <= a && b <= c)
            return b;
        return c;
    }

    int nthUglyNumber(int n) {
        if(n <= 4)
            return n;
        queue<int> q1, q2, q3;
        q1.push(3);
        q1.push(4);
        q2.push(2);
        q3.push(1);
        for(; n > 4; n--) {
            int a = INT_MAX, b = INT_MAX, c = INT_MAX;
            if(q1.size())
                a = q1.front() * 2;
            if(q2.size())
                b = q2.front() * 3;
            if(q3.size())
                c = q3.front() * 5;
            int min=minium(a, b, c);
            q1.push(min);
            if(q1.size() && q1.front() * 2 == min) {
                q2.push(q1.front());
                q1.pop();
            }
            if(q2.size() && q2.front() * 3 == min) {
                q3.push(q2.front());
                q2.pop();
            }
            if(q3.size() && q3.front() * 5 == min)
                q3.pop();
        }
        return q1.back();
    }
};

//After improvement
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++;
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
