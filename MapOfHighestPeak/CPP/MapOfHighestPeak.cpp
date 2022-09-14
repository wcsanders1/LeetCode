// https://leetcode.com/problems/map-of-highest-peak/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
  {
    vector<vector<int>> answer = vector<vector<int>>(isWater.size(), vector<int>(isWater[0].size(), INT32_MAX));

    for (int row = 0; row < isWater.size(); row++)
    {
      for (int col = 0; col < isWater[row].size(); col++)
      {
        if (isWater[row][col] == 1)
        {
          doCorrection(answer, row, col);
        }
      }
    }

    return answer;
  }

private:
  const vector<vector<int>> directions = vector<vector<int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void doCorrection(vector<vector<int>> &matrix, int row, int col)
  {
    matrix[row][col] = 0;
    int max = 1;

    queue<vector<int>> q;
    fillQueue(q, matrix, row, col, max);

    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        vector<int> p = q.front();
        q.pop();

        int r = p[0];
        int c = p[1];
        matrix[r][c] = max;
        fillQueue(q, matrix, r, c, max + 1);
      }

      max++;
    }
  }

  void fillQueue(queue<vector<int>> &q, vector<vector<int>> &matrix, int row, int col, int max)
  {
    for (auto d : directions)
    {
      int r = row + d[0];
      int c = col + d[1];

      if (r < matrix.size() && r >= 0 && c < matrix[0].size() && c >= 0)
      {
        if (matrix[r][c] > max)
        {
          q.push({r, c});
        }
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.highestPeak(*new vector<vector<int>>{{0, 1}, {0, 0}});
  auto result2 = solution.highestPeak(*new vector<vector<int>>{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}});
}