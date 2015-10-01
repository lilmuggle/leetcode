#include <iostream>
#include <set>

using namespace std;

class Solution {
    public:
        set<int> numberSet;
        bool isHappy(int n);
        int num2sum(int n);
};
bool Solution::isHappy(int n)
{
    if(n > 0)
    {
        while(numberSet.count(n) == 0)
        {
            while(n >= 10 && n % 10 == 0)
                n /= 10;
            numberSet.insert(n);
            n = num2sum(n);
        }
        if(n == 1)
            return true;
    }

    return false;
}
int Solution::num2sum(int n)
{
    int c;

    if(n < 10)
        return n * n;
    else
        c = n % 10;
        n /= 10;
        return c * c + num2sum(n);
}

int main()
{
    int number;
    Solution s;

    cin >> number;
    if(s.isHappy(number))
        cout << "TRUE" << endl;
    else
        cout << "Flase" << endl;

    return 0;
}
