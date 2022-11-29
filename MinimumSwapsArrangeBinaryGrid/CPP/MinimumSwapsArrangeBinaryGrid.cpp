// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int minSwaps(vector<vector<int>> &grid)
  {
    int size = grid.size();
    for (int row = 0; row < size; row++)
    {
      grid[row].push_back(0);
    }

    int answer = 0;
    for (int col = size - 1; col >= 0; col--)
    {
      int maxOnes = size - col;
      int onesCount = 0;
      stack<int> swappableRows;
      for (int row = size - 1; row >= 0; row--)
      {
        onesCount += grid[row][col];
        if (onesCount > maxOnes)
        {
          return -1;
        }

        if (grid[row][col] == 0 && grid[row][size] == 0 && row >= col)
        {
          swappableRows.push(row);
        }

        if (grid[row][col] == 1)
        {
          grid[row][size] = 1;
          if (row < col)
          {
            if (!swappableRows.empty())
            {
              int swapIndex = swappableRows.top();
              swappableRows.pop();

              for (int t1 = row, t2 = row + 1; t2 <= swapIndex; t1++, t2++)
              {
                vector<int> temp = grid[t1];
                grid[t1] = grid[t2];
                grid[t2] = temp;
                answer++;
              }
            }
            else
            {
              return -1;
            }
          }
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSwaps(*new vector<vector<int>>{{0, 0, 1}, {1, 1, 0}, {1, 0, 0}});                        // 3
  int result2 = solution.minSwaps(*new vector<vector<int>>{{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}}); // -1
  int result3 = solution.minSwaps(*new vector<vector<int>>{{1, 0, 0}, {1, 1, 0}, {1, 1, 1}});                        // 0
  int result4 = solution.minSwaps(*new vector<vector<int>>{{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}}); // 2
  int result5 = solution.minSwaps(*new vector<vector<int>>{
      {
          1,
          0,
          0,
          0,
          0,
      },
      {0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1}}); // 5
}