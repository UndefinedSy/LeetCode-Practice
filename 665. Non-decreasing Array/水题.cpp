// 模拟遍历一遍即可，记录出现排序冲突次数
// 需要注意的是，当  num[i] > num[i+1] 时，变换元素需要考虑变换的位置
// 因为我是从左往右遍历，因此需要考虑
// * 若 num[i-1] > num[i+1] ===> 将 num[i+1] 变为 num[i]，以满足变化后不破坏前缀系列的单调性。
// * 否则，将 num[i] 变为 num[i+1] 以最小化后后缀数组的影响

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ConfictNum = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                ConfictNum++;
                if (ConfictNum > 1) return false;

                if (i > 0 && nums[i - 1] > nums[i + 1])
                    nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};