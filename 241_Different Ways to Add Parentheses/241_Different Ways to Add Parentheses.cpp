#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isOperator(char currentChar) {
        return(currentChar == '+' || currentChar == '-' || currentChar == '*');
    }

    std::vector<int> diffWaysToCompute(std::string exp) {
        std::vector<int> arrayLeft;
        std::vector<int> arrayRight;
        std::vector<int> res;
        int stringIter;

        arrayLeft.clear();
        arrayRight.clear();
        res.clear();

        for(stringIter = 0; stringIter < exp.length(); ++stringIter) {
            if (isOperator(exp[stringIter])) {
                arrayLeft = diffWaysToCompute(exp.substr(0, stringIter));
                arrayRight = diffWaysToCompute(exp.substr(stringIter+1));
                for (int arrIterL = 0; arrIterL < arrayLeft.size(); ++arrIterL) {
                    for (int arrIterR = 0; arrIterR < arrayRight.size(); ++arrIterR) {
                        switch (exp[stringIter]) {
                            case '+':
                                res.push_back(arrayLeft[arrIterL] + arrayRight[arrIterR]);
                                break;
                            case '-':
                                res.push_back(arrayLeft[arrIterL] - arrayRight[arrIterR]);
                                break;
                            case '*':
                                res.push_back(arrayLeft[arrIterL] * arrayRight[arrIterR]);
                                break;
                        }
                    }
                }
            }
        }
        if (!res.size()) {
            res.push_back(atoi(exp.c_str()));
        }
        sort(res.begin(), res.end());
        return res;
    }

    void printVecRes(std::vector<int> res) {
        std::cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            std::cout << res[i] << (i == res.size()-1 ? "]\n" : ", ");
        }
    }

};

int main() {
    std::string exp;
    std::cin >> exp;
    exp.erase(std::remove(exp.begin(), exp.end(), '\"'), exp.end());
    std::vector<int> res = Solution().diffWaysToCompute(exp);
    Solution().printVecRes(res);
    //system("pause");
    return 0;
}