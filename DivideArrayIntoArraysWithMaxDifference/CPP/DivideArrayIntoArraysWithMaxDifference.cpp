// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<int>> divideArray(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;

    for (int i = 0; i < nums.size(); i += 3)
    {
      if (nums[i + 2] - nums[i] > k)
      {
        return vector<vector<int>>();
      }

      answer.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.divideArray(*new vector<int>{1, 3, 4, 8, 7, 9, 3, 5, 1}, 2);
  auto result2 = solution.divideArray(*new vector<int>{1, 3, 3, 2, 7, 3}, 3);
}