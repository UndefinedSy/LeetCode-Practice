class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int NumsSize = nums.size();
        if (NumsSize == 0) return 0;

        int MaxLength = -1;
        int StartPos = 0;
        int PrevNum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (PrevNum >= nums[i])
            {
                MaxLength = std::max(MaxLength, i - StartPos);
                StartPos = i;
            }
            PrevNum = nums[i];
        }
        return std::max(MaxLength, NumsSize - StartPos);
    }
};