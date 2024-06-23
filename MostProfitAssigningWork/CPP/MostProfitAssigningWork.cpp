// https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
  {
    int n = difficulty.size();
    vector<vector<int>> m;
    for (int i = 0; i < n; i++)
    {
      m.push_back({difficulty[i], profit[i]});
    }

    sort(m.begin(), m.end());
    sort(worker.begin(), worker.end());

    int most = m[0][1];
    for (auto &_m : m)
    {
      most = max(most, _m[1]);
      _m[1] = most;
    }

    int answer = 0;

    int index = 0;
    for (int w : worker)
    {
      while (index < n - 1 && w >= m[index + 1][0])
      {
        index++;
      }

      if (w >= m[index][0])
      {
        answer += m[index][1];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxProfitAssignment(*new vector<int>{2, 4, 6, 8, 10}, *new vector<int>{10, 20, 30, 40, 50}, *new vector<int>{4, 5, 6, 7});
  int result2 = solution.maxProfitAssignment(*new vector<int>{85, 47, 57}, *new vector<int>{24, 66, 99}, *new vector<int>{40, 25, 25});
}