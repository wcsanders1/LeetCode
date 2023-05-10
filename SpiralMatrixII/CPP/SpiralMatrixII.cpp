// https://leetcode.com/problems/spiral-matrix-ii/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    int size = n * n;
    queue<vector<int>> directions;
    directions.push({0, 1});
    directions.push({1, 0});
    directions.push({0, -1});
    directions.push({-1, 0});

    vector<vector<int>> answer(n, vector<int>(n, 0));

    int row = 0;
    int col = 0;
    for (int i = 1; i <= size; i++)
    {
      answer[row][col] = i;
      int trow = row + directions.front()[0];
      int tcol = col + directions.front()[1];
      if (trow >= n || tcol >= n || trow < 0 || tcol < 0 || answer[trow][tcol] != 0)
      {
        auto temp = directions.front();
        directions.pop();
        directions.push(temp);
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

  auto result1 = solution.generateMatrix(3);
  auto result2 = solution.generateMatrix(1);
}