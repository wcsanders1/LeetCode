// https://leetcode.com/problems/design-circular-queue/
#include <vector>

using namespace std;

class MyCircularQueue
{
public:
  MyCircularQueue(int k)
  {
    _capacity = k;
    _size = 0;
    _position = 0;
    _queue = vector<int>(k, -1);
  }

  bool enQueue(int value)
  {
  }

  bool deQueue()
  {
  }

  int Front()
  {
    if (_size == 0)
    {
      return -1;
    }
  }

  int Rear()
  {
    if (_size == 0)
    {
      return -1;
    }
  }

  bool isEmpty()
  {
    return _size == 0;
  }

  bool isFull()
  {
    return _size == _capacity;
  }

private:
  int _capacity;
  int _size;
  int _position;
  vector<int> _queue;
};
