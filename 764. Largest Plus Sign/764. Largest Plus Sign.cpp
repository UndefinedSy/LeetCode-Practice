/******************************************************
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, 
except those cells in the given list mines which are 0. 
What is the largest axis-aligned plus sign of 1s contained in the grid? 
Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. 
This is demonstrated in the diagrams below. 
Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)

Hide Hint 1:
For each direction such as "left", find left[r][c] = the number of 1s you will see before a zero starting at r, c and walking left. 
You can find this in N^2 time with a dp. 
The largest plus sign at r, c is just the minimum of left[r][c], up[r][c] etc.

Obviously, this is a problem about gready.
A naive solution is to use 5 n*n matrix to store the map and the four direction with the time complexity is O(N^2)
An optimization is 5 matrix is not necessary, since we only concern about the shortest length of the four directions.
******************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <malloc.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign_1(int N, vector<vector<int>>& mines) {   // time complexity: O(N^2), memory complexity: O(N^3) 
        int res = 0;
        //  4 n*n arrays to store the maxtrix of 1s length going l, r, u, d
        int ***plusNumDirection = (int***)malloc(sizeof(int**)*4);
        for (int i = 0; i < 4; ++i) {
            plusNumDirection[i] = (int**)malloc(sizeof(int*)*N);
            for (int j = 0; j < N; ++j) {
                plusNumDirection[i][j] = (int*)malloc(sizeof(int)*N);
            }
        }

        int** plusMap = new int*[N];
        for (int i = 0; i < N; ++i) {
            plusMap[i] = new int[N];
        }        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                plusMap[i][j] = 1;
                for (int k = 0; k < 4; ++k) {
                    plusNumDirection[k][i][j] = 1;
                }
            }
        }
        for (auto posPair : mines) {
            plusMap[posPair[0]][posPair[1]] = 0;
            for (int k = 0; k < 4; ++k) {
                    plusNumDirection[k][posPair[0]][posPair[1]] = 0;
                }
        }
        
        //----------------------init part above--------------------//

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (plusMap[i][j] == 1) {
                    if (i - 1 >= 0) {   // the num of left 1s
                        plusNumDirection[0][i][j] = plusNumDirection[0][i-1][j]+1;
                    }
                    if (j - 1 >= 0) {   // the num of up 1s
                        plusNumDirection[1][i][j] = plusNumDirection[1][i][j-1]+1;
                    }
                }
            }
        }

        for (int i = N-1; i >=0; --i) {
            for (int j = N-1; j >= 0; --j) {
                if (plusMap[i][j] == 1) {
                    if (i + 1 < N) {   // the num of right 1s
                        plusNumDirection[2][i][j] = plusNumDirection[2][i+1][j]+1;
                    }
                    if (j + 1 < N) {   // the num of down 1s
                        plusNumDirection[3][i][j] = plusNumDirection[3][i][j+1]+1;
                    }
                    int minTmp = 0x3f3f3f3f;
                    for (int k = 0; k < 4; ++k) {
                        if (plusNumDirection[k][i][j] < minTmp) {
                            minTmp = plusNumDirection[k][i][j];
                        }
                    }
                    res = max(res, minTmp);
                }
            }
        }

        // release heap memory in C
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < N; ++j) {
                free((int*)plusNumDirection[i][j]);
            }
            free((int**)plusNumDirection[i]);
        }
        free((int***)plusNumDirection);
        // release heap memory in C++
        delete[] plusMap;

        return res;
    }
    //---------------------------------------------------------------------------
    // some optimizations:
    // 1.it will be helpful if we just track the direction with shortest path of 1s
    // 2.make the code more concise

    int orderOfLargestPlusSign_2(int N, vector<vector<int>>& mines) { // this method cose time with O(N^3) and memory with O(N^2)
        int maxi=0;
        vector<vector<int>> m(N,vector<int>(N,1));
        for (auto &v: mines) m[v[0]][v[1]] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0, k = 0; j < N; ++j, k = 0) {
                while (canExpand(N,i,j,k,m)) ++k;
                maxi=max(maxi,k);
            }
        }
        return maxi;
    }
    //---------------------------------------------------------------------------
    // a greater solution:
    // the above solution cal the 1s length repeatly
    // so if we can use the previous information, it will cost less time.

    int orderOfLargestPlusSign_3(int N, vector<vector<int>>& mines) { // this method cose time with O(N^3) and memory with O(N^2)
        int res = 0;
        vector<vector<int>> m(N,vector<int>(N,0x3f3f3f3f));
        for (auto &v: mines) m[v[0]][v[1]] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0, k = N - 1, l = 0, r = 0, u = 0, d = 0; j < N && k >= 0; ++j, --k) { // min can make sure the final result of each cell is the shortest length
                m[i][j] = min(m[i][j], l = (m[i][j] == 0 ? 0 : l + 1)); // expand from left to right
                m[i][k] = min(m[i][k], r = (m[i][k] == 0 ? 0 : r + 1)); // expand from right to left
                m[j][i] = min(m[j][i], u = (m[j][i] == 0 ? 0 : u + 1)); // expand from top to down
                m[k][i] = min(m[k][i], d = (m[k][i] == 0 ? 0 : d + 1)); // expand from bottom to top
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res = max(res, m[i][j]);
            }
        }
        return res;
    }

private:
    bool canExpand(int N, int x, int y, int k, vector<vector<int>>& m){ //  N: the size of map, (x, y) lables the current pos, k records the current size of plus.
        if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N) return false;
        return m[x-k][y] && m[x][y+k] && m[x+k][y] && m[x][y-k];    //  the shortest length of the four directions.
    }

};
