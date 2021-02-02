// 本题旨在维护一个滑动窗口，使得窗口内与 Majority 不重复的字符长度不超过 k。
// 因此我们只需要维护几个状态：
// 1. 当前窗口内的 majority 大小
// 2. 历史上最长的窗口大小
// 3. 当前窗口内各个字符的长度
// 
// 最后这个最长的窗口大小即是替换掉 k 个字符后的最长重复子串

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> CharInWindow(26);
        int l = 0;
        int MaxRepeatedLength = 0;
        int LongestRepeatedCharLength = 0;
        for (int r = 0; r < s.length(); ++r)
        {
            CharInWindow[s[r] - 'A']++;
            LongestRepeatedCharLength = std::max(LongestRepeatedCharLength, CharInWindow[s[r] - 'A']);
            if (r - l + 1 - LongestRepeatedCharLength > k)
            {
                CharInWindow[s[l] - 'A']--;
                l++;
            }
            MaxRepeatedLength = std::max(MaxRepeatedLength, r - l + 1);
            // std::cout << "Current Char: " << s[r]
            //           << " | L is:" << l << " / R is: " << r
            //           << " | LongestRepeatedCharLength is: " << LongestRepeatedCharLength
            //           << " | MaxRepeatedLength is: " << MaxRepeatedLength << std::endl;
        }
        return MaxRepeatedLength;
    }
};