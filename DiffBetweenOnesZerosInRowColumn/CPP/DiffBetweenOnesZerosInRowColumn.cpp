// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> rowOnes(rows, 0);
    vector<int> colOnes(cols, 0);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        rowOnes[r] += grid[r][c];
      }
    }

    for (int c = 0; c < cols; c++)
    {
      for (int r = 0; r < rows; r++)
      {
        colOnes[c] += grid[r][c];
      }
    }

    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        answer[r][c] = rowOnes[r] + colOnes[c] - (rows - rowOnes[r]) - (cols - colOnes[c]);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.onesMinusZeros(*new vector<vector<int>>{{0, 1, 1}, {1, 0, 1}, {0, 0, 1}});
  auto result2 = solution.onesMinusZeros(*new vector<vector<int>>{{1, 1, 1}, {1, 1, 1}});
}