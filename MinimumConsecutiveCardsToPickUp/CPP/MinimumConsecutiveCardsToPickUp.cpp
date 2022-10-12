// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minimumCardPickup(vector<int> &cards)
  {
    int answer = INT32_MAX;

    unordered_map<int, int> m;
    for (int i = 0; i < cards.size(); i++)
    {
      if (m.count(cards[i]) == 0)
      {
        m[cards[i]] = i;
      }
      else
      {
        answer = min(answer, (i - m[cards[i]]) + 1);
        m[cards[i]] = i;
      }
    }

    return answer == INT32_MAX ? -1 : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumCardPickup(*new vector<int>{3, 4, 2, 3, 4, 7});
  int result2 = solution.minimumCardPickup(*new vector<int>{1, 0, 5, 3});
}