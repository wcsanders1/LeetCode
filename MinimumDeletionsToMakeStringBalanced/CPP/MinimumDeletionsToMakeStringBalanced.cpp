// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30
// NOT MINE: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/solutions/5555960/easy-one-pass-o-1-space-solution-c-python-java/?envType=daily-question&envId=2024-07-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int minimumDeletions(string s)
  {
    int bs = 0;
    int deletions = 0;
    for (char &c : s)
    {
      if (c == 'b')
      {
        bs++;
      }
      else if (bs > 0)
      {
        bs--;
        deletions++;
      }
    }

    return deletions;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumDeletions("aababbab");
  int result2 = solution.minimumDeletions("bbaaaaabb");
}