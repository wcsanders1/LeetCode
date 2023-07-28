// https://leetcode.com/problems/knight-probability-in-chessboard/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  double knightProbability(int n, int k, int row, int column)
  {
    if (k == 0)
    {
      return 1;
    }

    vector<vector<double>> cache(n, vector<double>(n, -1));
    auto onBoard = getTimesOnBoard(k, row, column, n, cache);

    return onBoard / pow(8.0, k);
  }

private:
  vector<vector<int>> directions =
      {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  double getTimesOnBoard(int k, int row, int column, int n, vector<vector<double>> &cache)
  {
    if (cache[row][column] != -1)
    {
      return cache[row][column];
    }

    if (k == 0)
    {
      cache[row][column] = 1;
      return 1;
    }

    double onBoard = 0;
    for (auto &d : directions)
    {
      int newRow = row + d[0];
      int newColumn = column + d[1];
      if (!isOnBoard(newRow, newColumn, n))
      {
        continue;
      }

      auto t = getTimesOnBoard(k - 1, row + d[0], column + d[1], n, cache);
      onBoard += t;
    }

    cache[row][column] = onBoard;
    return onBoard;
  }

  bool isOnBoard(int row, int column, int n)
  {
    return row >= 0 && column >= 0 && row < n && column < n;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.knightProbability(3, 2, 0, 0);
  auto result2 = solution.knightProbability(1, 0, 0, 0);
  auto result3 = solution.knightProbability(8, 30, 6, 4);
}