// https://leetcode.com/problems/permutations/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> answer;
    answer.push_back({nums[0]});

    for (int i = 1; i < n; i++)
    {
      vector<vector<int>> next;
      for (auto &a : answer)
      {
        for (int j = 0; j <= a.size(); j++)
        {
          auto nxt = a;
          nxt.insert(nxt.begin() + j, nums[i]);
          next.push_back(nxt);
        }
      }

      answer = next;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.permute(*new vector<int>{1, 2, 3});
  auto result2 = solution.permute(*new vector<int>{0, 1});
  auto result3 = solution.permute(*new vector<int>{1});
}