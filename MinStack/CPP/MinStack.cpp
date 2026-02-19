// https://leetcode.com/problems/min-stack/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class MinStack
{
public:
  MinStack()
  {
  }

  void push(int val)
  {
    int mn = _s.empty() ? val : min(_s.top().second, val);
    _s.push({val, mn});
  }

  void pop()
  {
    if (!_s.empty())
    {
      _s.pop();
    }
  }

  int top()
  {
    return _s.empty() ? 0 : _s.top().first;
  }

  int getMin()
  {
    return _s.empty() ? 0 : _s.top().second;
  }

private:
  stack<pair<int, int>> _s;
};

int main()
{
  MinStack *minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  int result1 = minStack->getMin();
  minStack->pop();
  int result2 = minStack->top();
  int result3 = minStack->getMin();
}