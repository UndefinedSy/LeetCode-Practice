class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        for (int i = 0; i < isConnected.size(); ++i)
            ancestors.emplace_back(i);
        
        for (int i = 0; i < isConnected.size(); ++i)
        {
            for (int j = 0; j < isConnected.size(); ++j)
            {
                if (i == j) continue;

                if (isConnected[i][j])
                    unionSet(i, j);
            }
        }

        int Provinces = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (ancestors[i] == i)
                ++Provinces;
        }

        return Provinces;

    }

private:
    std::vector<int> ancestors;

    int find(int x)
    {
        if (x != ancestors[x])
            ancestors[x] = find(ancestors[x]);
        return ancestors[x];
    }

    void unionSet(int x, int y)
    {
        auto xx = find(x);
        auto yy = find(y);

        if (xx == yy) return;
        
        ancestors[xx] = yy;
    }
};