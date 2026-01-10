// https://leetcode.com/problems/delete-columns-to-make-sorted/?envType=daily-question&envId=2026-01-06
// NOT MINE: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/solutions/205679/javacpython-maximum-increasing-subsequen-wio6/?envType=daily-question&envId=2026-01-06
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
    int rows = strs.size();
    int cols = strs[0].size();
    int r = 0;
    vector<int> lis(cols, 1);
    int deletions = cols - 1;
    for (int c = 0; c < cols; c++)
    {
      for (int ic = 0; ic < c; ic++)
      {
        for (r = 0; r < rows; r++)
        {
          if (strs[r][ic] > strs[r][c])
          {
            break;
          }
        }
        if (r == rows && lis[ic] + 1 > lis[c])
        {
          lis[c] = lis[ic] + 1;
        }
      }
      deletions = min(deletions, cols - lis[c]);
    }

    return deletions;
  }
};

int main()
{
  Solution solution;
  int result1 = solution.minDeletionSize(*new vector<string>{"babca", "bbazb"});    // 3
  int result2 = solution.minDeletionSize(*new vector<string>{"edcba"});             // 4
  int result3 = solution.minDeletionSize(*new vector<string>{"ghi", "def", "abc"}); // 0
  int result4 = solution.minDeletionSize(*new vector<string>{"baabab"});            // 2
}