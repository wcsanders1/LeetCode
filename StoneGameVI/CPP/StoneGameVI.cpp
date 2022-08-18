// https://leetcode.com/problems/stone-game-vi/
#include <vector>
#include <queue>

using namespace std;

struct Score
{
  int index;
  int value;
  Score(int i, int v)
  {
    index = i;
    value = v;
  }
};

class Comparator
{
public:
  int operator()(const Score &s1, const Score &s2)
  {
    return s1.value < s2.value;
  }
};

class Solution
{
public:
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
  {
    priority_queue<Score, vector<Score>, Comparator> maxHeap;

    for (int i = 0; i < aliceValues.size(); i++)
    {
      int v = aliceValues[i] + bobValues[i];
      Score s = Score(i, v);
      maxHeap.push(s);
    }

    int aliceScore = 0;
    int bobScore = 0;
    bool aliceTurn = true;

    while (!maxHeap.empty())
    {
      Score s = maxHeap.top();
      maxHeap.pop();

      if (aliceTurn)
      {
        aliceTurn = false;
        aliceScore += aliceValues[s.index];
      }
      else
      {
        aliceTurn = true;
        bobScore += bobValues[s.index];
      }
    }

    if (aliceScore > bobScore)
    {
      return 1;
    }

    if (bobScore > aliceScore)
    {
      return -1;
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.stoneGameVI(*new vector<int>{1, 3}, *new vector<int>{2, 1});
  int result2 = solution.stoneGameVI(*new vector<int>{1, 2}, *new vector<int>{3, 1});
  int result3 = solution.stoneGameVI(*new vector<int>{2, 4, 3}, *new vector<int>{1, 6, 7});
  int result4 = solution.stoneGameVI(*new vector<int>{9, 8, 3, 8}, *new vector<int>{10, 6, 9, 5});
}