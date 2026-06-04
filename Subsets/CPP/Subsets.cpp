// https://leetcode.com/problems/subsets/description/
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
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> answer;
    answer.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
      vector<vector<int>> temp;
      for (int j = 0; j < answer.size(); j++)
      {
        vector<int> next(answer[j]);
        next.push_back(nums[i]);
        temp.push_back(next);
      }

      for (auto &t : temp)
      {
        answer.push_back(t);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.subsets(*new vector<int>{1, 2, 3});
  auto result2 = solution.subsets(*new vector<int>{0});
}