class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::unordered_map<int, vector<int>> NumDegree;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (NumDegree.count(nums[i]))
            {
                NumDegree[nums[i]][0]++;
                NumDegree[nums[i]][2] = i;
            }
            else
            {
                NumDegree[nums[i]] = {1, i, i};
            }
        }
    
        int MaxDegree = 0, Res = 0x3f3f3f3f;
        for (auto& [_, vec] : NumDegree) {
            if (MaxDegree < vec[0])
            {
                MaxDegree = vec[0];
                Res = vec[2] - vec[1] + 1;
            }
            else if (MaxDegree == vec[0])
            {
                Res = std::min(Res, vec[2] - vec[1] + 1);
            }
        }
        return Res;
    }
};