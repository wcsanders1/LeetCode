// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  int maximizeSum(vector<int> &nums, int k)
  {
    int m = 0;
    for (int n : nums)
    {
      m = max(m, n);
    }

    int answer = 0;
    while (k-- > 0)
    {
      answer += m++;
    }

    return answer;
  }
};

int main()
{
  Solution soluton;

  int result1 = soluton.maximizeSum(*new vector<int>{1, 2, 3, 4, 5}, 3);
  int result2 = soluton.maximizeSum(*new vector<int>{5, 5, 5}, 2);
}