// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxMoves(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> count(rows, vector<int>(cols, 0));

    vector<int> directions{-1, 0, 1};
    for (int col = cols - 2; col >= 0; col--)
    {
      for (int row = 0; row < rows; row++)
      {
        int greatest = 0;
        for (int &dir : directions)
        {
          int next = row + dir;
          if (next >= 0 && next < rows && grid[next][col + 1] > grid[row][col])
          {
            greatest = max(greatest, 1 + count[next][col + 1]);
          }
        }
        count[row][col] = greatest;
      }
    }

    int answer = 0;
    for (int row = 0; row < rows; row++)
    {
      answer = max(answer, count[row][0]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxMoves(*new vector<vector<int>>{{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}});
  int result2 = solution.maxMoves(*new vector<vector<int>>{{3, 2, 4}, {2, 1, 9}, {1, 1, 7}});
}