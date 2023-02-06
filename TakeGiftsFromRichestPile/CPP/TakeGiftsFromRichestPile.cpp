// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
  long long pickGifts(vector<int> &gifts, int k)
  {
    priority_queue<int> q;

    long long total = 0;
    for (int g : gifts)
    {
      q.push(g);
      total += g;
    }

    for (int i = 0; i < k; i++)
    {
      int g = q.top();
      q.pop();
      auto s = (int)floor(sqrt(g));
      total -= g - s;
      q.push(s);
    }

    return total;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.pickGifts(*new vector<int>{25, 64, 9, 4, 100}, 4);
  auto result2 = solution.pickGifts(*new vector<int>{1, 1, 1, 1}, 4);
}