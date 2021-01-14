// N[i] = (N[i-1] * 2 + A[i])
// N[i] % 5 = (N[i-1] * 2 % 5 + A[i]) % 5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;

        for (int i = 0; i < A.size(); ++i)
        {
            bool CurrentRes;
            if (i == 0) CurrentRes = (A[i] != 0);
            else
            {
                A[i] += (A[i-1] << 1) % 5;
                CurrentRes = A[i] % 5;
            }
            res.push_back(!CurrentRes);
        }
        return res;
    }
};