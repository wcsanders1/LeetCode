// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  int shipWithinDays(vector<int> &weights, int days)
  {
    int start = 0;
    int end = 0;

    for (int w : weights)
    {
      start = max(start, w);
      end += w;
    }

    int answer = end;
    while (start < end)
    {
      int mid = (end + start) / 2;
      if (isPossible(weights, days, mid))
      {
        answer = mid;
        end = mid;
      }
      else
      {
        start = mid + 1;
      }
    }

    return answer;
  }

private:
  bool isPossible(vector<int> &weights, int days, int maxWeight)
  {
    int totalDays = 0;
    int currentWeight = 0;
    for (int w : weights)
    {
      if (currentWeight + w > maxWeight)
      {
        totalDays++;
        currentWeight = w;
      }
      else
      {
        currentWeight += w;
      }
    }

    totalDays = currentWeight > 0 ? totalDays + 1 : totalDays;

    return totalDays <= days;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.shipWithinDays(*new vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5);       // 15
  int result2 = solution.shipWithinDays(*new vector<int>{3, 2, 2, 4, 1, 4}, 3);                    // 6
  int result3 = solution.shipWithinDays(*new vector<int>{1, 2, 3, 1, 1}, 4);                       // 3
  int result4 = solution.shipWithinDays(*new vector<int>{10, 50, 100, 100, 50, 100, 100, 100}, 5); // 160
}