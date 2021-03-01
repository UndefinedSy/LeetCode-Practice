class NumArray {
private:
    std::vector<int> nums_;

public:
    NumArray(vector<int>& nums)
    {
        nums_.resize(nums.size());
        int TmpSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            TmpSum += nums[i];
            nums_[i] = TmpSum;
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
            return nums_[j];
        else
            return nums_[j] - nums_[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */