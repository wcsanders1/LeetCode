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
    if (expression.empty())
    {
      return answer;
    }

    vector<int> numbers;
    vector<char> operators;

    int start = 0;
    int length = 1;
    for (int position = 0; position < expression.size(); position++)
    {
      if (!isdigit(expression[position]))
      {
        numbers.push_back(stoi(expression.substr(start, length)));
        operators.push_back(expression[position]);
        start = position + 1;
        length = 1;
      }
      else
      {
        length++;
      }
    }

    numbers.push_back(stoi(expression.substr(start, length)));

    reduce(numbers, operators, answer);

    return answer;
  }

private:
  void reduce(vector<int> numbers, vector<char> operators, vector<int> answer, int position = 0)
  {
    if (numbers.size() == 2)
    {
      answer.push_back(compute(numbers[0], numbers[1], operators[position]));
      return;
    }

    for (int outter = 0; outter < numbers.size(); outter++)
    {
      vector<int> reducedNumbers;

      for (int inner = outter + 1; inner < numbers.size(); inner++)
      {
      }
    }
  }

  int compute(int first, int second, char op)
  {
    switch (op)
    {
    case '*':
      return first * second;
    case '-':
      return first - second;
    default:
      return first + second;
    }
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.diffWaysToCompute("2*3-4*5");
}