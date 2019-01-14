/**************************************
 A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
 *************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <windows.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> charOccuredPos;
        vector<int> res;
        charOccuredPos.clear();
        res.clear();
        int partEnd = -1, partBegin = 0;
        for (int i = 0; i < S.length(); ++i) {
            charOccuredPos[S[i]] = i;
        }
        for (int i = 0; i < S.length(); ++i) {
            if (partEnd < 0 || charOccuredPos[S[i]] > partEnd) {
                partEnd = charOccuredPos[S[i]];
            }
            if (i == partEnd) {
                res.push_back(partEnd - partBegin + 1);
                partEnd = -1;
                partBegin = i + 1;
            }
        }
        return res;
    }
};
