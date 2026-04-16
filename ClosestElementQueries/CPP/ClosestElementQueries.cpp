// https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
  {
    unordered_map<int, vector<int>> indexes;
    for (int i = 0; i < nums.size(); i++)
    {
      indexes[nums[i]].push_back(i);
    }

    vector<int> answer(queries.size(), -1);
    for (int i = 0; i < queries.size(); i++)
    {
      int index = queries[i];
      int num = nums[index];
      if (indexes[num].size() < 2)
      {
        continue;
      }

      int j = getIndex(indexes[num], index);
      int a = j > 0 ? indexes[num][j] - indexes[num][j - 1] : (nums.size() - indexes[num][indexes[num].size() - 1]) + indexes[num][0];
      int b = j < indexes[num].size() - 1 ? indexes[num][j + 1] - indexes[num][j] : (nums.size() - indexes[num][indexes[num].size() - 1]) + indexes[num][0];
      answer[i] = min(a, b);
    }

    return answer;
  }

private:
  int getIndex(vector<int> &indexes, int target)
  {
    int start = 0;
    int end = indexes.size();
    while (start <= end)
    {
      int mid = (end + start) / 2;
      if (indexes[mid] == target)
      {
        return mid;
      }
      if (indexes[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return start;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.solveQueries(*new vector<int>{1, 3, 1, 4, 1, 3, 2}, *new vector<int>{0, 3, 5});
  auto result2 = solution.solveQueries(*new vector<int>{1, 2, 3, 4}, *new vector<int>{0, 1, 2, 3});
}