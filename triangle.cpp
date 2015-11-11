class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min = INT_MAX, tmp1, tmp2, n = triangle[triangle.size() - 1].size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(j == 0) {
                    tmp1 = res[0];
                    res[0] += triangle[i][0];
                }
                else if(j < triangle[i].size() - 1) {
                    tmp2 = res[j];
                    res[j] = triangle[i][j] + (tmp1<res[j]?tmp1:res[j]);
                    tmp1 = tmp2;
                }
                else
                    res[j] = tmp1 + triangle[i][j];
                if(i == n - 1)
                    min = min < res[j] ? min : res[j];
            }
        }
        return min;
    }
};

//Bottom-Up
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i];
        }
    }
    return minlen[0];
}
