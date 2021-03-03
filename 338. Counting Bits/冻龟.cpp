// 其背景是一个数如果左移一位，则在值上反映为 * 2
// 进而就是有两种情况，即
// * 左移后末位为 1，此时总的 countBits + 1
// * 左移后末位为 0，此时总的 countBits 不变
// 因此可以得到冻龟方程 f[n] = f[n/2] + n % 2;

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> Res(num+1);
        for (int i = 1; i <= num; ++i)
            Res[i] = Res[i >> 1] + (i & 1);
        return Res;
    }
};