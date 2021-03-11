// 由于本题中不允许括号表达式，因此可以按照运算优先级，先乘除后加减
// 将结果都存放在一个栈中，最后算栈内数据的和即可。
// > +、-：对后一个数去正/反
// > *、/: 弹出栈顶的值，优先运算，并将结果重新压栈
// 这样最后栈里面的数据的求和就是次优先级的加减运算

class Solution {
public:
    int calculate(string s) {
        std::stack<int> Nums;
        int sign = 1;
        int ExpLength = s.length();

        int cur = 0;
        while (cur < ExpLength)
        {
            switch (s[cur])
            {
                case ' ':
                    cur++;
                    break;
                case '+':
                    sign = 1;
                    cur++;
                    break;
                case '-':
                    sign = -1;
                    cur++;
                    break;
                case '*':
                    sign = 2;
                    cur++;
                    break;
                case '/':
                    sign = 3;
                    cur++;
                    break;
                default:
                    long num = 0;
                    while (cur < s.length() && s[cur] >= '0' && s[cur] <= '9')
                    {
                        num = num * 10 + s[cur++] - '0';
                    }
                    int tmp;
                    switch (sign)
                    {
                        case 1:
                        case -1:
                            Nums.push(num * sign);
                            break;
                        case 2:
                            tmp = Nums.top();
                            Nums.pop();
                            Nums.push(tmp * num);
                            break;
                        case 3:
                            tmp = Nums.top();
                            Nums.pop();
                            Nums.push(tmp / num);
                            break;           
                    }
            }
        }

        int Res = 0;
        while (!Nums.empty())
        {
            Res += Nums.top();
            Nums.pop();
        }

        return Res;
    }
};