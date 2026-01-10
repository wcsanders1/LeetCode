// https://leetcode.com/problems/delete-columns-to-make-sorted/?envType=daily-question&envId=2026-01-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
  int minDeletionSize(vector<string> &strs)
  {
    int cols = strs[0].size();
    unordered_set<int> deletedCols;
    vector<bool> skip(cols, false);
    for (int c = 0; c < cols; c++)
    {
      if (deletedCols.find(c) != deletedCols.end())
      {
        continue;
      }

      for (int s = 1; s < strs.size(); s++)
      {
        if (skip[s - 1])
        {
          continue;
        }

        if (strs[s - 1][c] > strs[s][c])
        {
          deletedCols.insert(c);
          skip = vector<bool>(cols, false);
          c = -1;
          break;
        }

        if (strs[s - 1][c] < strs[s][c])
        {
          skip[s - 1] = true;
        }
      }
    }

    return deletedCols.size();
  }
};

int main()
{
  Solution solution;
  int result1 = solution.minDeletionSize(*new vector<string>{"ca", "bb", "ac"});           // 1
  int result2 = solution.minDeletionSize(*new vector<string>{"xc", "yb", "za"});           // 0
  int result3 = solution.minDeletionSize(*new vector<string>{"zyx", "wvu", "tsr"});        // 3
  int result4 = solution.minDeletionSize(*new vector<string>{"xga", "xfb", "yfa"});        // 1
  int result5 = solution.minDeletionSize(*new vector<string>{"dhjwdxmq", "dzsnbenh"});     // 0
  int result6 = solution.minDeletionSize(*new vector<string>{"vdy", "vei", "zvc", "zld"}); // 2
}