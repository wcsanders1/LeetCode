// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    stack<vector<int>> stk;
    for (int i = nums1.size() - 1; i >= 0; i--)
    {
      stk.push(vector<int>{i, 0});
    }

    vector<vector<int>> answer;
    while (k-- > 0)
    {
      stack<vector<int>> tempStk;
      while (!stk.empty())
      {
      }

      while (!tempStk.empty())
      {
        if (tempStk.top()[1] < nums2.size())
        {
          stk.push(tempStk.top());
        }

        tempStk.pop();
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  vector<vector<int>> result1 = solution.kSmallestPairs(*new vector<int>{1, 7, 11}, *new vector<int>{2, 4, 6}, 3);
  vector<vector<int>> result2 = solution.kSmallestPairs(*new vector<int>{1, 1, 2}, *new vector<int>{1, 2, 3}, 2);
  vector<vector<int>> result3 = solution.kSmallestPairs(*new vector<int>{1, 2}, *new vector<int>{3}, 3);
}