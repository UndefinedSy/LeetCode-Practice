class Solution {
private:
    int directions[8][2] = 
    {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}
    };

    int SearchPondSize(vector<vector<int>>& land, std::pair<int, int> start_pos)
    {
        auto y_length = land.size();
        auto x_length = land[0].size();

        std::queue<std::pair<int, int> > AvailablePondQueue;
        AvailablePondQueue.push(start_pos);
        land[start_pos.first][start_pos.second] = -1;
        int PondSize = 1;

        while (!AvailablePondQueue.empty())
        {
            auto& search_pos = AvailablePondQueue.front();
            AvailablePondQueue.pop();

            for (int i = 0; i < 8; ++i)
            {
                auto next_y = search_pos.first + directions[i][0];
                auto next_x = search_pos.second + directions[i][1];

                if (next_x >= 0 && next_x < x_length && next_y >= 0 && next_y < y_length)
                {
                    if (!land[next_y][next_x])
                    {
                        AvailablePondQueue.emplace(next_y, next_x);
                        land[next_y][next_x] = -1;
                        ++PondSize;
                    }
                }
            }
        }

        return PondSize;
    }

public:
    vector<int> pondSizes(vector<vector<int>>& land)
    {
        auto y_length = land.size();
        auto x_length = land[0].size();

        std::vector<int> results;

        for (int i = 0; i < y_length; ++i)
        {
            for (int j = 0; j < x_length; ++j)
            {
                if (land[i][j] == 0)
                {
                    results.emplace_back(SearchPondSize(land, std::make_pair(i, j)));
                }
            }
        }
        
        std::sort(results.begin(), results.end());
        return results;
    }
};