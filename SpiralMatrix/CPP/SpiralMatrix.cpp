// https://leetcode.com/problems/spiral-matrix/description/
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();

    queue<vector<int>> directions;
    directions.push({0, 1});
    directions.push({1, 0});
    directions.push({0, -1});
    directions.push({-1, 0});

    vector<int> answer;

    int row = 0;
    int col = 0;

    while (answer.size() < rows * cols)
    {
      answer.push_back(matrix[row][col]);
      matrix[row][col] = INT32_MAX;
      int trow = row + directions.front()[0];
      int tcol = col + directions.front()[1];

      if (trow >= rows || tcol >= cols || trow < 0 || tcol < 0 || matrix[trow][tcol] == INT32_MAX)
      {
        auto t = directions.front();
        directions.pop();
        directions.push(t);
        trow = row + directions.front()[0];
        tcol = col + directions.front()[1];
      }

      row = trow;
      col = tcol;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.spiralOrder(*new vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  auto result2 = solution.spiralOrder(*new vector<vector<int>>{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
}