// https://leetcode.com/problems/reveal-cards-in-increasing-order/
// NOT MINE: https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/201574/C%2B%2B-with-picture-skip-over-empty-spaces
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    sort(begin(deck), end(deck));
    vector<int> res(deck.size(), 0);
    res[0] = deck[0];
    for (auto i = 1, p = 0; i < deck.size(); ++i)
    {
      for (auto j = 0; j < 2; p %= res.size(), j += (res[p] == 0 ? 1 : 0))
      {
        ++p;
      }

      res[p] = deck[i];
    }
    return res;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.deckRevealedIncreasing(*new vector<int>{17, 13, 11, 2, 3, 5, 7});
  auto result2 = solution.deckRevealedIncreasing(*new vector<int>{17, 13, 11, 2, 3, 5});
  auto result3 = solution.deckRevealedIncreasing(*new vector<int>{1, 1000});
  auto result4 = solution.deckRevealedIncreasing(*new vector<int>{1, 2, 3, 4}); // 1, 3, 2, 4
  auto result5 = solution.deckRevealedIncreasing(*new vector<int>{1});
  auto result6 = solution.deckRevealedIncreasing(*new vector<int>{1, 2, 3});
  auto result7 = solution.deckRevealedIncreasing(*new vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
}