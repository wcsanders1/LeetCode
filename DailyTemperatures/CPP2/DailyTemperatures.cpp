// https://leetcode.com/problems/daily-temperatures/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--)
    {
      while (!s.empty() && s.top().first <= temperatures[i])
      {
        s.pop();
      }

      if (!s.empty())
      {
        answer[i] = s.top().second - i;
      }

      s.push({temperatures[i], i});
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.dailyTemperatures(*new vector<int>{73, 74, 75, 71, 69, 72, 76, 73});
  auto result2 = solution.dailyTemperatures(*new vector<int>{
      30,
      40,
      50,
      60,
  });
  auto result3 = solution.dailyTemperatures(*new vector<int>{30, 60, 90});
}