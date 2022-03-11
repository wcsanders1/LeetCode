#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), greater<>());
    unordered_map<int, vector<int>> graph;
    vector<int> greatestSubset(0);

    for (int i = 0; i < nums.size(); i++)
    {
      if (graph.count(nums[i]) > 0)
      {
        continue;
      }

      graph[nums[i]] = vector<int>(0);

      for (int j = i + 1; j < nums.size(); j++)
      {
        if (graph.count(nums[j]) > 0)
        {
          continue;
        }

        if (nums[i] % nums[j] != 0)
        {
          continue;
        }

        // vector<int> subset = getSubset();
      }
    }
  }

private:
  vector<int> getSubset(unordered_map<int, vector<int>> &dp, vector<int> &nums, int position)
  {
  }
};