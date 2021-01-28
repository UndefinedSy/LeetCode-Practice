// 由于本题要求多个 pivot index 时输出左侧的 index
// 因此首先求出整个数组的和，作为后缀和；
// 之后从左到右，每次一个点加入前缀，这样找到第一个 pivot 就可以直接退出了。

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int RightSum = std::accumulate(nums.begin(), nums.end(), 0);
        int LeftSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            LeftSum += (i == 0 ? 0 : nums[i-1]);
            RightSum -= nums[i];
            if (LeftSum == RightSum) return i;
        }
        return -1;
    }
};