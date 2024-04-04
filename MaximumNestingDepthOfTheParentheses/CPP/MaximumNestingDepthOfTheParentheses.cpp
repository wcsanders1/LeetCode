// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04
#include <vector>
#include <unordered_set>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int maxDepth(string s)
  {
    int count = 0;
    int answer = 0;
    for (char &c : s)
    {
      if (c == '(')
      {
        answer = max(answer, ++count);
      }
      if (c == ')')
      {
        count--;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxDepth("(1+(2*3)+((8)/4))+1");
  int result2 = solution.maxDepth("(1)+((2))+(((3)))");
}