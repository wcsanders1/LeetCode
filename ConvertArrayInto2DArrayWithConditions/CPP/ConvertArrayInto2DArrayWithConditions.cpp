// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findMatrix(vector<int> &nums)
  {
    int last = -1;
    stack<vector<int> *> s1;
    stack<vector<int> *> s2;

    sort(nums.begin(), nums.end());
    s1.push(new vector<int>());

    for (int &n : nums)
    {
      if (n == last)
      {
        vector<int> *last = s1.top();
        s1.pop();
        s2.push(last);

        vector<int> *nxt = s1.empty() ? new vector<int>() : s1.top();
        if (!s1.empty())
        {
          s1.pop();
        }
        nxt->push_back(n);
        s1.push(nxt);
      }
      else
      {
        last = n;
        while (!s2.empty())
        {
          s1.push(s2.top());
          s2.pop();
        }
        s1.top()->push_back(n);
      }
    }

    vector<vector<int>> answer;
    while (!s1.empty())
    {
      answer.push_back(*s1.top());
      s1.pop();
    }

    while (!s2.empty())
    {
      answer.push_back(*s2.top());
      s2.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findMatrix(*new vector<int>{1, 3, 4, 1, 2, 3, 1});
  auto result2 = solution.findMatrix(*new vector<int>{1, 2, 3, 4});
}