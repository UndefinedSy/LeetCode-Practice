// 本题中需要求一个子区域的和，因此我们可以重新构造一个新的图
// 图中每一个点都是其坐标 (x, y) 与 (0, 0) 所描述的子区域的和
// 这样我们需要求的结果就是:
//     {(0, 0), (x2, y2)} - {(x2, y1-1), (x2, y2)} - {(x1-1, y2), (x2, y2)} + {(0, 0), (x1-1, y1-1)}
// 当然需要注意边界的检查。


class NumMatrix {
private:
    std::vector<std::vector<int>> SumMatrix_;

public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        SumMatrix_.resize(n);
        for (int i = 0; i < n; ++i)
        {
            SumMatrix_[i].resize(m);
            int LineSum = 0;
            for (int j = 0; j < m; ++j)
            {
                LineSum += matrix[i][j];
                SumMatrix_[i][j] = LineSum;
                if (i > 0)
                    SumMatrix_[i][j] += SumMatrix_[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // if (SumMatrix_.empty()) return 0;
        int Res = SumMatrix_[row2][col2];
        if (row1 > 0)
            Res -= SumMatrix_[row1-1][col2];
        if (col1 > 0)
            Res -= SumMatrix_[row2][col1-1];
        if (row1 > 0 && col1 > 0)
            Res += SumMatrix_[row1-1][col1-1];
        return Res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */