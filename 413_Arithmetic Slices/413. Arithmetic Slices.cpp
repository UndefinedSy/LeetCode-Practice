/*******************************************************
A sequence of number is called arithmetic if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. 
A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*******************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices_O_N2(vector<int>& A) { // this naive method cost memory O(N^2), when the input vector is enormous will cause runtime error.
        const int inputLen = A.size();
        if (inputLen < 3) return 0;
        int res[inputLen][inputLen];
        memset(res, 0, sizeof(res));
        
        for (int j = 2; j < inputLen; ++j) {
            for (int i = 0; i < inputLen-2; ++i) {
                if (i + j < inputLen) {
                    res[i][i+j] = res[i][i+j-1] + res[i+1][i+j];
                    if (A[i] - A[i+1] == A[i+1] - A[i+2]) { // according to this line, we just need to check the previous index
                        res[i][i+j] += 1;
                    }
                }
            }
        }

        return res[0][inputLen-1]; 
    }

    int numberOfArithmeticSlices(vector<int>& A) { // actually only a N size array is necessary
        const int inputLen = A.size();
        if (inputLen < 3) return 0;
        vector<int> dp(inputLen, 0);
        dp[2] = (A[0] - A[1] == A[1] - A[2]) ? 1 : 0;
        int res = dp[2];

        for (int i = 3; i < inputLen; ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;    // 1 means the array A[i-2]~A[i] formed a arithmetic slices, and has the same differece in value
            }
            res += dp[i];
        }

        return res;
    }

};