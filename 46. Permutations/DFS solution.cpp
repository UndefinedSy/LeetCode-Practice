// 本题旨在生成一个数组的全排列，因此可以采用 DFS 的思路，找到每一条长度等于数组 size 的路径。
// 需要注意的是，当我们从一条路径反向回溯时，要将移除的点给重新加入到可用的 list 中即可。

class Solution {
private:
    std::vector<std::vector<int>> Permutations;
    std::vector<bool> Used;
    int TotalNums;

    void SearchQPL(int UsedCounter, const std::vector<int>& Nums,
                   std::vector<int>& CurrentPermutation)
    {
        if (UsedCounter == TotalNums)
        {
            Permutations.push_back(CurrentPermutation);
            return;
        }
        for (int i = 0; i < TotalNums; ++i)
        {
            if (Used[i]) continue;
            Used[i] = true;
            CurrentPermutation[UsedCounter] = Nums[i];
            SearchQPL(UsedCounter+1, Nums, CurrentPermutation);
            Used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        TotalNums = nums.size();
        std::vector<int> CurrentPL(TotalNums);
        Used.resize(TotalNums);
    
        SearchQPL(0, nums, CurrentPL);
        return Permutations; 
    }
};