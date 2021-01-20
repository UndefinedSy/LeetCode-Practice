class Solution {
private:
    void KSort(int l, int r, int TargetPos, std::vector<int>& nums)
    {
        if (r < TargetPos && l > 1) return;
        if (l >= r) return;

        // std::cout << l << " | " << r << std::endl;

        int i = l, j = r;
        int Partition = nums[i];
        while (i < j)
        {
            while (i < j && nums[j] >= Partition) j--;
            if(i < j) nums[i++] = nums[j];
            while (i < j && nums[i] < Partition) i++;
            if(i < j) nums[j--] = nums[i];
        }
        nums[i] = Partition;
        KSort(l, i - 1, TargetPos, nums);
        KSort(i + 1, r, TargetPos, nums);
    }

public:
    int maximumProduct(vector<int>& nums) {
        auto NumsCount = nums.size();
        KSort(0, NumsCount - 1, NumsCount - 3, nums);
        
        return std::max(nums[NumsCount - 1] * nums[NumsCount - 2] * nums[NumsCount - 3],
                        nums[NumsCount - 1] * nums[0] * nums[1]);
    }
};