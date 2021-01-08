class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return; 
        // std::reverse(nums.begin(), nums.end());
        // std::reverse(nums.begin(), nums.begin() + k);
        // std::reverse(nums.begin() + k, nums.end());
        ReverseVector(nums, 0, nums.size()-1);
        ReverseVector(nums, 0, k-1);
        ReverseVector(nums, k, nums.size()-1);
    }

private:
    void ReverseVector(vector<int>& VectorToReverse, int l, int r)
    {
        if (l == r) return;

        auto mid = (r - l) / 2;
        for (int i = 0; i <= mid; ++i)
            std::swap(VectorToReverse[l+i], VectorToReverse[r-i]);
    }
};