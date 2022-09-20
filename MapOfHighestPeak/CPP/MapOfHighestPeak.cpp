// https://leetcode.com/problems/map-of-highest-peak/
// NOT MINE: https://leetcode.com/problems/map-of-highest-peak/discuss/1076933/C%2B%2B-with-picture-(of-Mars)
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
  {
    vector<pair<int, int>> q;
    int rowSize = isWater.size();
    int colSize = isWater[0].size();

    for (int row = 0; row < rowSize; row++)
    {
      for (int col = 0; col < colSize; col++)
      {
        if (isWater[row][col] == 1)
        {
          isWater[row][col] = 0;
          q.push_back({row, col});
        }
        else
        {
          isWater[row][col] = -1;
        }
      }
    }

    int max = 1;
    while (!q.empty())
    {
      vector<pair<int, int>> q1;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto cell = q[i];
        int row = cell.first;
        int col = cell.second;

        for (auto d : directions)
        {
          int r = row + d[0];
          int c = col + d[1];

          if (r >= 0 && r < rowSize && c >= 0 && c < colSize && isWater[r][c] == -1)
          {
            isWater[r][c] = max;
            q1.push_back({r, c});
          }
        }
      }
      swap(q, q1);
      max++;
    }

    return isWater;
  }

private:
  const vector<vector<int>> directions = vector<vector<int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};

int main()
{
  Solution solution;

  auto result1 = solution.highestPeak(*new vector<vector<int>>{{0, 1}, {0, 0}});
  auto result2 = solution.highestPeak(*new vector<vector<int>>{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}});
}