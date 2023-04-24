// https://leetcode.com/problems/last-stone-weight/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    priority_queue<int> pq;
    for (int &s : stones)
    {
      pq.push(s);
    }

    while (pq.size() > 1)
    {
      int x = pq.top();
      pq.pop();

      int y = pq.top();
      pq.pop();

      int result = x - y;

      if (result > 0)
      {
        pq.push(result);
      }
    }

    return pq.empty() ? 0 : pq.top();
  }
};

int main()
{
  Solution solution;

  int result1 = solution.lastStoneWeight(*new vector<int>{2, 7, 4, 1, 8, 1});
  int result2 = solution.lastStoneWeight(*new vector<int>{1});
}