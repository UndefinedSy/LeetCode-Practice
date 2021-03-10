class Solution {
public:
    string removeDuplicates(string S) {
        std::stack<char> ReverseCharStack;
        for (auto it = S.cbegin(); it != S.cend(); ++it)
        {
            char c = *it;
            if (!ReverseCharStack.empty()
                && ReverseCharStack.top() == c)
                ReverseCharStack.pop();
            else
                ReverseCharStack.push(c);
        }

        char Res[ReverseCharStack.size()+1];
        memset(Res, 0, sizeof(Res));
        int index = ReverseCharStack.size();
        while (index)
        {
            Res[--index] = ReverseCharStack.top();
            ReverseCharStack.pop();
        }

        return std::string(Res);
    }
};