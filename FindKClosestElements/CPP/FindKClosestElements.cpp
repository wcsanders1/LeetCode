// https://leetcode.com/problems/find-k-closest-elements/
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    if (arr.size() == k)
    {
      return arr;
    }

    int start = 0;
    int cur = abs(arr[start] - x);

    while (start < arr.size() - 1)
    {
      int t = abs(arr[start + 1] - x);
      if (t > cur || (t == cur && arr[start] < arr[start + 1]))
      {
        break;
      }
      cur = t;
      start++;
    }

    int end = start + 1;
    stack<int> b;
    b.push(arr[start--]);
    queue<int> e;

    while (end - start - 1 < k)
    {
      if (end >= arr.size())
      {
        b.push(arr[start--]);
      }
      else if (start < 0)
      {
        e.push(arr[end++]);
      }
      else
      {
        if (abs(arr[start] - x) <= abs(arr[end] - x))
        {
          b.push(arr[start--]);
        }
        else
        {
          e.push(arr[end++]);
        }
      }
    }

    vector<int> answer;
    while (!b.empty())
    {
      answer.push_back(b.top());
      b.pop();
    }

    while (!e.empty())
    {
      answer.push_back(e.front());
      e.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findClosestElements(*new vector<int>{1, 2, 3, 4, 5}, 4, 3);
  auto result2 = solution.findClosestElements(*new vector<int>{1, 2, 3, 4, 5}, 4, -1);
  auto result3 = solution.findClosestElements(*new vector<int>{1, 1, 1, 10, 10}, 1, 9);
  auto result4 = solution.findClosestElements(*new vector<int>{1, 1, 2, 2, 2, 2, 2, 3, 3}, 3, 3);
}