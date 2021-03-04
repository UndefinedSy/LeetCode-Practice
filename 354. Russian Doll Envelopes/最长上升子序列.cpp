class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::vector<int> dp(envelopes.size());
        int Res = 0;
        std::sort(envelopes.begin(), envelopes.end(),
                  [] (const std::vector<int>& a, const std::vector<int>& b) -> bool
                  { return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);} );
        for (int i = 0; i < envelopes.size(); ++i)
        {
            int prevMax = 0;
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[j][0] < envelopes[i][0]
                    && envelopes[j][1] < envelopes[i][1])
                    prevMax = std::max(prevMax, dp[j]);
            }
            dp[i] = prevMax + 1;
            Res = std::max(Res, dp[i]);
        }
        return Res;
    }
};