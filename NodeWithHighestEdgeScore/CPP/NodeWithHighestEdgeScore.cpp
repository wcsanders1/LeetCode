// https://leetcode.com/problems/node-with-highest-edge-score/
#include <vector>

using namespace std;

class Solution
{
public:
  int edgeScore(vector<int> &edges)
  {
    vector<long long> scores = vector<long long>(edges.size(), 0);
    for (int i = 0; i < edges.size(); i++)
    {
      scores[edges[i]] += i;
    }

    long long max = 0;
    int index = 0;

    for (int i = 0; i < scores.size(); i++)
    {
      if (scores[i] > max)
      {
        max = scores[i];
        index = i;
      }
    }

    return index;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.edgeScore(*new vector<int>{1, 0, 0, 0, 0, 7, 7, 5});
  int result2 = solution.edgeScore(*new vector<int>{2, 0, 0, 2});
}