class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int OriginRow = nums.size();
        int OriginCol = nums[0].size();
        if (r * c != OriginRow * OriginCol) return nums;

        std::vector<std::vector<int>> Res(r);
        int ResRow = 0, ResColumn = 0;
        for (int i = 0; i < OriginRow; ++i)
        {
            auto&& CurrRow = nums[i];
            for (int j = 0; j < OriginCol; ++j)
            {
                Res[ResRow].emplace_back(CurrRow[j]);
                ++ResColumn;
                if (ResColumn == c)
                {
                    ++ResRow;
                    ResColumn = 0;
                }
            }
        }
        return Res;
    }
};