class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> dp(nums.size());
        int Res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int prevMax = 0;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    prevMax = std::max(prevMax, dp[j]);
            }
            dp[i] = prevMax + 1;
            Res = std::max(Res, dp[i]);
        }
        return Res;
    }
};