// https://leetcode.com/problems/find-the-highest-altitude/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int answer = 0;
    int current = 0;
    for (int &g : gain)
    {
      current += g;
      answer = max(answer, current);
    }

    return answer;
  }
};