#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <windows.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.length();
        vector<bool> dpRes(strLen+1, false);
        dpRes[0] = true;
        for (int i = 0; i <= strLen; ++i) {
            for (int j = i; j >= 0; --j) {
                if(dpRes[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                    dpRes[i] = true;
                    break;
                }
            }
        }
        return dpRes[strLen];
    }
};

int main() {
    string strInput, wordInput;
    vector<string> wordDict;
    cin >> strInput;
    while (cin >> wordInput) {
        wordDict.push_back(wordInput);
    }
    cout << Solution().wordBreak(strInput, wordDict) << endl;
    system("pause");
    return 0;
}