class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        FinishPoint = std::make_pair(m - 1, n - 1);

        std::vector<int> tmpRes(m*n);

        SearchPath(obstacleGrid, 0, 0, tmpRes);
        
        return tmpRes[0];
    }

private:
    std::pair<int, int> FinishPoint;
    int m, n;
    int DirectionX[2] = {0, 1};
    int DirectionY[2] = {1, 0};


    int SearchPath(const vector<vector<int>>& obstacleGrid,
                    int x, int y, std::vector<int>& tmpRes)
    {
        // std::cout << y * n + x << ": " << tmpRes[y * n + x] << std::endl;
        if (tmpRes[y * n + x] != 0) return tmpRes[y * n + x];
        if (obstacleGrid[y][x] == 1) return 0;
        if (y == std::get<0>(FinishPoint) && x == std::get<1>(FinishPoint))
        {
            tmpRes[y * n + x] = 1;
            return 1;
        }

        int DirectionRes[2] = {0, 0};
        for (int i = 0; i < 2; ++i)
        {
            int tmpX = x + DirectionX[i];
            int tmpY = y + DirectionY[i];
            if (tmpX < n && tmpY < m)
            {
                DirectionRes[i] = SearchPath(obstacleGrid, tmpX, tmpY, tmpRes);
            }
        }
        tmpRes[y * n + x] = DirectionRes[0] + DirectionRes[1];
        // std::cout << DirectionRes[0] << " | " << DirectionRes[1] << std::endl;
        return tmpRes[y * n + x];
    }

};