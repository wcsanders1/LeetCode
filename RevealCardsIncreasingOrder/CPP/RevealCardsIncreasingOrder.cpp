// https://leetcode.com/problems/reveal-cards-in-increasing-order/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    vector<int> answer(deck.size(), 0);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int card : deck)
    {
      pq.push(card);
    }

    for (int i = 0; i < deck.size(); i += 2)
    {
      answer[i] = pq.top();
      pq.pop();
    }

    int position = deck.size() % 2 == 0 ? 1 : 3;
    while (!pq.empty())
    {
      if (position >= deck.size())
      {
        position = position - (deck.size() - 1) - (deck.size() % 2 == 0 ? 1 : 0);
      }

      answer[position] = pq.top();
      pq.pop();

      position += 4;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.deckRevealedIncreasing(*new vector<int>{17, 13, 11, 2, 3, 5, 7});
  auto result2 = solution.deckRevealedIncreasing(*new vector<int>{17, 13, 11, 2, 3, 5});
  auto result3 = solution.deckRevealedIncreasing(*new vector<int>{1, 1000});
  auto result4 = solution.deckRevealedIncreasing(*new vector<int>{1, 2, 3, 4});
}