#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> path;

    getCombinations(candidates, 0, target, path, answer);

    return answer;
  }

private:
  void getCombinations(vector<int> &candidates, int index, int target, vector<int> &path, vector<vector<int>> &answer)
  {
    if (target == 0)
    {
      answer.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
      if (i > index && candidates[i] == candidates[i - 1])
      {
        continue;
      }

      if (candidates[i] > target)
      {
        return;
      }

      path.push_back(candidates[i]);
      getCombinations(candidates, i + 1, target - candidates[i], path, answer);
      path.pop_back();
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.combinationSum2(*new vector<int>{10, 1, 2, 7, 6, 1, 5}, 8);
  auto result2 = solution.combinationSum2(*new vector<int>{2, 5, 2, 1, 2}, 5);
}