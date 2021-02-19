class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l, r;
        l = r = 0;

        int MaxConsecutiveOnes = 0;
        for (; r < nums.size(); ++r)
        {
            if (nums[r] == 1) continue;
            else
            {
                MaxConsecutiveOnes = std::max(MaxConsecutiveOnes, r - l);
                l = r + 1;
            }
        }
        return std::max(MaxConsecutiveOnes, r - l);
    }
};