// https://leetcode.com/problems/largest-3-same-digit-number-in-string/?envType=daily-question&envId=2023-12-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  string largestGoodInteger(string num)
  {
    char prev = num[0];
    int count = 1;
    int greatest = -1;
    for (int i = 1; i < num.size(); i++)
    {
      char &c = num[i];
      if (c == prev)
      {
        if (++count == 3 && c > greatest)
        {
          greatest = c;
          prev = c;
          count = 1;
        }
      }
      else
      {
        prev = c;
        count = 1;
      }
    }

    if (greatest == -1)
    {
      return "";
    }

    string answer = "";
    for (int i = 0; i < 3; i++)
    {
      answer += (char)greatest;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.largestGoodInteger("6777133339");
  string result2 = solution.largestGoodInteger("2300019");
  string result3 = solution.largestGoodInteger("42352338");
}