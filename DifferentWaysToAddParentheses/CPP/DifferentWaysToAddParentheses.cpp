#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;

class Solution
{
public:
  vector<int> diffWaysToCompute(string expression)
  {
    vector<int> answer;
    for (int i = 0; i < expression.size(); i++)
    {
      char current = expression[i];
      if (current == '+' || current == '-' || current == '*')
      {
        vector<int> partOne = diffWaysToCompute(expression.substr(0, i));
        vector<int> partTwo = diffWaysToCompute(expression.substr(i + 1));
        for (int num1 : partOne)
        {
          for (int num2 : partTwo)
          {
            if (current == '+')
            {
              answer.push_back(num1 + num2);
            }
            else if (current == '-')
            {
              answer.push_back(num1 - num2);
            }
            else
            {
              answer.push_back(num1 * num2);
            }
          }
        }
      }
    }

    if (answer.empty())
    {
      answer.push_back(atoi(expression.c_str()));
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.diffWaysToCompute("2-1-1");
  vector<int> result2 = solution.diffWaysToCompute("2*3-4*5");
  vector<int> result3 = solution.diffWaysToCompute("4+6+3-6-7*5*6-22*89+78");
}