// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int minSwaps(string s)
  {
    vector<char> stk;
    for (char &c : s)
    {
      stk.push_back(c);
      int n = stk.size();
      while (n > 1 && stk[n - 2] == '[' && stk[n - 1] == ']')
      {
        stk.pop_back();
        stk.pop_back();
        n -= 2;
      }
    }

    return ((stk.size() / 2) + 1) / 2;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minSwaps("][][");
  int result2 = solution.minSwaps("]]][[[");
  int result3 = solution.minSwaps("[]");
}