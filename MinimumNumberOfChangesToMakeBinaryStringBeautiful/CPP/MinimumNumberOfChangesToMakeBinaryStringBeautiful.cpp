// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minChanges(string s)
  {
    int answer = 0;
    for (int i = 0; i < s.size(); i += 2)
    {
      if (s[i] != s[i + 1])
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minChanges("1001");
  int result2 = solution.minChanges("10");
  int result3 = solution.minChanges("0000");
}