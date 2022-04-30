// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// not mine
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
  {
    int res = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
    for (int l = 0; l < cols; ++l)
    {
      vector<int> sums(rows);
      for (int r = l; r < cols; ++r)
      {
        for (int i = 0; i < rows; ++i)
          sums[i] += matrix[i][r];
        set<int> s = {0};
        int run_sum = 0;
        for (int sum : sums)
        {
          run_sum += sum;
          auto it = s.lower_bound(run_sum - k);
          if (it != end(s))
            res = max(res, run_sum - *it);
          s.insert(run_sum);
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSumSubmatrix(*new vector<vector<int>>{vector<int>{1, 0, 1}, vector<int>{0, -2, 3}}, 2);
  int result2 = solution.maxSumSubmatrix(*new vector<vector<int>>{vector<int>{2, 2, -1}}, 3);
  int result3 = solution.maxSumSubmatrix(*new vector<vector<int>>{vector<int>{1, 0, 1}, vector<int>{0, -2, 3}}, 4);
  int result4 = solution.maxSumSubmatrix(*new vector<vector<int>>{vector<int>{2, 2, -1}}, 0);
  int result5 = solution.maxSumSubmatrix(*new vector<vector<int>>{vector<int>{5, -4, -3, 4}, vector<int>{-3, -4, 4, 5}, vector<int>{5, 1, 5, -4}}, 8);
}