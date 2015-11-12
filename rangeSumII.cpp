class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            int sum = 0;
            a.push_back(vector<int>(matrix[0].size(), 0));
            for(int j = 0; j < matrix[0].size(); j++) {
                sum += matrix[i][j];
                a[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
            sum += col1==0?a[i][col2]:a[i][col2]-a[i][col1-1];
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
