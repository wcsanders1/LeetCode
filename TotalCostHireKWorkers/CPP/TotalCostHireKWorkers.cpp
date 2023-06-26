// https://leetcode.com/problems/total-cost-to-hire-k-workers/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long totalCost(vector<int> &costs, int k, int candidates)
  {
    int n = costs.size();
    priority_queue<int, vector<int>, greater<int>> first;
    priority_queue<int, vector<int>, greater<int>> second;

    int i = 0, j = n - 1;
    for (; i < candidates; i++, j--)
    {
      if (i > j)
      {
        break;
      }
      if (i == j)
      {
        first.push(costs[i++]);
        break;
      }
      first.push(costs[i]);
      second.push(costs[j]);
    }

    long long answer = 0;

    while (k-- > 0)
    {
      if (first.empty())
      {
        answer += second.top();
        second.pop();
      }
      else if (second.empty())
      {
        answer += first.top();
        first.pop();
      }
      else if (first.top() <= second.top())
      {
        answer += first.top();
        first.pop();
        if (i <= j)
        {
          first.push(costs[i++]);
        }
      }
      else
      {
        answer += second.top();
        second.pop();
        if (i <= j)
        {
          second.push(costs[j--]);
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.totalCost(*new vector<int>{17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4);
  auto result2 = solution.totalCost(*new vector<int>{1, 2, 4, 1}, 3, 3);
  auto result3 = solution.totalCost(*new vector<int>{18, 64, 12, 21, 21, 78, 36, 58, 88, 58, 99, 26, 92, 91, 53, 10, 24, 25, 20, 92, 73, 63, 51, 65, 87, 6, 17, 32, 14, 42, 46, 65, 43, 9, 75}, 13, 23);
  auto result4 = solution.totalCost(*new vector<int>{57, 33, 26, 76, 14, 67, 24, 90, 72, 37, 30}, 11, 2);
  auto result5 = solution.totalCost(*new vector<int>{60, 87, 94, 42, 12, 60}, 5, 4);
}