// https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31
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
    stack<vector<int>> s;
    s.push({temperatures[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
      int temp = temperatures[i];
      if (temp < s.top()[0])
      {
        answer[i] = 1;
        s.push({temp, i});
      }
      else
      {
        while (!s.empty() && s.top()[0] <= temp)
        {
          s.pop();
        }

        if (s.empty())
        {
          answer[i] = 0;
          s.push({temp, i});
        }
        else
        {
          answer[i] = s.top()[1] - i;
          s.push({temp, i});
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.dailyTemperatures(*new vector<int>{73, 74, 75, 71, 69, 72, 76, 73});
  auto result2 = solution.dailyTemperatures(*new vector<int>{30, 40, 50, 60});
  auto result3 = solution.dailyTemperatures(*new vector<int>{30, 60, 90});
  auto result4 = solution.dailyTemperatures(*new vector<int>{89, 62, 70, 58, 47, 47, 46, 76, 100, 70});
}