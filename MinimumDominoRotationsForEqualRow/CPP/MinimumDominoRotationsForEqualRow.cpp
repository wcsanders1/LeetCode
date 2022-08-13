// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#include <vector>
#include <unordered_map>

using namespace std;

struct TopBottom
{
  int top;
  int bottom;
  bool canMatch;
  TopBottom()
  {
    top = 0;
    bottom = 0;
    canMatch = true;
  }
};

class Solution
{
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
  {
    unordered_map<int, TopBottom> matches;
    const int values = 6;

    for (int v = 1; v <= values; v++)
    {
      matches[v] = TopBottom();
    }

    for (int i = 0; i < tops.size(); i++)
    {
      int bottom = bottoms[i];
      int top = tops[i];

      matches[bottom].bottom++;
      matches[top].top++;

      for (int v = 1; v <= values; v++)
      {
        if (v == bottom || v == top)
        {
          continue;
        }

        matches[v].canMatch = false;
      }
    }

    int answer = INT32_MAX;
    for (auto it : matches)
    {
      if (it.second.canMatch)
      {
        int diff = tops.size() - max(it.second.bottom, it.second.top);
        answer = min(answer, diff);
      }
    }

    return answer == INT32_MAX ? -1 : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDominoRotations(*new vector<int>{2, 1, 2, 4, 2, 2}, *new vector<int>{5, 2, 6, 2, 3, 2});
  int result2 = solution.minDominoRotations(*new vector<int>{3, 5, 1, 2, 3}, *new vector<int>{3, 6, 3, 3, 4});
  int result3 = solution.minDominoRotations(*new vector<int>{1, 2, 1, 1, 1, 2, 2, 2}, *new vector<int>{2, 1, 2, 2, 2, 2, 2, 2});
}