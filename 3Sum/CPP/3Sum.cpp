// https://leetcode.com/problems/3sum/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
      m[nums[i]].push_back(i);
    }

    unordered_set<int> s;
    for (int start = 0; start < n; start++)
    {
      if (s.find(nums[start]) != s.end())
      {
        continue;
      }
      s.insert(nums[start]);
      int end = n - 1;
      unordered_set<int> ss;
      while (end > start)
      {
        if (ss.find(nums[end]) != ss.end())
        {
          end--;
          continue;
        }
        ss.insert(nums[end]);
        int need = -(nums[start] + nums[end]);
        if (m.find(need) != m.end())
        {
          for (int &i : m[need])
          {
            if (i > start && i < end)
            {
              answer.push_back({nums[start], nums[i], nums[end]});
              break;
            }
          }
        }
        end--;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.threeSum(*new vector<int>{-1, 0, 1, 2, -1, -4});
  auto result2 = solution.threeSum(*new vector<int>{0, 1, 1});
  auto result3 = solution.threeSum(*new vector<int>{0, 0, 0});
  auto result4 = solution.threeSum(*new vector<int>{-100, -70, -60, 110, 120, 130, 160});
  auto result5 = solution.threeSum(*new vector<int>{1, 1, -2});
  auto result6 = solution.threeSum(*new vector<int>{0, 0, 0});
}