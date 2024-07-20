// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
  {
    int rows = rowSum.size();
    int cols = colSum.size();
    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        int amount = min(rowSum[row], colSum[col]);
        answer[row][col] = amount;
        rowSum[row] -= amount;
        colSum[col] -= amount;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.restoreMatrix(*new vector<int>{3, 8}, *new vector<int>{4, 7});
  auto result2 = solution.restoreMatrix(*new vector<int>{5, 7, 10}, *new vector<int>{8, 6, 8});
}