// https://leetcode.com/problems/largest-odd-number-in-string/?envType=daily-question&envId=2023-12-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  string largestOddNumber(string num)
  {
    for (int i = num.size() - 1; i >= 0; i--)
    {
      if (((num[i] - '0') & 1) == 1)
      {
        return num.substr(0, i + 1);
      }
    }

    return "";
  }
};

int main()
{
  Solution solution;

  string result1 = solution.largestOddNumber("52");
  string result2 = solution.largestOddNumber("4206");
  string result3 = solution.largestOddNumber("35427");
  string result4 = solution.largestOddNumber("3");
  string result5 = solution.largestOddNumber("2");
}