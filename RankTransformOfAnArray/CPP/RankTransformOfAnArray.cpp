// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 0)
    {
      return arr;
    }
    vector<vector<int>> pairs;
    for (int i = 0; i < n; i++)
    {
      pairs.push_back({arr[i], i});
    }

    sort(pairs.begin(), pairs.end());

    int rank = 1;
    int prev = pairs[0][0];
    for (auto &pair : pairs)
    {
      if (pair[0] > prev)
      {
        rank++;
        prev = pair[0];
      }

      arr[pair[1]] = rank;
    }

    return arr;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.arrayRankTransform(*new vector<int>{40, 10, 20, 30});
  auto result2 = solution.arrayRankTransform(*new vector<int>{100, 100, 100});
  auto result3 = solution.arrayRankTransform(*new vector<int>{37, 12, 28, 9, 100, 56, 80, 5, 12});
}