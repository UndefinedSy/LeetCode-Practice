class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> results;

        int i = 0;
        while (i != s.length())
        {
            auto GroupLength = SearchGroup(s, i);
            if (GroupLength >= 3)
                results.emplace_back(std::vector<int>{i, i + GroupLength - 1});

            i += GroupLength;
        }
        return results;
    }

private:
    int SearchGroup(const std::string& s, int StartPos)
    {
        char GroupStartWith = s[StartPos];
        int GroupLength = 1;

        for (int i = StartPos + 1; i < s.length(); ++i)
        {
            if (s[i] != GroupStartWith)
                break;
            ++GroupLength;
        }
        return GroupLength;
    }
};