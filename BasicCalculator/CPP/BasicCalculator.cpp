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
    string currentNumber = "";
    char operation = '+';

    for (int i = 0; i < s.size(); i++)
    {
      char current = s[i];

      if (isdigit(current))
      {
        currentNumber += current;
        continue;
      }

      if (current == ' ')
      {
        continue;
      }

      if (current == '(')
      {
        int expressionEndIndex = getExpressionEndIndex(s.substr(i));
        int expressionAnswer = calculate(s.substr(i + 1, expressionEndIndex - 1));

        // TODO: something
      }

      if (operation == '+')
      {
        answer += atoi(currentNumber.c_str());
      }

      if (operation == '-')
      {
        answer -= atoi(currentNumber.c_str());
      }

      operation = current;
      currentNumber = "";
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