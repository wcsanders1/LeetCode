// https://leetcode.com/problems/maximum-number-of-points-with-cost/description/?envType=daily-question&envId=2024-08-17
// NOT MINE: https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/1344908/c-java-python-3-dp-explanation-with-pictures-o-mn-time-o-n-space/?envType=daily-question&envId=2024-08-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  long long maxPoints(vector<vector<int>> &points)
  {
    int rows = points.size();
    int cols = points[0].size();
    vector<long long> prev(cols, 0);
    for (int col = 0; col < cols; col++)
    {
      prev[col] = points[0][col];
    }

    for (int row = 1; row < rows; row++)
    {
      vector<long long> maxLeft(cols, 0);
      maxLeft[0] = prev[0];
      vector<long long> maxRight(cols, 0);
      maxRight[cols - 1] = prev[cols - 1];
      for (int left = 1, right = cols - 2; left < cols; left++, right--)
      {
        maxLeft[left] = max(prev[left], maxLeft[left - 1] - 1);
        maxRight[right] = max(prev[right], maxRight[right + 1] - 1);
      }

      vector<long long> cur(cols, 0);
      for (int col = 0; col < cols; col++)
      {
        long long num = points[row][col];
        cur[col] = num + max(maxLeft[col], maxRight[col]);
      }

      prev = cur;
    }

    long long answer = 0;
    for (int col = 0; col < cols; col++)
    {
      answer = max(answer, prev[col]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxPoints(*new vector<vector<int>>{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}});
  auto result2 = solution.maxPoints(*new vector<vector<int>>{{1, 5}, {2, 3}, {4, 2}});
}