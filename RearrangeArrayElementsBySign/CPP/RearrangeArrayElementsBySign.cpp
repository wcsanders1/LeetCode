// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    queue<int> pos;
    queue<int> neg;
    for (int n : nums)
    {
      if (n > 0)
      {
        pos.push(n);
      }
      else
      {
        neg.push(n);
      }
    }

    vector<int> answer;
    bool needPos = true;
    while (!pos.empty() || !neg.empty())
    {
      if (needPos)
      {
        answer.push_back(pos.front());
        pos.pop();
      }
      else
      {
        answer.push_back(neg.front());
        neg.pop();
      }
      needPos = !needPos;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.rearrangeArray(*new vector<int>{3, 1, -2, -5, 2, -4});
  auto result2 = solution.rearrangeArray(*new vector<int>{-1, 1});
}