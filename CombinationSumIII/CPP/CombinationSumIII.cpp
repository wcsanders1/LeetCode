// https://leetcode.com/problems/combination-sum-iii/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> sums;
    vector<int> current;
    getSums(k, n, current, sums, 1);
    return sums;
  }

private:
  void getSums(int k, int n, vector<int> &current, vector<vector<int>> &sums, int start)
  {
    if (current.size() >= k || start >= 10)
    {
      return;
    }

    for (int i = start; i < 10; i++)
    {
      if (i > n)
      {
        return;
      }

      auto c = vector<int>(current);
      c.push_back(i);

      if (i == n)
      {
        if (c.size() == k)
        {
          sums.push_back(c);
        }
        return;
      }

      getSums(k, n - i, c, sums, i + 1);
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.combinationSum3(3, 7);
  auto result2 = solution.combinationSum3(3, 9);
  auto result3 = solution.combinationSum3(4, 1);
}