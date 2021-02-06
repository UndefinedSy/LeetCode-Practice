// 题目需要从左右两端得到两个子序列，使其总长度为 k 且总和最大。
// 变换一下题意可以得到是求总序列中一段连续的长度为 n - k 最小序列
// 进而可以转换为一个滑动窗口的问题

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int CardNum = cardPoints.size();
        int WindowSize = CardNum - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + WindowSize, 0);
        int MinSum = sum;
        for (int i = WindowSize; i < CardNum; ++i) {
            sum += cardPoints[i] - cardPoints[i - WindowSize];
            MinSum = std::min(MinSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - MinSum;
    }
};