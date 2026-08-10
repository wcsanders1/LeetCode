// https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08
// NOT MINE: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/solutions/8448020/simple-suffix-and-string-construction-by-z9bo/?envType=daily-question&envId=2026-08-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> validSequence(string word1, string word2)
  {
    int size1 = word1.size();
    int size2 = word2.size();
    vector<int> suf(size1, 0);
    int sufCount = 0;
    int word2Index = size2 - 1;
    for (int i = size1 - 1; i >= 0; i--)
    {
      suf[i] = sufCount;
      if (word2Index >= 0 && word1[i] == word2[word2Index])
      {
        sufCount++;
        word2Index--;
      }
    }

    vector<int> indexes;
    bool changed = false;
    word2Index = 0;
    for (int i = 0; i < size1 && word2Index < size2; i++)
    {
      if (word1[i] == word2[word2Index])
      {
        indexes.push_back(i);
        word2Index++;
      }
      else if (!changed && suf[i] >= size2 - 1 - word2Index)
      {
        changed = true;
        indexes.push_back(i);
        word2Index++;
      }
    }

    if (indexes.size() == size2)
    {
      return indexes;
    }

    return {};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.validSequence("vbcca", "abc");
  auto result2 = solution.validSequence("bacdc", "abc");
}