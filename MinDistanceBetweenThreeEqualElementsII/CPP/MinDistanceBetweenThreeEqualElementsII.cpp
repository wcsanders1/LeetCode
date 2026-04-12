// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-10
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
  int minimumDistance(vector<int> &nums)
  {
    unordered_map<int, vector<int>> m;
    int least = INT32_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
      m[nums[i]].push_back(i);
      if (m[nums[i]].size() >= 3)
      {
        int t = 0;
        int last = m[nums[i]].size() - 1;
        for (int j = 0; j < 3; j++)
        {
          int i1 = last - j;
          int i2 = j == 2 ? last : (last - (j + 1));
          t += abs(m[nums[i]][i1] - m[nums[i]][i2]);
        }
        least = min(least, t);
      }
    }

    return least == INT32_MAX ? -1 : least;
  }
};

int main()
{
  Solution solution;

  int restul1 = solution.minimumDistance(*new vector<int>{1, 2, 1, 1, 3});
  int restul2 = solution.minimumDistance(*new vector<int>{1, 1, 2, 3, 2, 1, 2});
  int restul3 = solution.minimumDistance(*new vector<int>{1});
}