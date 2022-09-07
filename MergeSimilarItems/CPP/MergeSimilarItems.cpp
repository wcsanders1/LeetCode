// https://leetcode.com/problems/merge-similar-items/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
  {
    vector<int> totals = vector<int>(1001, 0);
    int size = max(items1.size(), items2.size());

    for (int i = 0; i < size; i++)
    {
      if (i < items1.size())
      {
        totals[items1[i][0]] += items1[i][1];
      }

      if (i < items2.size())
      {
        totals[items2[i][0]] += items2[i][1];
      }
    }

    vector<vector<int>> answer;
    for (int i = 0; i < totals.size(); i++)
    {
      if (totals[i] == 0)
      {
        continue;
      }

      answer.push_back(vector<int>{i, totals[i]});
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mergeSimilarItems(*new vector<vector<int>>{{1, 1}, {4, 5}, {3, 8}}, *new vector<vector<int>>{{3, 1}, {1, 5}});
  auto result2 = solution.mergeSimilarItems(*new vector<vector<int>>{{1, 1}, {3, 2}, {2, 3}}, *new vector<vector<int>>{{2, 1}, {3, 2}, {1, 3}});
  auto result3 = solution.mergeSimilarItems(*new vector<vector<int>>{{1, 3}, {2, 2}}, *new vector<vector<int>>{{7, 1}, {2, 2}, {1, 4}});
}