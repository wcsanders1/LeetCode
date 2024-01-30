// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    unordered_set<string> ops = {"+", "-", "*", "/"};
    stack<string> s;
    for (string &t : tokens)
    {
      if (ops.count(t) == 0)
      {
        s.push(t);
        continue;
      }

      int num2 = stoi(s.top());
      s.pop();
      int num1 = stoi(s.top());
      s.pop();

      if (t == "+")
      {
        s.push(to_string(num1 + num2));
      }
      else if (t == "-")
      {
        s.push(to_string(num1 - num2));
      }
      else if (t == "*")
      {
        s.push(to_string(num1 * num2));
      }
      else
      {
        s.push(to_string(num1 / num2));
      }
    }

    return stoi(s.top());
  }
};

int main()
{
  Solution solution;

  int result1 = solution.evalRPN(*new vector<string>{"2", "1", "+", "3", "*"});
  int result2 = solution.evalRPN(*new vector<string>{"4", "13", "5", "/", "+"});
  int result3 = solution.evalRPN(*new vector<string>{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"});
}