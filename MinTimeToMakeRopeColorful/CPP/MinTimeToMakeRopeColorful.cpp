// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2023-12-27
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int start = 0;
    int n = colors.size();
    int answer = 0;

    for (int end = 1; end < n; end++)
    {
      if (colors[start] != colors[end])
      {
        answer += getCost(colors, neededTime, start, end);
        start = end;
      }
    }

    answer += getCost(colors, neededTime, start, n);
    return answer;
  }

private:
  int getCost(string &colors, vector<int> &neededTime, int start, int end)
  {
    int m = 0;
    int total = 0;
    for (; start < end; start++)
    {
      m = max(m, neededTime[start]);
      total += neededTime[start];
    }

    total -= m;
    return total;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost("abaac", *new vector<int>{1, 2, 3, 4, 5});
  int result2 = solution.minCost("abc", *new vector<int>{1, 2, 3});
  int result3 = solution.minCost("aabaa", *new vector<int>{1, 2, 3, 4, 1});
}