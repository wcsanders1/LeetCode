// https://leetcode.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Sorter
{
public:
  bool operator()(vector<int> v1, vector<int> v2)
  {
    return v1[1] < v2[1];
  }
};

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];
      if (m.count(num) == 0)
      {
        m[num] = 0;
      }
      m[num]++;
    }

    priority_queue<vector<int>, vector<vector<int>>, Sorter> q;
    for (auto &[n, a] : m)
    {
      q.push({n, a});
    }

    vector<int> answer;
    while (k-- > 0)
    {
      answer.push_back(q.top()[0]);
      q.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.topKFrequent(*new vector<int>{1, 1, 1, 2, 2, 3}, 2);
  auto result2 = solution.topKFrequent(*new vector<int>{1}, 1);
  auto result3 = solution.topKFrequent(*new vector<int>{3, 0, 1, 0}, 1);
}