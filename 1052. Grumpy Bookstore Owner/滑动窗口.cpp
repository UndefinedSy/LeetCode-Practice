// 本题需要得到一个最大的客户满意值，转换以下就是求店主的最大冷静值
// 因此可以先将每个点的用户数 * 是否愤怒，将原本的愤怒状态变为愤怒的影响值
// 之后则只需要用一个滑动窗口去遍历每个窗口内的收益

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int TotalCustomerCount = 0;
        int TotalGrumpyCount = 0;
        for (int i = grumpy.size() - 1; i >= 0; --i)
        {
            TotalCustomerCount += customers[i];
            if (grumpy[i])
            {
                grumpy[i] *= customers[i];
                TotalGrumpyCount += grumpy[i];
            }
        }

        int CurrentCalmCount = 0;
        for (int i = 0; i < X; ++i)
        {
            CurrentCalmCount += grumpy[i];
        }
        int MaxCalmCount = CurrentCalmCount;

        for (int i = X; i < grumpy.size(); ++i)
        {
            CurrentCalmCount = CurrentCalmCount - grumpy[i-X] + grumpy[i];
            MaxCalmCount = std::max(MaxCalmCount, CurrentCalmCount);
        }

        return TotalCustomerCount - TotalGrumpyCount + MaxCalmCount;
    }
};