class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int area, len, maxarea = 0;
        vector<vector<pair<int, int>>> dp(matrix.size(), vector<pair<int, int>>(matrix[0].size(), {0, 0}));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '0')
                    continue;
                dp[i][j].first = (j > 0 ? dp[i][j - 1].first : 0) + 1;
                dp[i][j].second = (i > 0 ? dp[i - 1][j].second : 0) + 1;
                area = max(dp[i][j].first, dp[i][j].second);
                maxarea = max(maxarea, area);
                len = INT_MAX;
                for(int r = i, c = j - 1; j > 0 && i < r + dp[i][j].second && matrix[r][c] != '0'; r--) {
                    len = min(dp[r][c].first + 1, len);
                    area = len * (i - r + 1);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};

//Another
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix==null||matrix.length==0||matrix[0].length==0)
            return 0;
        int cLen = matrix[0].length;    // column length
        int rLen = matrix.length;       // row length
        // height array
        int[] h = new int[cLen+1];
        h[cLen]=0;
        int max = 0;


        for (int row=0;row<rLen;row++) {
            Stack<Integer> s = new Stack<Integer>();
            for (int i=0;i<cLen+1;i++) {
                if (i<cLen)
                    if(matrix[row][i]=='1')
                        h[i]+=1;
                    else h[i]=0;

                if (s.isEmpty()||h[s.peek()]<=h[i])
                    s.push(i);
                else {
                    while(!s.isEmpty()&&h[i]<h[s.peek()]){
                        int top = s.pop();
                        int area = h[top]*(s.isEmpty()?i:(i-s.peek()-1));
                        if (area>max)
                            max = area;
                    }
                    s.push(i);
                }
            }
        }
        return max;
    }
}
