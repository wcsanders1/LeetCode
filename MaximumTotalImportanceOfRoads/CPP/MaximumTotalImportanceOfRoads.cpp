// https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    vector<int> counts(n, 0);
    for (auto &road : roads)
    {
      counts[road[0]]++;
      counts[road[1]]++;
    }

    sort(counts.begin(), counts.end(), greater<>());

    long long answer = 0;
    long long _n = n;
    for (long long c : counts)
    {
      answer += _n-- * c;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.maximumImportance(5, *new vector<vector<int>>{{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}});
  long long result2 = solution.maximumImportance(5, *new vector<vector<int>>{{0, 3}, {2, 4}, {1, 3}});
}