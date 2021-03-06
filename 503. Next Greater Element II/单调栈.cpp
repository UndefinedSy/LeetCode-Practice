// 题目需要为一个循环数组中的每一个元素找到第一个比它大的值。
// 题目可以转换为：
//      维护一个单调递减的栈
//      当找到了第一个更大的值后就将符合条件的栈内符合的元素移除，并继续维护一个单调递减栈

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int numsLength = nums.size();
        std::stack<int> pendingStack;
        std::vector<int> Res(numsLength, -1);
        for (int i = 0; i < 2 * numsLength; ++i)
        {
            while (!pendingStack.empty())
            {
                if (!(nums[pendingStack.top()] < nums[i % numsLength]))
                    break;
                Res[pendingStack.top()] = nums[i % numsLength];
                pendingStack.pop();
            }
            pendingStack.push(i % numsLength);
        }
        return Res;
    }
};