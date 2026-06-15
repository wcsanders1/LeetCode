// https://leetcode.com/problems/find-median-from-data-stream/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class MedianFinder
{
public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (mx.size() == 0)
    {
      mx.push(num);
      return;
    }

    if (mn.size() == 0)
    {
      if (num > mx.top())
      {
        mn.push(mx.top());
        mx.pop();
        mx.push(num);
      }
      else
      {
        mn.push(num);
      }

      return;
    }

    if (num <= mn.top())
    {
      mn.push(num);
    }
    else
    {
      mx.push(num);
    }

    if (mn.size() > mx.size() + 1)
    {
      mx.push(mn.top());
      mn.pop();
    }
    else if (mx.size() > mn.size() + 1)
    {
      mn.push(mx.top());
      mx.pop();
    }
  }

  double findMedian()
  {
    if (mn.size() == mx.size())
    {
      return (mn.top() + mx.top()) / 2;
    }
    else if (mn.size() > mx.size())
    {
      return mn.top();
    }
    return mx.top();
  }

private:
  priority_queue<double, vector<double>, greater<double>> mx;
  priority_queue<double> mn;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
  auto finder1 = new MedianFinder();

  finder1->addNum(1);
  double result1 = finder1->findMedian();
  finder1->addNum(2);
  double result2 = finder1->findMedian();
  finder1->addNum(3);
  double result3 = finder1->findMedian();
  finder1->addNum(4);
  double result4 = finder1->findMedian();

  auto finder2 = new MedianFinder();

  finder2->addNum(6);
  double result5 = finder2->findMedian();
  finder2->addNum(10);
  double result6 = finder2->findMedian();
  finder2->addNum(2);
  double result7 = finder2->findMedian();
  finder2->addNum(6);
  double result8 = finder2->findMedian();
  finder2->addNum(5);
  double result9 = finder2->findMedian();
  finder2->addNum(0);
  double result10 = finder2->findMedian();
  finder2->addNum(6);
  double result11 = finder2->findMedian();
  finder2->addNum(3);
  double result12 = finder2->findMedian();
  finder2->addNum(1);
  double result13 = finder2->findMedian();
  finder2->addNum(0);
  double result14 = finder2->findMedian();
  finder2->addNum(0);
  double result15 = finder2->findMedian();
}