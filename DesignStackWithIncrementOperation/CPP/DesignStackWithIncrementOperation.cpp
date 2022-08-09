// https://leetcode.com/problems/design-a-stack-with-increment-operation/
#include <vector>

using namespace std;

class CustomStack
{
public:
  CustomStack(int maxSize)
  {
    stack = vector<int>(maxSize, 0);
    position = -1;
    capacity = maxSize - 1;
  }

  void push(int x)
  {
    if (position >= capacity)
    {
      return;
    }

    stack[++position] = x;
  }

  int pop()
  {
    if (position < 0)
    {
      return -1;
    }

    return stack[position--];
  }

  void increment(int k, int val)
  {
    for (int i = 0; i < k; i++)
    {
      if (i > capacity)
      {
        return;
      }

      stack[i] += val;
    }
  }

private:
  vector<int> stack;
  int position;
  int capacity;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{
  CustomStack *customStack = new CustomStack(3);
  customStack->push(1);
  customStack->push(2);
  int a = customStack->pop();
  customStack->push(2);
  customStack->push(3);
  customStack->push(4);
  customStack->increment(5, 100);
  customStack->increment(2, 100);
  int b = customStack->pop();
  int c = customStack->pop();
  int d = customStack->pop();
  int e = customStack->pop();
}