// https://leetcode.com/problems/combination-sum/description/
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
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> current;
    getCombinations(candidates, target, answer, current, 0);
    return answer;
  }

private:
  void getCombinations(vector<int> &candidates, int target, vector<vector<int>> &combinations, vector<int> &current, int start)
  {
    for (int i = start; i < candidates.size(); i++)
    {
      int n = candidates[i];
      if (n > target)
      {
        return;
      }

      vector<int> next(current);
      next.push_back(n);
      if (n == target)
      {
        combinations.push_back(next);
        return;
      }
      else
      {
        getCombinations(candidates, target - n, combinations, next, i);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.combinationSum(*new vector<int>{2, 3, 6, 7}, 7);
  auto result2 = solution.combinationSum(*new vector<int>{2, 3, 5}, 8);
  auto result3 = solution.combinationSum(*new vector<int>{2}, 1);
}