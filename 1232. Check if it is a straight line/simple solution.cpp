class Solution {
private:
    void GetBaseGradient(const vector<int>& Point0, const vector<int>& Point1,
                         double& Gradient, bool& Vertical)
    {
        int DeltaX = Point1[0] - Point0[0];
        int DeltaY = Point1[1] - Point0[1];

        if (!DeltaX) Vertical = true;
        else
        {
            Gradient = (double)DeltaY / DeltaX;
        }
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double Gradient = -1;
        bool Vertical = false;
        GetBaseGradient(coordinates[0], coordinates[1], Gradient, Vertical);

        int x = coordinates[0][0];
        int y = coordinates[0][1];
        int PointNum = coordinates.size();
        for (int i = 2; i < PointNum; ++i)
        {
            const auto& TargetPoint = coordinates[i];

            int DeltaX = TargetPoint[0] - x;
            int DeltaY = TargetPoint[1] - y;

            if (!DeltaX)
            {
                if (Vertical) continue;
                return false;
            }

            double tmpGradient = (double)DeltaY / DeltaX;
            // cout << "Point " << i << ": " << tmpGradient << endl;
            if (Gradient != tmpGradient || Vertical)
                return false;
        }
        return true;
    }
};