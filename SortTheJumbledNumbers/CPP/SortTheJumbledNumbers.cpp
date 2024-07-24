// https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> mapped;
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      int m = 0;
      int multiple = 1;
      while (num >= 0)
      {
        int digit = (num % 10);
        num = (num / 10) == 0 ? -1 : num / 10;
        m += (mapping[digit]) * multiple;
        multiple *= 10;
      }
      mapped.push_back({m, i});
    }

    sort(mapped.begin(), mapped.end());
    vector<int> answer;
    for (auto &map : mapped)
    {
      answer.push_back(nums[map[1]]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sortJumbled(*new vector<int>{8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, *new vector<int>{991, 338, 38});
  auto result2 = solution.sortJumbled(*new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *new vector<int>{789, 456, 123});
  auto result3 = solution.sortJumbled(*new vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, *new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}