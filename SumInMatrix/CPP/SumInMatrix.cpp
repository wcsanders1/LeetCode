// https://leetcode.com/problems/sum-in-a-matrix/description/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int matrixSum(vector<vector<int>> &nums)
  {
    vector<priority_queue<int> *> qs;
    for (auto &row : nums)
    {
      auto q = new priority_queue<int>();
      for (int n : row)
      {
        q->push(n);
      }
      qs.push_back(q);
    }

    int answer = 0;
    for (int i = 0; i < nums[0].size(); i++)
    {
      int t = 0;
      for (auto q : qs)
      {
        t = max(t, q->top());
        q->pop();
      }
      answer += t;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.matrixSum(*new vector<vector<int>>{{7, 2, 1}, {6, 4, 2}, {6, 5, 3}, {3, 2, 1}});
  int result2 = solution.matrixSum(*new vector<vector<int>>{{1}});
}