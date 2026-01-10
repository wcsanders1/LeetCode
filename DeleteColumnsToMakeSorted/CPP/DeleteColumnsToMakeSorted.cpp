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
    int deletions = 0;
    for (int i = 0; i < strs[0].size(); i++)
    {
      for (int sn = 1; sn < strs.size(); sn++)
      {
        if (strs[sn - 1][i] > strs[sn][i])
        {
          deletions++;
          break;
        }
      }
    }

    return deletions;
  }
};

int main()
{
  Solution solution;
  int result1 = solution.minDeletionSize(*new vector<string>{"cba", "daf", "ghi"});
  int result2 = solution.minDeletionSize(*new vector<string>{"a", "b"});
  int result3 = solution.minDeletionSize(*new vector<string>{"zyx", "wvu", "tsr"});
}