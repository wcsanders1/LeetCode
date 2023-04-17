// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  vector<long long> findPrefixScore(vector<int> &nums)
  {
    vector<long long> answer;
    long long greatest = 0;
    long long cum = 0;
    for (int n : nums)
    {
      greatest = max(greatest, (long long)n);
      long long score = n + greatest + cum;
      answer.push_back(score);
      cum = score;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findPrefixScore(*new vector<int>{2, 3, 7, 5, 10});
  auto result2 = solution.findPrefixScore(*new vector<int>{1, 1, 2, 4, 8, 16});
}