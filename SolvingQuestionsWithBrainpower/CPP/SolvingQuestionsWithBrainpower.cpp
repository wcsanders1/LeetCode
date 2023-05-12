// https://leetcode.com/problems/solving-questions-with-brainpower/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  long long mostPoints(vector<vector<int>> &questions)
  {
    int n = questions.size();
    vector<long long> highest(n, 0);
    highest[n - 1] = questions[n - 1][0];

    for (int i = n - 2; i >= 0; i--)
    {
      if (questions[i][1] + i + 1 >= n)
      {
        highest[i] = max((long long)questions[i][0], highest[i + 1]);
      }
      else
      {
        highest[i] = max(questions[i][0] + highest[i + questions[i][1] + 1], highest[i + 1]);
      }
    }

    return highest[0];
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mostPoints(*new vector<vector<int>>{{3, 2}, {4, 3}, {4, 4}, {2, 5}});
  auto result2 = solution.mostPoints(*new vector<vector<int>>{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
}