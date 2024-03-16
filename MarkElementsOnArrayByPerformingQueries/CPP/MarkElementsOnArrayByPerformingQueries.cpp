// https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Compare
{
public:
  bool operator()(vector<int> &v1, vector<int> &v2)
  {
    if (v1[0] == v2[0])
    {
      return v1[1] > v2[1];
    }

    return v1[0] > v2[0];
  }
};

class Solution
{
public:
  vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
  {
    int m = queries.size();
    int n = nums.size();
    vector<long long> answer(m, 0);
    vector<bool> marked(n, false);
    vector<vector<int>> values_indeces(n, vector<int>(2, 0));
    priority_queue<vector<int>, vector<vector<int>>, Compare> q;

    long long total = 0;
    for (int i = 0; i < n; i++)
    {
      total += nums[i];
      q.push({nums[i], i});
    }

    for (int i = 0; i < m; i++)
    {
      auto query = queries[i];
      if (!marked[query[0]])
      {
        marked[query[0]] = true;
        total -= nums[query[0]];
      }

      while (query[1]-- > 0)
      {
        while (!q.empty() && marked[q.top()[1]])
        {
          q.pop();
        }

        if (!q.empty())
        {
          auto next = q.top();
          int value = next[0];
          int index = next[1];
          q.pop();

          marked[index] = true;
          total -= value;
        }
      }

      answer[i] = total;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.unmarkedSumArray(*new vector<int>{1, 2, 2, 1, 2, 3, 1}, *new vector<vector<int>>{{1, 2}, {3, 3}, {4, 2}});
  auto result2 = solution.unmarkedSumArray(*new vector<int>{1, 4, 2, 3}, *new vector<vector<int>>{{0, 1}});
  auto result3 = solution.unmarkedSumArray(*new vector<int>{11, 15, 3}, *new vector<vector<int>>{{1, 2}, {2, 1}, {2, 0}});
}