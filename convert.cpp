//Original
class Solution {
public:
    string convert(string s, int numRows) {
        string t;
        int i, j, k1, k2, len = s.size();
        if(numRows == 1)
            return s;
        k1 = 2 * numRows - 2;
        for(i = 0; i < numRows; i++) {
            if(i < numRows - 1)
                k2 = k1 - 2 * i;
            else
                k2 = k1;
            for(j = i; j < len; j += k2) {
                t += s[j];
                if(i > 0 && i < numRows - 1 && j != i)
                    k2 = k1 - k2;
            }
        }
        return t;
    }
};

//Another
string convert(string s, int nRows) {

    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}
