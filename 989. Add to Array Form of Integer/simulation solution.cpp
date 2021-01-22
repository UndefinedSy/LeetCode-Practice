// 这个问题本身是很简单的，唯一需要注意的是进位。
// * 若在对应位置 Array 中没有值，则直接填上对应位置即可。
// * 若在对应位置 Array 有值，且求和之后得到的结果 >= 10, 则需要递归的向前求进位。

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int OpCounter = 0;
        int ArraySize = A.size() - 1;
        while (K)
        {
            int Postion = ArraySize - OpCounter;
            if (Postion < 0)
            {
                A.insert(A.begin(), K % 10);
                ArraySize++;
            }
            else
            {
                A[Postion] += K % 10;
                while (A[Postion] >= 10)
                {
                    A[Postion] -= 10;
                    if (Postion)
                        A[--Postion] += 1;
                    else
                    {
                        A.insert(A.begin(), 1);
                        ArraySize++;
                    }
                }
            }
            K /= 10;
            OpCounter++;
        }
        return A;
    }
};