/****************************************
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

Longest Palindromic Substring is a typical DP problem.
The naive method requires time complexity O(n^3)
while using DP can reduce it to O(n^2)
Furthermore, the Manacher's Algorithm only costs O(n) time complexity.
****************************************/ 

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSeqDP(string s) {
        const int len = s.length();
        bool dp[len][len];  // dp array record the index i,j can constitute a palindrome subsequence
        memset(dp, 0, sizeof(dp));
        int res = 1;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i - j <= 1) { // a character or two
                    dp[j][i] = (s[j] == s[i]);
                }
                else {
                    dp[j][i] = (s[j] == s[i] && dp[j+1][i-1]);
                }
                if (dp[j][i] && res < i-j+1) {
                    res = i - j + 1;
                }
            }
        }
        return res;
    }
    
    int longestPalindromeSubseq(string s) {
        const int len = s.length();
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int i = len-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < len; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};
