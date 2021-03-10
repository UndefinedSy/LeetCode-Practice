// 很容易能想到，表达式可以通过查找左/右括号，并通过递归和栈将表达式拆分为多个无括号的表达式
// 但是由于本题条件为只有 +/-，也就没有运算符优先级的差异，因此可以直接将所有括号展开
// 但是需要注意的是，如果括号表达式前面有一个负号，则括号表达式内的所有运算符需要取反
// 因此对可以将每个左括号前的运算符入栈，来控制展开过程中是否需要变号

class Solution {
public:
    int calculate(string s) {
        int StringLength = s.length();
        std::stack<int> UnusedSignStack;
        UnusedSignStack.push(1);

        int sign = 1;
        long long Res = 0;

        int cur = 0;
        while (cur < StringLength)
        {
            switch (s[cur])
            {
                case ' ':
                    cur++;
                    break;
                case '+':
                    sign = UnusedSignStack.top();
                    cur++;
                    break;
                case '-':
                    sign = -UnusedSignStack.top();
                    cur++;
                    break;
                case '(':
                    UnusedSignStack.push(sign);
                    cur++;
                    break;
                case ')':
                    UnusedSignStack.pop();
                    cur++;
                    break;
                default:
                    long long num = 0;
                    while (cur < StringLength
                           && s[cur] >= '0'
                           && s[cur] <= '9')
                    {
                        num = num * 10 + s[cur++] - '0';
                    }
                    Res += sign * num;
            }
        }
        return Res;
    }
};