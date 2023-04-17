// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  vector<int> findColumnWidth(vector<vector<int>> &grid)
  {
    vector<int> answer(grid[0].size(), 0);
    for (int col = 0; col < grid[0].size(); col++)
    {
      int greatest = 0;
      for (int row = 0; row < grid.size(); row++)
      {
        auto s = to_string(grid[row][col]);
        int x = s.size();
        answer[col] = max(answer[col], x);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findColumnWidth(*new vector<vector<int>>{{1}, {22}, {333}});
  auto result2 = solution.findColumnWidth(*new vector<vector<int>>{{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}});
}