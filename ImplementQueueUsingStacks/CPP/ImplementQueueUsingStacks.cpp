// https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class MyQueue
{
public:
  MyQueue()
  {
  }

  void push(int x)
  {
    s1.push(x);
  }

  int pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int i = s2.top();
    s2.pop();
    return i;
  }

  int peek()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty()
  {
    return s1.empty() && s2.empty();
  }

private:
  stack<int> s1;
  stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
  auto q = new MyQueue();
  q->push(1);
  q->push(2);
  int result1 = q->peek();
  int result2 = q->pop();
  bool result3 = q->empty();
}