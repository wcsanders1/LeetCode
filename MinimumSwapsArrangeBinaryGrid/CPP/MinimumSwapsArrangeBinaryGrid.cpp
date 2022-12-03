// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// NOT MINE: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/discuss/768020/C%2B%2B-easy-solution-greedy-%2B-prove-%2B-example
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int minSwaps(vector<vector<int>> &grid)
  {
    int size = grid.size();
    vector<int> tailingZeros(size, 0);
    for (int i = 0; i < size; i++)
    {
      for (int j = size - 1; j >= 0; j--)
      {
        if (grid[i][j] != 0)
        {
          break;
        }
        tailingZeros[i]++;
      }
    }

    int answer = 0;
    for (int i = 0; i < size; i++)
    {
      int k = i;
      int required = size - 1 - i;
      while (k < size && tailingZeros[k] < required)
      {
        k++;
      }

      if (k >= size)
      {
        return -1;
      }

      answer += k - i;

      while (k > i)
      {
        tailingZeros[k] = tailingZeros[k - 1];
        k--;
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
      {1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1}}); // 5
}