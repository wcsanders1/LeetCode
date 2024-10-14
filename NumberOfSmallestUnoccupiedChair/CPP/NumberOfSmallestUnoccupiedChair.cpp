// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    int targetArrivalTime = times[targetFriend][0];
    sort(times.begin(), times.end());
    int nextNum = 0;
    priority_queue<int, vector<int>, greater<int>> nextAvailableChair;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> nextLeaving;

    for (auto &time : times)
    {
      while (!nextLeaving.empty() && time[0] >= nextLeaving.top()[0])
      {
        nextAvailableChair.push(nextLeaving.top()[1]);
        nextLeaving.pop();
      }

      int chair = -1;
      if (!nextAvailableChair.empty())
      {
        chair = nextAvailableChair.top();
        nextAvailableChair.pop();
      }
      else
      {
        chair = nextNum++;
      }

      if (time[0] == targetArrivalTime)
      {
        return chair;
      }

      nextLeaving.push({time[1], chair});
    }

    return -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.smallestChair(*new vector<vector<int>>{{1, 4}, {2, 3}, {4, 6}}, 1);
  int result2 = solution.smallestChair(*new vector<vector<int>>{{3, 10}, {1, 5}, {2, 6}}, 0);
}