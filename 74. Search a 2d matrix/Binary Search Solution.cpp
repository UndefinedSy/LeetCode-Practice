class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        int rawCount = matrix.size();
        int columnCount = matrix[0].size();

        int targetRaw = FindRaw(matrix, target);
        if (targetRaw == -1) return false;

        return FindColumn(matrix[targetRaw], target);
    }

private:
    int FindRaw(const vector<vector<int>>& matrix, const int target)
    {
        int l = 0;
        int r = matrix.size() - 1;
        int targetRaw = -1;

        while (l <= r)
        {
            int m = (l + r) / 2;

            const std::vector<int>& tmpMatrixRaw = matrix[m];

            if (target < tmpMatrixRaw.front()) r = m - 1;
            else if (target > tmpMatrixRaw.back()) l = m + 1;
            else {targetRaw = m; break;} 
        }

        return targetRaw;
    }

    bool FindColumn(const vector<int>& raw, const int target)
    {
        if (raw.empty()) return false;

        int l = 0;
        int r = raw.size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;

            int tmpValue = raw[m];

            if (target < tmpValue) r = m - 1;
            else if (target > tmpValue) l = m + 1;
            else return true; 
        }

        return false;
    }
};