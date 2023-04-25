// https://leetcode.com/problems/smallest-number-in-infinite-set/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet
{
public:
  SmallestInfiniteSet()
  {
    current = 1;
  }

  int popSmallest()
  {
    if (minq.empty() || current < minq.top())
    {
      return current++;
    }

    int t = minq.top();
    minq.pop();
    s.erase(t);
    return t;
  }

  void addBack(int num)
  {
    if (num < current && s.count(num) == 0)
    {
      minq.push(num);
      s.insert(num);
    }
  }

private:
  int current;
  priority_queue<int, vector<int>, greater<int>> minq;
  unordered_set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main()
{
  SmallestInfiniteSet *sis = new SmallestInfiniteSet();

  sis->addBack(2);
  int result1 = sis->popSmallest();
  int result2 = sis->popSmallest();
  int result3 = sis->popSmallest();
  sis->addBack(1);
  int result4 = sis->popSmallest();
  int result5 = sis->popSmallest();
  int result6 = sis->popSmallest();
}