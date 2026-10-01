// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/?envType=daily-question&envId=2026-09-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> maxDepthAfterSplit(string seq)
  {
    vector<int> answer;
    int cur = 0;
    char p = '-';
    for (char &c : seq)
    {
      if (c == p)
      {
        cur = cur == 0 ? 1 : 0;
      }

      answer.push_back(cur);
      p = c;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxDepthAfterSplit("(()())");
  auto result2 = solution.maxDepthAfterSplit("()(())()");
}