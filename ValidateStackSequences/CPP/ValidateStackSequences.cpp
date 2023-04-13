// https://leetcode.com/problems/validate-stack-sequences/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    int poppedPoint = 0;
    stack<int> s;

    for (int p : pushed)
    {
      s.push(p);
      while (!s.empty() && popped[poppedPoint] == s.top())
      {
        poppedPoint++;
        s.pop();
      }
    }

    return poppedPoint == popped.size();
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.validateStackSequences(*new vector<int>{1, 2, 3, 4, 5}, *new vector<int>{4, 5, 3, 2, 1});
  bool result2 = solution.validateStackSequences(*new vector<int>{1, 2, 3, 4, 5}, *new vector<int>{4, 3, 5, 1, 2});
}