// https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    long long sum = 0;
    int negatives = 0;
    int smallest = INT32_MAX;

    for (int r = 0; r < matrix.size(); r++)
    {
      for (int c = 0; c < matrix[0].size(); c++)
      {
        int n = matrix[r][c];
        sum += (long long)abs(n);
        smallest = min(smallest, abs(n));

        if (n < 0)
        {
          negatives++;
        }
      }
    }

    if (negatives % 2 == 1)
    {
      sum -= (smallest * 2);
    }

    return sum;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.maxMatrixSum(*new vector<vector<int>>{{1, -1}, {-1, 1}});
  long long result2 = solution.maxMatrixSum(*new vector<vector<int>>{{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}});
}