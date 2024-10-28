// https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestSquareStreak(vector<int> &nums)
  {
    unordered_set<int> s;
    for (int n : nums)
    {
      s.insert(n);
    }

    int answer = -1;
    sort(nums.begin(), nums.end());
    for (int &n : nums)
    {
      long long current = n;
      int count = 0;
      while (s.count(current) > 0)
      {
        s.erase(current);
        current *= current;
        count++;
      }

      if (count > 1)
      {
        answer = max(answer, count);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestSquareStreak(*new vector<int>{4, 3, 6, 16, 8, 2});
  int result2 = solution.longestSquareStreak(*new vector<int>{2, 3, 5, 6, 7});
}