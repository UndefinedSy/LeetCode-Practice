class Solution {
private:
    bool isToeplitz(int BaseNum, int x, int y,
                    int matrixX, int matrixY,
                    const std::vector<std::vector<int>>& matrix)
    {
        while (x < matrixX && y < matrixY)
        {
            if (matrix[x][y] != BaseNum) return false;
            x++;
            y++;
        }
        return true;
    }


public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int matrixX = matrix.size(), matrixY = matrix[0].size();
        for (int i = 0; i < matrixX; ++i)
        {
            if (!isToeplitz(matrix[i][0], i+1, 1, matrixX, matrixY, matrix))
                return false;
        }

        for (int i = 0; i < matrixY; ++i)
        {
            if (!isToeplitz(matrix[0][i], 1, i+1, matrixX, matrixY, matrix))
                return false;
        }
        return true;
    }
};