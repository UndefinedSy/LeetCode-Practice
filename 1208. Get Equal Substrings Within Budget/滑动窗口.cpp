class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        int l = 0, r = 0;
        int sum = 0;
        while (r < s.length()) {
            sum += std::abs(s[r] - t[r]);
            while (sum > maxCost) {
                sum -= std::abs(s[l] - t[l]);
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};