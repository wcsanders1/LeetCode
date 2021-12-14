#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int answer = 0;
    string currentNumberStr = "";
    int currentNumber = 0;
    char nextOperation = '+';
    char priorOperation = '+';

    for (int index = 0; index < s.size(); index++)
    {
      char current = s[index];

      if (isdigit(current))
      {
        currentNumberStr += current;
        continue;
      }

      if (current == ' ')
      {
        continue;
      }

      if (current == '+' || current == '-')
      {
        nextOperation = current;
      }

      if (current == '(')
      {
        int endIndex = getExpressionEndIndex(s.substr(index));
        currentNumber = calculate(s.substr(index + 1, endIndex - 1));
        index += endIndex;
      }
      else
      {
        currentNumber = atoi(currentNumberStr.c_str());
      }

      if (priorOperation == '+')
      {
        answer += currentNumber;
      }

      if (priorOperation == '-')
      {
        answer -= currentNumber;
      }

      priorOperation = nextOperation;
      currentNumberStr = "";
      currentNumber = 0;
    }

    if (currentNumberStr.size() > 0)
    {
      currentNumber = atoi(currentNumberStr.c_str());
      if (priorOperation == '+')
      {
        answer += currentNumber;
      }

      if (priorOperation == '-')
      {
        answer -= currentNumber;
      }
    }

    return answer;
  }

private:
  int getExpressionEndIndex(string s)
  {
    stack<char> parens;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        parens.push('(');
      }

      if (s[i] == ')')
      {
        parens.pop();
      }

      if (parens.empty())
      {
        return i;
      }
    }

    return s.size() - 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.calculate("1 + 1");
  int result2 = solution.calculate("1+1");
  int result3 = solution.calculate("2-1 + 2");
  int result4 = solution.calculate("(1+(4+5+2)-3)+(6+8)");
  int result5 = solution.calculate("- ( 3+4)");
  int result6 = solution.calculate("- (3 + (4 + 5))");
}