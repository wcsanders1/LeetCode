// https://leetcode.com/problems/gray-code/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> grayCode(int n)
  {
    n = pow(2, n);
    vector<int> answer(n, 0);
    for (int i = 1; i < n; i++)
    {
      answer[i] = i ^ (i >> 1);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.grayCode(2);
  auto result2 = solution.grayCode(3);
}