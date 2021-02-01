class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int target = (sumA - sumB) / 2;

        sort(A.begin(), A.end(), less<int>());
        sort(B.begin(), B.end(), less<int>());    

        int EndPosB = B.size() - 1;

        for (int i = 0; i < A.size(); ++i)
        {
            int LowerBoundB = 0;
            int UpperBoundB = EndPosB;

            while (LowerBoundB <= UpperBoundB)
            {
                int j = (LowerBoundB + UpperBoundB) / 2;
                int curr = A[i] - B[j];
                if (curr == target)
                {
                    return {A[i], B[j]};
                }
                else if (curr > target)
                {
                    LowerBoundB = j + 1;
                }
                else
                {
                    UpperBoundB = j - 1;
                }
            }
        }

        return vector<int>();
    }
};