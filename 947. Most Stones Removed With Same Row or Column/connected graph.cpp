class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int StoneNum = stones.size();
        std::vector<bool> Removeable(StoneNum);
        int res = 0;
        for (int i = 0; i < StoneNum; ++i)
        {
            if (!Removeable[i])
            {
                res++;
                Removeable[i] = true;
                SetRemoveable(stones, i, Removeable);
            }
            
        }
        
        return StoneNum - res;
    }

private:
    void SetRemoveable(const vector<vector<int>>& stones,
                       int StoneNo, std::vector<bool>& Removeable)
    {
        int x = stones[StoneNo][1];
        int y = stones[StoneNo][0];
        for (int i = 0; i < stones.size(); ++i)
        {
            if (Removeable[i]) continue;

            if (stones[i][0] == y || stones[i][1] == x)
            {
                Removeable[i] = true;
                // std::cout << "(" << stones[i][0] << ", " << stones[i][1] << ") has been marked as removeable." << std::endl;
                SetRemoveable(stones, i, Removeable);
            }
        }
    }
};