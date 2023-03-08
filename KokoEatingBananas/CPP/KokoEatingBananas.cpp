// https://leetcode.com/problems/koko-eating-bananas/
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
  int minEatingSpeed(vector<int> &piles, int h)
  {
    long long start = 1;
    long long end = 10e9;

    while (start < end)
    {
      long long mid = (end + start) / 2;
      long long total = 0;
      for (int p : piles)
      {
        total += ceil((double)p / (double)mid);
      }
      if (total > h)
      {
        start = mid + 1;
      }
      else
      {
        end = mid;
      }
    }

    return start;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minEatingSpeed(*new vector<int>{3, 6, 7, 11}, 8);
  int result2 = solution.minEatingSpeed(*new vector<int>{30, 11, 23, 4, 20}, 5);
  int result3 = solution.minEatingSpeed(*new vector<int>{30, 11, 23, 4, 20}, 6);
  int result4 = solution.minEatingSpeed(*new vector<int>{312884470}, 968709470);
}