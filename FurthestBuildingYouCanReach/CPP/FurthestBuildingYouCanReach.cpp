// https://leetcode.com/problems/furthest-building-you-can-reach/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    priority_queue<int, vector<int>, greater<int>> distances;
    int sum = 0;
    for (int i = 1; i < heights.size(); i++)
    {
      int height = heights[i] - heights[i - 1];
      if (height <= 0)
      {
        continue;
      }

      distances.push(height);
      if (distances.size() > ladders)
      {
        sum += distances.top();
        distances.pop();
      }

      if (sum > bricks)
      {
        return i - 1;
      }
    }

    return heights.size() - 1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.furthestBuilding(*new vector<int>{4, 2, 7, 6, 9, 14, 12}, 5, 1);
  int result2 = solution.furthestBuilding(*new vector<int>{4, 12, 2, 7, 3, 18, 20, 3, 19}, 10, 2);
  int result3 = solution.furthestBuilding(*new vector<int>{14, 3, 19, 3}, 17, 0);
}