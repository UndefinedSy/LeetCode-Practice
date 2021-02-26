// * 单词 word 中包含谜面 puzzle 的第一个字母。
// * 单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
// 
// 前置条件：
// * puzzles[i].length == 7
// * words[i][j], puzzles[i][j] 都是小写英文字母。
// * 每个 puzzles[i] 所包含的字符都不重复。

// 
// 这个题还是挺有意思的。根据题目要求，我们需要搜索一个 puzzle 中的字母所能够构成的 words，并且 puzzle 的第一个字母必须被使用。
// 由于题目中的 word 和 puzzle 都是小写字母，因此可以将字符串压缩为一个 26 bits 的二进制数
// 这样我们就将问题转换为对一个 puzzle 搜索其可能的组合，并将组合转换为一个 26 bits 的二进制数与 words 匹配的问题。

class Solution {
private:
    std::unordered_map<int, int> WordDict;

    int32_t GenerateBitmap(const std::string& TargetWord)
    {
        int Res = 0;
        for (int i = 0; i < TargetWord.length(); ++i)
        {
            Res |= 1 << (TargetWord[i] - 'a');
        }
        return Res;
    }

    int SearchSubPuzzle(const std::string& TargetPuzzle,
                        int32_t CurrentBitmap, int CurrentIndex)
    {
        int Base = 0;
        if (WordDict.count(CurrentBitmap))
            Base = WordDict[CurrentBitmap];

        if (CurrentIndex < TargetPuzzle.length())
        {
            for (; CurrentIndex < TargetPuzzle.length(); ++CurrentIndex)
            {
                auto NextBitmap = CurrentBitmap | (1 << (TargetPuzzle[CurrentIndex] - 'a'));
                Base += SearchSubPuzzle(TargetPuzzle, NextBitmap, CurrentIndex+1);
            }
        }
        return Base;
    }

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {     
        for (auto&& word : words)
        {
            auto WordBitmap = GenerateBitmap(word);
            if (__builtin_popcount(WordBitmap) <= 7)
                WordDict[WordBitmap]++;
        }

        std::vector<int> Res;
        for (auto&& puzzle : puzzles)
        {
            int32_t FirstChar = 1 << (puzzle[0] - 'a');
            auto PuzzleRes = SearchSubPuzzle(puzzle, FirstChar, 1);
            Res.push_back(PuzzleRes);
        }

        return Res;
    }
};