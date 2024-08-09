// https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
  {
    vector<vector<int>> answer{{rStart, cStart}};
    int distance = 1;
    int gridSize = rows * cols;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int currentDirection = 0;
    bool incrementDistance = false;
    int curRow = rStart;
    int curCol = cStart;

    while (answer.size() < gridSize)
    {
      for (int i = 0; i < distance; i++)
      {
        curRow += directions[currentDirection][0];
        curCol += directions[currentDirection][1];
        if (curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols)
        {
          answer.push_back({curRow, curCol});
        }
      }

      if (incrementDistance)
      {
        distance++;
        incrementDistance = false;
      }
      else
      {
        incrementDistance = true;
      }

      currentDirection = currentDirection + 1 == 4 ? 0 : currentDirection + 1;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.spiralMatrixIII(1, 4, 0, 0);
  auto result2 = solution.spiralMatrixIII(5, 6, 1, 4);
}