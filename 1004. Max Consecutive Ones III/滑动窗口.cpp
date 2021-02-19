class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l, r;
        int MaxLength;
        l = r = MaxLength = 0;
        
        for (; r < A.size(); ++r)
        {
            if (A[r]) continue;

            if (K)
                K--;
            else
            {
                MaxLength = std::max(MaxLength, r - l);
                while (l <= r)
                {
                    if (!A[l]) break;
                    ++l;
                }
                ++l;
            }
        }

        return std::max(MaxLength, r - l);
    }
};