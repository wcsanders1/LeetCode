// https://leetcode.com/problems/knight-dialer/?envType=daily-question&envId=2023-11-27
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int knightDialer(int n)
  {
    if (n == 1)
    {
      return 10;
    }

    int mod = 1e9 + 7;

    unordered_map<int, vector<int>> m = {
        {0, {4, 6}},
        {1, {6, 8}},
        {2, {7, 9}},
        {3, {4, 8}},
        {4, {0, 3, 9}},
        {6, {0, 1, 7}},
        {7, {2, 6}},
        {8, {1, 3}},
        {9, {2, 4}}};

    unordered_map<int, long long> cur = {
        {0, 1},
        {1, 1},
        {2, 1},
        {3, 1},
        {4, 1},
        {6, 1},
        {7, 1},
        {8, 1},
        {9, 1}};

    while (n-- > 1)
    {
      unordered_map<int, long long> nextCur{
          {0, 0},
          {1, 0},
          {2, 0},
          {3, 0},
          {4, 0},
          {6, 0},
          {7, 0},
          {8, 0},
          {9, 0}};

      for (auto &[k, v] : cur)
      {
        vector<int> nums = m[k];
        for (int n : nums)
        {
          nextCur[n] = (nextCur[n] + cur[k]) % mod;
        }
      }

      cur = nextCur;
    }

    int answer = 0;
    for (auto &[k, v] : cur)
    {
      answer = (answer + v) % mod;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.knightDialer(1);
  int result2 = solution.knightDialer(2);
  int result3 = solution.knightDialer(4); // 104
  int result4 = solution.knightDialer(3131);
}