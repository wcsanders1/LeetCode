// https://leetcode.com/problems/01-matrix/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    queue<pair<int, int>> q;

    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        if (mat[row][col] == 0)
        {
          visited[row][col] = true;
          q.push({row, col});
        }
      }
    }

    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int distance = 1;
    while (!q.empty())
    {
      int count = q.size();
      while (count-- > 0)
      {
        auto next = q.front();
        q.pop();

        for (auto &d : directions)
        {
          int nRow = next.first + d.first;
          int nCol = next.second + d.second;
          if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && !visited[nRow][nCol])
          {
            answer[nRow][nCol] = distance;
            visited[nRow][nCol] = true;
            q.push({nRow, nCol});
          }
        }
      }
      distance++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.updateMatrix(*new vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}});
  auto result2 = solution.updateMatrix(*new vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}});
  auto result3 = solution.updateMatrix(*new vector<vector<int>>{{1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}});
}