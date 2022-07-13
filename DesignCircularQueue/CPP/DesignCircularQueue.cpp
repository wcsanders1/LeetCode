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
    _rearPosition = -1;
    _frontPosition = 0;
    _queue = vector<int>(k, -1);
  }

  bool enQueue(int value)
  {
    if (_size == _capacity)
    {
      return false;
    }

    if (_rearPosition == _capacity - 1)
    {
      _rearPosition = 0;
    }
    else
    {
      _rearPosition++;
    }

    _size++;
    _queue[_rearPosition] = value;

    return true;
  }

  bool deQueue()
  {
    if (_size == 0)
    {
      return false;
    }

    _size--;

    if (_frontPosition == _capacity - 1)
    {
      _frontPosition = 0;
    }
    else
    {
      _frontPosition++;
    }

    return true;
  }

  int Front()
  {
    if (_size == 0)
    {
      return -1;
    }

    return _queue[_frontPosition];
  }

  int Rear()
  {
    if (_size == 0)
    {
      return -1;
    }

    return _queue[_rearPosition];
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
  int _rearPosition;
  int _frontPosition;
  vector<int> _queue;
};

int main()
{
  MyCircularQueue circleQueue(3);

  bool result1 = circleQueue.enQueue(1);  // true
  bool result2 = circleQueue.enQueue(2);  // true
  bool result3 = circleQueue.enQueue(3);  // true
  bool result4 = circleQueue.enQueue(4);  // false
  int result5 = circleQueue.Rear();       // 3
  bool result6 = circleQueue.isFull();    // true
  bool result7 = circleQueue.deQueue();   // true
  bool result8 = circleQueue.enQueue(4);  // true
  int result9 = circleQueue.Rear();       // 4
  int result10 = circleQueue.Front();     // 2
  bool result11 = circleQueue.enQueue(5); // false
  bool result12 = circleQueue.deQueue();  // true
  bool result13 = circleQueue.enQueue(5); // true
  int result14 = circleQueue.Front();     // 3
  int result15 = circleQueue.Rear();      // 5
}