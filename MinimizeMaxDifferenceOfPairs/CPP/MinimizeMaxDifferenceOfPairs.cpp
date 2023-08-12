// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minimizeMax(vector<int> &nums, int p)
  {
    vector<pair<int, int>> pos;
    for (int i = 0; i < nums.size(); i++)
    {
      pos.push_back({nums[i], i});
    }

    sort(pos.begin(), pos.end());

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> diffs;
    for (int i = 0; i < pos.size(); i++)
    {
      for (int j = i + 1; j < pos.size(); j++)
      {
        diffs.push({pos[j].first - pos[i].first, pos[i].second, pos[j].second});
      }
    }

    vector<bool> visited(nums.size(), false);
    int answer = 0;
    while (p > 0 && !diffs.empty())
    {
      auto t = diffs.top();
      diffs.pop();
      if (visited[t[1]] || visited[t[2]])
      {
        continue;
      }

      p--;
      visited[t[1]] = true;
      visited[t[2]] = true;

      answer = max(answer, t[0]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimizeMax(*new vector<int>{10, 1, 2, 7, 1, 3}, 2);            // 1
  int result2 = solution.minimizeMax(*new vector<int>{4, 2, 1, 2}, 1);                   // 0
  int result3 = solution.minimizeMax(*new vector<int>{8, 9, 1, 5, 4, 3, 6, 4, 3, 7}, 4); // 1
  int result4 = solution.minimizeMax(*new vector<int>{3, 4, 2, 3, 2, 1, 2}, 3);          // 1
}