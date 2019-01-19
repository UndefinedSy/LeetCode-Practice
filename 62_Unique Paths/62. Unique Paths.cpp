/**********************************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
**********************************/

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <windows.h>

class Solution {
public:
    int uniquePaths_O_N2(int m, int n) { // naive method with lime cost O(N^2) and memory cost O(m*n)
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
    int uniquePaths_O_N2_clear(int m, int n) { // a clear implementation with lime cost O(N^2) and memory cost O(m*n)
        vector<vector<int> > dp(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
    int uniquePaths(int m, int n) {   // this implementation requires only one column memory
        int len_long = max(m, n);
        int len_short = min(m, n);
        vector<int> dp(len_long, 1);
        for (int i = 1; i < len_short; ++i) {
            for (int j = 1; j < len_long; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[len_long-1];
    }
};

int main() {

}