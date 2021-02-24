class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int Length = A.size();
        std::vector<std::vector<int>> Res(Length);
        for (int i = 0; i < Length; ++i)
        {
            Res[i].resize(Length);
            for (int j = 0; j < Length; ++j)
                Res[i][j] = A[i][Length - 1 - j] ^ 1;
        }
        return Res;
    }
};