// 题目中提到，骨牌只有两个面，且每个面的大小在 0~9
// 因此这里可以将骨牌的唯一标识转换为一个 00~99 之间整数


class Solution {
private:
    std::vector<int> ExistingDominoes;

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        ExistingDominoes.resize(100);
        int Res = 0;
        for (auto&& domino: dominoes)
        {
            int val = domino[0] < domino[1]
                      ? domino[0] * 10 + domino[1]
                      : domino[1] * 10 + domino[0];
            Res += ExistingDominoes[val]++;
        }

        return Res;
    }
};